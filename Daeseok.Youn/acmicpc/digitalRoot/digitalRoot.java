import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class digitalRoot {

  public static String calDigitalRoot(String num) {
    if (num.length() == 1) return num;

    int calNum = 0;

    for (int i = 0; i < num.length(); i++) {
      calNum += (num.charAt(i) - '0');
    }

    if (calNum / 10 > 0)
      return calDigitalRoot(Integer.toString(calNum));

    return Integer.toString(calNum);
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String num;
    List<String> res = new ArrayList<String>();

    while (true) {
      num = input.nextLine();

      if (num.equals("0"))
        break;

      res.add(calDigitalRoot(num));
    }

    for (int i = 0; i < res.size(); i++)
      System.out.println(res.get(i));
  }
}
