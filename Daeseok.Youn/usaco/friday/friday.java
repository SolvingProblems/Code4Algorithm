/*
ID: yourID
LANG: JAVA
TASK: friday
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

public class friday {  // saved as test.java
  public static final int startYear = 1900;

  public static boolean checkLeepYear(int y) {
    return ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0));
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("friday.in"));        // file input
    Formatter out = new Formatter(new File("friday.out"));  // file output

    int numYears = in.nextInt();
    int [] daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int [] cntThirteen = new int [7];
    int janOne = 0;

    int cnt = 0;

    while (cnt < numYears) {
      int currYear = startYear + cnt;
      if (checkLeepYear(currYear)) {
        daysInMonth[1] = 29;
      } else {
        daysInMonth[1] = 28;
      }

      for (int i = 0; i < 12; i++) {
        int findDayName = (janOne + 13) % 7;
        cntThirteen[(findDayName + 1) % 7]++;

        janOne += daysInMonth[i];
      }
      janOne = (janOne % 7);

      cnt++;
    }

    for (int i = 0; i < 7; i++) {
      out.format("%d", cntThirteen[i]);  // format() has the same syntax as printf()
      if (i < 6)
        out.format(" ");
    }
    out.format("\n");

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
