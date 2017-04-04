/*
ID: daeseok1
LANG: JAVA
TASK: wormhole
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

public class wormhole {

  public static final int MAX_N = 12;

  public static int [] next = new int [MAX_N + 1];
  public static int [] pairs = new int [MAX_N + 1];

  public static boolean is_cycle(int n) {
    for (int s = 1; s <= n; s++) {
      int pos = s;

      for (int c = 0; c < n; c++) {
        pos = next[pairs[pos]];
      }

      if (pos != 0) {
        return true;
      }
    }
    return false;
  }

  public static int makePairs(int n) {
    int i, total = 0;

    for (i = 1; i <= n; i++)
      if (pairs[i] == 0) break;

    if (i > n) {
      if (is_cycle(n)) return 1;

      return 0;
    }

    for (int j = i + 1; j <= n; j++) {
      if (pairs[j] == 0) {
        pairs[i] = j;
        pairs[j] = i;
        total += makePairs(n);
        pairs[i] = pairs[j] = 0;
      }
    }

    return total;
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("wormhole.in"));        // file input
    Formatter out = new Formatter(new File("wormhole.out"));  // file output

    int n = Integer.parseInt(in.nextLine());
    int [] x = new int [n + 1];
    int [] y = new int [n + 1];

    int inCnt = 1;
    while (inCnt <= n) {
      x[inCnt] = Integer.parseInt(in.next());
      y[inCnt] = Integer.parseInt(in.next());

      inCnt++;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (x[j] > x[i] && y[i] == y[j]) {
          if (next[i] == 0 ||
              x[j] - x[i] < x[next[i]] - x[i]) {
//            System.out.println("next[" + i + "] : " + j);
            next[i] = j;
          }
        }
      }
    }

    out.format("%d\n", makePairs(n));  // format() has the same syntax as printf()

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
