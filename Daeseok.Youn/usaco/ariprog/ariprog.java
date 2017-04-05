/*
ID: daeseok1
LANG: JAVA
TASK: ariprog
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.TreeSet;
import java.util.Iterator;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;


class Pair implements Comparator<Pair> {
  private int start;
  private int diff;

  Pair() {
  }
  Pair (int s, int d) {
    this.start = s;
    this.diff = d;
  }

  public int getStart() {
    return this.start;
  }

  public int getDiff() {
    return this.diff;
  }

  @Override
  public int compare(Pair a, Pair b) {
    if (a.diff != b.diff) {
      return a.diff - b.diff;
    }

    return a.start - b.start;
  }
}

public class ariprog {
   public static void main (String [] args) throws IOException {
      Scanner in = new Scanner(new File("ariprog.in"));        // file input
      Formatter out = new Formatter(new File("ariprog.out"));  // file output

      int N = Integer.parseInt(in.nextLine());
      int M = Integer.parseInt(in.nextLine());
      int p = 0, q = 0;
      int max = 0;

      boolean [] bisquares = new boolean[125002];
      List<Pair> pairs = new ArrayList<Pair>();

      for (p = 0; p <= M; p++) {
        for (q = 0; q <= M; q++) {
          int temp = (p * p) + (q * q);

          if (max < temp)
            max = temp;

          bisquares[temp] = true;
        }
      }

      for (int d = 1; d <= (M * M * 2)/(N-1); d++) {
        for (int a = 0; a <= (M * M); a++) {
          int c;
          for (c = 0; c < N; c++) {
            if (!bisquares[a + c * d])
              break;
          }

          if (c >= N)
            pairs.add(new Pair(a, d));
        }
      }

      Collections.sort(pairs, new Pair());

      if (pairs.size() != 0) {
        for (int i = 0; i < pairs.size(); i++) {
          out.format("%d %d\n", pairs.get(i).getStart(), pairs.get(i).getDiff());
        }
      } else {
        out.format("NONE\n");
      }

      out.close();    // flush the output and close the output file
      System.exit(0); // likely needed in USACO
   }
}
