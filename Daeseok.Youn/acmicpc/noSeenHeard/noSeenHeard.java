import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class noSeenHeard {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    int count = 0;
    Map<String, Boolean> person = new HashMap<String, Boolean>();
    List<String> res = new ArrayList<String>();

    int noSeen = input.nextInt();
    int noHeard = input.nextInt();

    while (noSeen-- > 0) {
      person.put(input.next(), true);
    }

    while (noHeard-- > 0) {
      String name = input.next();
      if (person.containsKey(name)) {
        res.add(name);
        count++;
      }
    }

    System.out.println(res.size());
    Collections.sort(res);

    for (int i = 0; i < res.size(); i++) {
      System.out.println(res.get(i));
    }
  }
}
