import java.util.Scanner;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class prefixArray {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    Map<String, Integer> map = new HashMap<String, Integer>();

    String str = input.next();
    int index = 0;

    while (index < str.length()) {
      String subStr = str.substring(index++);

      if (map.containsKey(subStr))
        map.put(subStr, map.get(subStr) + 1);
      else
        map.put(subStr, 1);
    }

    Map<String, Integer> sortedMap = new TreeMap<String, Integer>(map);
    for (Map.Entry<String, Integer> entry: sortedMap.entrySet()) {
      System.out.println(entry.getKey());
    }
  }
}
