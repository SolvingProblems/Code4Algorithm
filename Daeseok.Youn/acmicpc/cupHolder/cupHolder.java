import java.util.Scanner;

public class cupHolder {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int length = input.nextInt();
    int count = 0;
    input.nextLine();
    String seats = input.nextLine();

    for (int i = 0; i < seats.length(); i++) {
      if (seats.charAt(i) == 'L') {
        count++;
      }
    }

    int res = (seats.length() - count) + (count / 2) + 1;

    if (count == 0)
      res -= 1;

    System.out.println(res);
  }
}
