import java.util.Scanner;

public class Dial {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String alpha = input.next();
    int [] numbers = new int[alpha.length()];
    int elapsedTime = 0;

    for (int i = 0; i < alpha.length(); i++) {
      int index = alpha.charAt(i) - 'A';

      if (index > 17)
        index--;

      numbers[i] = (index / 3) + 2;
      if (numbers[i] > 9)
        numbers[i] = 9;
    }

    for (int i = 0; i < alpha.length(); i++) {
      elapsedTime += (numbers[i] + 1);
    }

    System.out.println(elapsedTime);
  }
}
