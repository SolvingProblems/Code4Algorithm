import java.util.Scanner;

public class Main {

  public static boolean hasFeel = false;

  public static int checkHappyWord(String str) {
    if (str.length() <= 0) return 0;

    if (str.length() > 2 &&
        str.substring(0, 3).equals(":-)")) {
      hasFeel = true;
      return 1 + checkHappyWord(str.substring(3));
    } else if (str.length() > 2 &&
               str.substring(0, 3).equals(":-(")) {
      hasFeel = true;
      return (-1) + checkHappyWord(str.substring(3));
    }

    return checkHappyWord(str.substring(1));
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String str = input.nextLine();
    int feels = 0;

    feels = checkHappyWord(str);

    if (feels > 0) {
      System.out.println("happy");
    } else if (feels < 0) {
      System.out.println("sad");
    } else if (hasFeel) {
      System.out.println("unsure");
    } else {
      System.out.println("none");
    }
  }
}
