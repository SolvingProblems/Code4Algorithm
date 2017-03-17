/*
ID: daeseok1
LANG: JAVA
TASK: dualpal
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.List;
import java.util.ArrayList;

public class dualpal {

  public static char [] baseNum = {'0', '1', '2', '3', '4', '5', '6', '7',
                                   '8', '9'};

  public static String convertBase(int base, int number) {
    StringBuilder sb = new StringBuilder();

    while (number > 0) {
      sb.append(baseNum[number % base]);
      number /= base;
    }

    return sb.reverse().toString();
  }

  public static boolean isPalindrome(String num) {
    if (num.length() <= 1)
      return true;

    int i = 0;
    for (; i < num.length() / 2; i++) {
      if (num.charAt(i) != num.charAt(num.length() - 1 - i))
          break;
    }

    return (i == (num.length() / 2));
  }

  public static List<Integer> findPalindromBases(int num, int start) {
    List<Integer> palRes = new ArrayList<Integer>();

    for (int i = start + 1; i < Integer.MAX_VALUE; i++) {
      int base = 2;
      int cntPal = 0;

      if (palRes.size() >= num)
        break;

      while (base <= 10) {
        String basedNum = convertBase(base++, i);
        if (isPalindrome(basedNum))
          cntPal++;

        if (cntPal >= 2) {
          palRes.add(i);
          break;
        }
      }
    }

    return palRes;
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("dualpal.in"));        // file input
    Formatter out = new Formatter(new File("dualpal.out"));  // file output

    int n = Integer.parseInt(in.next());
    int s = Integer.parseInt(in.next());

    List<Integer> res = findPalindromBases(n, s);

    for (int i = 0; i < res.size(); i++) {
      out.format("%d\n", res.get(i));  // format() has the same syntax as printf()
    }

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
