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

    index = 0;
    while (index++ < numOfWars) {
      testStr.add(input.next());
    }

    if (numOfWars > 2) {
      for (int i = 0; i < testStr.size(); i++) {
        String first = testStr.get(i);
        for (int j = i + 1; j < testStr.size(); j++) {
          String second = testStr.get(j);
          if (correctOrder.containsKey(first) &&
              correctOrder.containsKey(second) &&
              (correctOrder.get(testStr.get(i)) < correctOrder.get(testStr.get(j))))
            score++;
        }
      }
    } else {
      int k = 0;
      while (k < testStr.size()) {
        if (correctOrder.containsKey(testStr.get(k)) &&
            correctOrder.get(testStr.get(k)) == k)
          score++;
        k++;
      }
    }

    int total = ((int)(numOfWars * (numOfWars - 1)/2));
    if (total == 0)
      total = 1;

    System.out.println(score + "/" + total);
  }
}
