import java.util.Scanner;
import java.io.*;

public class maxAlpha {
  public static void main(String [] args) {
    //Scanner input = new Scanner(System.in);
    int [] alpha = new int[26];
    int maxCnt = 0;
    int maxIdx = 0;
    String str = "";
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);

    try {
      while ((str = br.readLine()) != null && str.length() != 0) {
        for (int i = 0; i < str.length(); i++) {
          if (str.charAt(i) == ' ' || str.charAt(i) == '\r' || str.charAt(i) == '\n')
            continue;

          int index = (int)(str.charAt(i) - 'a');
          int cnt = ++alpha[index];

          if (cnt > maxCnt) {
            maxCnt = cnt;
            maxIdx = index;
          }
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
    }

    System.out.println((char)(maxIdx + 'a'));
  }
}
