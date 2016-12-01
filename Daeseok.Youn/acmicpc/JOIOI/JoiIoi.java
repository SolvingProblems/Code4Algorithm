import java.util.Scanner;

public class JoiIoi {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String str = input.next();
    int joiCount = 0;
    int ioiCount = 0;
    int index = 0;

    while (index <= str.length() - 3) {
      String sub = str.substring(index, index + 3);

      if (sub.equals("JOI"))
        joiCount++;
      else if (sub.equals("IOI"))
        ioiCount++;

      index++;
    }

    System.out.println(joiCount);
    System.out.println(ioiCount);
  }
}
