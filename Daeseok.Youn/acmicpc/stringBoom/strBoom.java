/*
 * String explosion
 * The chain reaction takes place in the following way:
 * 1. if a string contains explosions, they all explode and
 *    a new string is formed by concatenating the pieces
 *    without the exploding parts
 * 2. this concatenation could possibly create new explosions
 * 3. the chain reaction repeats while there are explosions
 *    in the string
 * Input:
 * The first line of input contains string (1 ≤ |Mirko's string| ≤ 1 000 000).
 * The second line of input contains the explosion string, (1 ≤ |explosion| ≤ 36).
 * string and the explosion string consist of uppercase and
 * lowercase letters of the English alphabet and digits 0, 1, … 9.
 * Output:
 * The first and only line of output must contain the final string remaining
 * after all the reactions as stated in the task.
 *
 * ex)
 * INPUT:
 * mirkovC4nizCC44
 * C4
 * OUTPUT:
 * mirkovniz
 */
import java.util.Scanner;
//import java.util.regex.Pattern;

import java.util.Stack;

public class strBoom {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String str = input.next();
    String boom = input.next();

    /*
     * Refer from http://seongilman.tistory.com/394
     */
    Stack<Character> stack = new Stack<Character>();

    for (int i = str.length() - 1; i >= 0; i--) {
      stack.push(str.charAt(i));

      if (stack.size() >= boom.length() &&
          stack.peek() == boom.charAt(0)) {
        int j;

        for (j = 1; j < boom.length(); j++) {
          if (stack.get(stack.size() - j - 1) !=
              boom.charAt(j))
            break;
        }

        if (j == boom.length()) {
          for (int k = 0; k < boom.length(); k++)
            stack.pop();
        }
      }
    }

    if (stack.isEmpty()) {
      System.out.println("FRULA");
    } else {
      while (!stack.isEmpty())
        System.out.print(stack.pop());
      System.out.println();
    }
    /*
     * Timed out solution.
     *
    int index = 0;

    while (index != -1) {
      str = Pattern.compile(boom).matcher(str).replaceAll("");

      index = str.indexOf(boom);
    }

    if (str.equals(""))
      System.out.println("FRULA");
    else
      System.out.println(str);
    */
  }
}
