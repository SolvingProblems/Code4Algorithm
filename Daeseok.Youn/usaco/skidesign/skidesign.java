/*
ID: daeseok1
LANG: JAVA
TASK: skidesign
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.Arrays;

public class skidesign {
   public static void main (String [] args) throws IOException {
      Scanner in = new Scanner(new File("skidesign.in"));        // file input
      Formatter out = new Formatter(new File("skidesign.out"));  // file output

      int n = Integer.parseInt(in.nextLine());

      int [] hills = new int [n];
      int c = 0;
      long max = Integer.MAX_VALUE;

      while (c < n) {
        int height = Integer.parseInt(in.nextLine());
        hills[c++] = height;
      }

      Arrays.sort(hills);

      for (int i = 1; i <= 83; i++) {
        long temp = 0;
        for (int j = 0; j < n; j++) {
          if (hills[j] < i)
            temp += (i - hills[j]) * (i - hills[j]);
          else if (hills[j] > i + 17)
            temp += (hills[j] - i - 17) * (hills[j] - i - 17);
        }

        max = Math.min(max, temp);
      }


      out.format("%d\n", max);  // format() has the same syntax as printf()

      out.close();    // flush the output and close the output file
      System.exit(0); // likely needed in USACO
   }
}
