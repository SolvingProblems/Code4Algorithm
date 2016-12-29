import java.util.Scanner;

public class Blind {
  public static final int WINSIZE = 4;

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int m = input.nextInt();
    int n = input.nextInt();
    int floor = 0;
    int pass = 0;
    boolean [][] blindMap = new boolean[m * n][WINSIZE];
    int [] bTypes = new int [5];
    int ln = 0;

    input.nextLine();

    while (pass <= m) {
      String line = input.nextLine();
      int index = 1;

      if (line.charAt(index) == '#') {
        pass++;
        continue;
      }

      for (int i = floor; i < n + floor; i++) {
        if ((index < (n * WINSIZE + (n + 1))) &&
            line.substring(index).charAt(0) == '*') {
          blindMap[i][ln] = true;
        }

        index += 5;
      }

      if (ln + 1 == WINSIZE)
        floor += n;

      ln = (ln + 1) % WINSIZE;
    }

    for (int i = 0; i < m * n; i++) {
      int status = 0;
      for (int j = 0; j < WINSIZE; j++) {
        if (blindMap[i][j])
          status++;
      }

      bTypes[status]++;
    }

    // print bit map
    /* Debug
    for (int i = 0; i < (m * n); i++) {
      System.out.print("i : " + i + " ");
      for (int j = 0; j < WINSIZE; j++) {
        char ch = blindMap[i][j] ? '1' : '0';
        System.out.print(ch + " ");
      }
      System.out.println();
    }
    */

    for (int i = 0; i < 5; i++) {
      System.out.print(bTypes[i] + " ");
    }
    System.out.println();
  }
}
