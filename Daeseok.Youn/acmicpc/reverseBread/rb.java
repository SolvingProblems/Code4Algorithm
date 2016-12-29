import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class rb {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int n = input.nextInt();
    int m = input.nextInt();

    List<String> res = new ArrayList<String>();
    input.nextLine();

    while (n-- > 0) {
      String line = input.nextLine();

      if (line.length() > 0) {
        StringBuilder sb = new StringBuilder(line);
        res.add(sb.reverse().toString());
      }
    }

    for (int i = 0; i < res.size(); i++)
      System.out.println(res.get(i));
  }
}
