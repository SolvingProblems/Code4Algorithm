import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class teach {
  public static int k;

  public static int readable(List<String> words, boolean [] alpha)
  {
    int count = 0;

    for (int i = 0; i < words.size(); i++) {
      String str = words.get(i);
      int j = 0;
      for (j = 0; j < str.length(); j++) {
        if (!alpha[str.charAt(j) - 'a'])
          break;
      }

      if (j == str.length())
        count++;
    }

    return count;
  }

  public static int countReadable(List<String> words, boolean [] alpha, char [] alpha2,
                                  int alpha2size, int idx)
  {
    int max = 0;
    int chCnt = 0;

    for (int j = 0; j < 26; j++) {
      if (alpha[j])
        chCnt++;
    }

    if (chCnt == k)
      return readable(words, alpha);

    for (int i = idx; i < alpha2size; i++) {
      alpha[alpha2[i] - 'a'] = true;
      max = Math.max(max, countReadable(words, alpha, alpha2, alpha2size, idx + 1));
      alpha[alpha2[i] - 'a'] = false;
    }

    return max;
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    // a, c, i, n, t
    char [] southPoleChs = {'a', 'c', 'i', 'n', 't'};
    boolean [] alpha = new boolean[26];
    boolean [] temp = new boolean[26];
    char [] newAlpha = new char[26];
    List<String> words = new ArrayList<String>();

    for (int i = 0; i < 5; i++) {
      int ch = (int)(southPoleChs[i] - 'a');
      alpha[ch] = true;
      temp[ch] = true;
    }

    int n = input.nextInt();
    k = input.nextInt();
    input.nextLine();

    int index = 0;

    while (n-- > 0) {
      String str = input.nextLine();

      String trimed = str.substring(4).substring(0, str.length() - 8);
      words.add(trimed);

      for (int i = 0; i < trimed.length(); i++) {
        char ch = trimed.charAt(i);

        if (!temp[ch - 'a']) {
          newAlpha[index++] = ch;
          temp[ch - 'a'] = true;
        }
      }
    }

    System.out.println(countReadable(words, alpha, newAlpha, index, 0));
  }
}
