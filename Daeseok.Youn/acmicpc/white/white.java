import java.util.Scanner;

public class white {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int flag = 0;
    int count = 0;
    int lineCount = 8;

    while (lineCount-- > 0) {
      String line = input.nextLine();

      for (int i = 0; i < line.length(); i++) {
        if (i % 2 == flag && line.charAt(i) == 'F') {
          count++;
        }
      }

      flag = flag == 0 ? 1 : 0;
    }

    System.out.println(count);
  }
}
