import java.util.Scanner;
import java.util.Stack;

public class goodWord {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    Stack<Character> stack = new Stack<Character>();

    int testCase = input.nextInt();
    int goodWordCnt = 0;

    while (testCase-- > 0) {
      String str = input.next();

      for (int i = 0; i < str.length(); i++) {
        if (stack.isEmpty()) {
          stack.push(str.charAt(i));
          continue;
        }

        char ch = str.charAt(i);
        if (stack.peek() == ch)
          stack.pop();
        else
          stack.push(ch);
      }

      if (stack.isEmpty())
        goodWordCnt++;
      else {
        stack.clear();
      }
    }

    System.out.println(goodWordCnt);
  }
}
