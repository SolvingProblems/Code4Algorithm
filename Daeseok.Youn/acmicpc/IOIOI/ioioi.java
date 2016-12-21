import java.util.Scanner;

public class ioioi {
  public String createPattern(int n) {
    boolean flag = true;
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < (2 * n + 1); i++) {
      if (flag)
        sb.append('I');
      else
        sb.append('O');

      flag = !flag;
    }

    return sb.toString();
  }

  public int checkPattern(String origin, String pat) {
    if (origin.length() <= 0) return 0;

    if (origin.length() >= pat.length() &&
        origin.substring(0, pat.length()).equals(pat)) {
      return 1 + checkPattern(origin.substring(1), pat);
    }

    return checkPattern(origin.substring(1), pat);
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    ioioi ioi = new ioioi();
    String pnStr;

    int pn = input.nextInt();
    int strLength = input.nextInt();
    String str = input.next();

    int result = 0;

    pnStr = ioi.createPattern(pn);
    result = ioi.checkPattern(str, pnStr);

    System.out.println(result);
  }
}
