import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class ljesnjak {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    String [] croStr = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    Map<String, Boolean> Croatia = new HashMap<String, Boolean>();

    String str = input.next();
    int count = 0;

    for (int i = 0; i < croStr.length; i++)
      Croatia.put(croStr[i], true);

    while (str.length() > 0) {
      int matchCnt = 1;

      if (str.length() > 1 &&
          Croatia.containsKey(str.substring(0, 2))) {
        matchCnt = 2;
      } else if (str.length() > 2 &&
          Croatia.containsKey(str.substring(0, 3))) {
        matchCnt = 3;
      }

      count++;
      str = str.substring(matchCnt);
    }

    System.out.println(count);
  }
}
