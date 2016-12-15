import java.util.Scanner;

public class PalinDivide {

  private boolean [][] dp;
  private int [] result;
  private final int MAXLEN = 2501;
  private String inputStr;

  public PalinDivide() {
    dp = new boolean[MAXLEN][MAXLEN];

    for (int i = 0; i < MAXLEN; i++) {
      for (int j = 0; j < MAXLEN; j++) {
        if (i == j) dp[i][j] = true;
        else dp[i][j] = false;
      }
    }

    result = new int[MAXLEN];
    for (int j = 0; j < MAXLEN; j++)
      result[j] = -1;
  }

  public void checkPalin(String instr) {
    char [] str = instr.toCharArray();
    for (int i = 0; i < str.length - 1; i++) {
      if (str[i] == str[i + 1]) dp[i][i + 1] = true;
    }

    for (int len = 3; len <= str.length; len++) {
      for (int j = 0; j < (str.length - len + 1); j++) {
        int n = j + len - 1;
        if (str[j] == str[n] && dp[j + 1][n - 1]) {
          dp[j][n] = true;
        }
      }
    }
  }

  public int getDividenNum(int pos, int len) {
    if (pos > len) return 0;

    if (result[pos] != -1) return result[pos];

    result[pos] = Integer.MAX_VALUE;

    for (int i = pos; i <= len; i++) {
      //System.out.println("pos : " + pos + " i : " + i);
      if (dp[pos][i]) {
        result[pos] = Math.min(result[pos], 1 + getDividenNum(i + 1, len));
      }
    }

    return result[pos];
  }

  public void printDp(int len) {
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        if (dp[i][j])
          System.out.print("1");
        else
          System.out.print("0");
        System.out.print(" ");
      }
      System.out.println();
    }

    for (int j = 0; j < len; j++)
      System.out.print(result[j] + " ");
    System.out.println();
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    PalinDivide pd = new PalinDivide();

    String str = input.next();
    pd.checkPalin(str);
    System.out.println(pd.getDividenNum(0, str.length() - 1));
    pd.printDp(str.length());
  }
}
