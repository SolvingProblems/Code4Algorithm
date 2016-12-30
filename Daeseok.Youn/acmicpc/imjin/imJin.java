import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class imJin {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    Map<String, Integer> correctOrder = new HashMap<String, Integer>();
    List<String> testStr = new ArrayList<String>();

    int numOfWars = input.nextInt();
    int score = 0;
    input.nextLine();

    int index = 0;
    while (index < numOfWars) {
      correctOrder.put(input.next(), index++);
    }

    /*
     * Debug print
    Iterator<String> iter = correctOrder.keySet().iterator();
    while (iter.hasNext()) {
      String key = iter.next();
      System.out.print(key + " " + correctOrder.get(key));
    }
    System.out.println();
    */

    index = 0;
    while (index++ < numOfWars) {
      testStr.add(input.next());
    }

    for (int i = 0; i < testStr.size(); i++) {
      for (int j = i + 1; j < testStr.size(); j++) {
        if (correctOrder.get(testStr.get(i)) < correctOrder.get(testStr.get(j)))
          score++;
      }
    }
    System.out.println(score + "/" + ((int)(numOfWars * (numOfWars/2))));
    /*
     * Debug print
    for (int i = 0; i < testStr.size(); i++) {
      System.out.print(testStr.get(i) + " ");
    }
    System.out.println();
    */
  }
}
