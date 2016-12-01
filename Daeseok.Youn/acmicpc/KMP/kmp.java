import java.util.Scanner;

public class kmp
{
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    String str = input.next();
    int index = 0;

    System.out.print(str.charAt(index));

    while (index >= 0) {
      index = str.indexOf('-', index + 1);

      if (index > 0)
        System.out.print(str.charAt(index + 1));
    }

    System.out.print('\n');
  }
}
