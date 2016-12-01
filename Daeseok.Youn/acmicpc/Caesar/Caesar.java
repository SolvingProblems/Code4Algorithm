import java.util.Scanner;

public class Caesar {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    String encrpted = input.next();

    for (int i = 0; i < encrpted.length(); i++) {
      int ch = (encrpted.charAt(i) - 'A' + 23) % 26;
      System.out.print((char)(ch + 'A'));
    }
    System.out.print('\n');
  }
}
