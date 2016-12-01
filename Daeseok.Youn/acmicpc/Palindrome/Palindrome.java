import java.util.Scanner;

public class Palindrome {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String str = input.next();
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
      if (str.charAt(start) != str.charAt(end)) {
          System.out.println("0");
          break;
      }

      start++;
      end--;
    }

    if (start >= end) {
      System.out.println("1");
    }
  }
}
