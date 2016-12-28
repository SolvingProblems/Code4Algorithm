import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class teach {
  public static int k;

  public static int countReadable(List<Integer> words, int alpha, char [] alpha2,
                                  int alpha2size, int idx)
  {
    int max = 0;
    int chCnt = 0;

    for (int j = 0; j < 26; j++) {
      if ((alpha & (1 << j)) != 0)
        chCnt++;
    }

    if (chCnt == k) {
      chCnt = 0;
      for (int i = 0; i < words.size(); i++) {
        int val = words.get(i);
        if ((val & alpha) == val)
          chCnt++;
      }

      return chCnt;
    }

    for (int i = idx; i < alpha2size; i++) {
      alpha |= (1 << (alpha2[i] - 'a'));
      max = Math.max(max, countReadable(words, alpha, alpha2, alpha2size, idx + 1));
      alpha &= ~(1 << alpha2[i] - 'a');
    }

    return max;
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    // a, c, i, n, t
    char [] southPoleChs = {'a', 'c', 'i', 'n', 't'};
    int alpha = 0;
    int temp = 0;
    char [] newAlpha = new char[26];
    List<Integer> words = new ArrayList<Integer>();

    for (int i = 0; i < 5; i++) {
      int ch = (int)(southPoleChs[i] - 'a');
      alpha |= (1 << ch);
      temp |= (1 << ch);
    }

    int n = input.nextInt();
    k = input.nextInt();
    input.nextLine();

    int index = 0;

    while (n-- > 0) {
      String str = input.nextLine();

      String trimed = str.substring(4).substring(0, str.length() - 8);
      int word = 0;

      for (int i = 0; i < trimed.length(); i++) {
        char ch = trimed.charAt(i);

        if ((temp & (1 << (ch - 'a'))) == 0) {
          newAlpha[index++] = ch;
          temp |= (1 << (ch - 'a'));
        }

        word |= (1 << (ch - 'a'));
      }

      words.add(word);
    }

    System.out.println(countReadable(words, alpha, newAlpha, index, 0));
  }
}
