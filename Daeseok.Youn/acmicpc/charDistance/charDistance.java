import java.util.Scanner;

public class charDistance {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int testCase = input.nextInt();

    while (testCase-- > 0) {
      String strFirst = input.next();
      String strNext = input.next();

      System.out.print("Distances: ");
      for (int i = 0; i < strFirst.length(); i++) {
        char a = strFirst.charAt(i);
        char b = strNext.charAt(i);

        int c = a - b;

        if (c <= 0)
          c *= -1;
        else
          c = (26 - c);

        System.out.print(c + " ");
      }
      System.out.print('\n');
    }
  }
}
