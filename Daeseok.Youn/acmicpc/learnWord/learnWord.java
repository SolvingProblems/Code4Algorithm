import java.util.Scanner;

public class learnWord {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int [] charCnt = new int[26];
    int max = 0, maxCnt = 0;
    int i = 0;
    int idx = 0;

    String str = input.next().toLowerCase();

    for (i = 0; i < str.length(); i++) {
      charCnt[str.charAt(i) - 'a']++;
    }

    for (i = 0; i < 26; i++) {
      int cnt = charCnt[i];

      if (cnt != 0 && cnt > max) {
        max = cnt;
        idx = i;
      }
    }

    for (i = 0; i < 26; i++) {
      if (max == charCnt[i]) {
        maxCnt++;
      }
    }

    if (maxCnt > 1) {
      System.out.println(Character.toUpperCase('?'));
    } else {
      System.out.println(Character.toUpperCase((char)(idx + 'a')));
    }
  }
}
