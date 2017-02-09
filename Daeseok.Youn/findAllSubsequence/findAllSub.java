import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

public class findAllSub {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    Map<String, Integer> map = new HashMap<String, Integer>();

    int testCase = Integer.parseInt(input.nextLine());

    int [] resultArr = new int[testCase];
    int index = 0;

    while (testCase-- > 0) {
      int result = 0;
      int count = Integer.parseInt(input.nextLine());

      String str = input.nextLine();

      if (count == 1) {
        resultArr[index++] = str.length();
        continue;
      }

      for (int i = 0; i < str.length(); i++) {
        for (int j = 1; j <= str.length() - i; j++) {
          String sub = str.substring(i, i + j);
          if (!map.containsKey(sub))
            map.put(sub, 1);
          else
            map.put(sub, map.get(sub) + 1);
        }
      }

      Iterator<String> iter = map.keySet().iterator();

      while (iter.hasNext()) {
        String key = iter.next();
        if (map.get(key) == count && result < key.length()) {
          result = key.length();
        }
      }

      resultArr[index++] = result;
      map.clear();
    }

    for (int i = 0; i < resultArr.length; i++)
      System.out.println(resultArr[i]);
  }
}
