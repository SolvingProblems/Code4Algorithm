import java.util.Scanner;

public class Cipher {
  public static void main(String [] args)
  {
    Scanner input = new Scanner(System.in);

    String plainText = input.nextLine();
    String encryptKey = input.next();

    int index = 0;

    while (index < plainText.length()) {
      char ch = plainText.charAt(index);

      if (ch != ' ') {
        ch = (char)(ch - 'a');
        ch = (char)((25 + (ch - (encryptKey.charAt(index % encryptKey.length()) - 'a'))) % 26);
        ch = (char)(ch + 'a');
      }
      System.out.print(ch);
      index++;
    }
    System.out.println();
  }
}
