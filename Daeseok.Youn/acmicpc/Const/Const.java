import java.util.Scanner;

public class Const
{
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    String first = input.next();
    String second = input.next();
    int firNum = 0, secNum = 0;

    firNum = reverseStrToInt(first);
    secNum = reverseStrToInt(second);

    if (firNum > secNum) {
      System.out.println(firNum);
    } else {
      System.out.println(secNum);
    }
  }

  public static int reverseStrToInt(String num) {
    int number = 0;
    int i = 0, index = 1;

    for (i = 0; i < num.length(); i++) {
      number += ((num.charAt(i) - '0') * index);

      index *= 10;
    }

    return number;
  }
}
