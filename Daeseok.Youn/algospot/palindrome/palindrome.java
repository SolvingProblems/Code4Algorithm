/*
 * solving problem: Makes string as palindrome
 * find minimum length value to make a string
 * as palindrome.
 * input example
 * 1
 * there
 * ouput
 * 7
 */
import java.util.Scanner;

public class palindrome
{
    public static void main(String[] args) {
      Scanner inputs = new Scanner(System.in);
      int testCase = 0;

      testCase = inputs.nextInt();

      while (testCase-- > 0) {
        String str = inputs.next();
        int lenPalin = 0;

        lenPalin = makesPalin(str);

        System.out.println(lenPalin);
      }
    }

    private static int makesPalin(String str) {
      int start = 0;
      int startRev = 0;
      int sameCount = 0;

      String rev = new StringBuffer(str).reverse().toString();

      while (start < str.length()) {
        if (str.charAt(start) != rev.charAt(startRev)) {
          startRev = 0;
        } else {
          startRev++;
        }

        start++;
      }
      return str.length() + start - startRev;
    }
}
