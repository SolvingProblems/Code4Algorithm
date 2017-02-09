import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

public class habit {
  static Map<String, Integer> map = new HashMap<String, Integer>();

  public static void maxHabitCnt(String speach, String subStr, int k, int start) {
    System.out.println("subStr : " + subStr);
    if (subStr.length() > 0 && !map.containsKey(subStr)) {
      int index = 0;
      int count = 0;
      while (index < speach.length() &&
            (index = speach.indexOf(subStr, index)) != -1) {
        count++;
        index += subStr.length();
      }

      map.put(subStr, count);
    } else {
      return;
    }

    int len = start + 1;

    for (int i = start; i < speach.length(); i++) {
      if (i + len < speach.length()) {
        maxHabitCnt(speach, speach.substring(i, i + len), k, i + 1);
      }
    }
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int testCase = input.nextInt();
    input.nextLine();

    while (testCase-- > 0) {
      int k = input.nextInt();
      input.nextLine();
      String speach = input.nextLine();

      maxHabitCnt(speach, speach, k, 0);

      Iterator<String> iter = map.keySet().iterator();
      while (iter.hasNext()) {
        String key = iter.next();
        System.out.println(key + " : " + map.get(key));
      }
    }
  }
}
