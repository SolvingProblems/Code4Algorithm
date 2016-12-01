import java.util.Scanner;
import java.util.HashMap;

public class MinPass {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    HashMap<String, Boolean> map = new HashMap<String, Boolean>();

    int testCase = input.nextInt();

    while (testCase-- > 0) {
      String str = input.next();
      String rev = (new StringBuffer(str)).reverse().toString();

      if (map.containsKey(rev) || str.equals(rev)) {
        System.out.print(rev.length() + " ");
        System.out.println(rev.charAt(rev.length() / 2));
        break;
      } else {
        map.put(str, new Boolean(true));
      }
    }
  }
}
