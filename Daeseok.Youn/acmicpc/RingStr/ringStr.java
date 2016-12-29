import java.util.Scanner;

public class ringStr {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String findStr = input.nextLine();
    int n = input.nextInt();
    int result = 0;

    input.nextLine();

    while (n-- > 0) {
      String ringStr = input.nextLine();
      StringBuilder sb = new StringBuilder(ringStr);

      sb.append(ringStr);

      if (sb.indexOf(findStr) >= 0)
        result++;
    }

    System.out.println(result);
  }
}
