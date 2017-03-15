/*
ID: daeseok1
LANG: JAVA
TASK: palsquare
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.List;
import java.util.ArrayList;

class PairVals {
  String number;
  String squareNum;

  PairVals(int num, double squre) {
    number = new String(String.valueOf(num));
    squareNum = new String(String.valueOf((int)squre));
  }

  PairVals(String num, String square) {
    this.number = num;
    this.squareNum = square;
  }

  public String getNum() {
    return this.number;
  }

  public String getSquareNum() {
    return this.squareNum;
  }
};

public class palsquare {  // saved as test.java

  public static char [] baseNum = {'0', '1', '2', '3', '4', '5', '6', '7',
                                   '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                                   'G', 'H', 'I', 'J'};

  public static final int MAX_VALUE_BASE10 = 300;

  public static String convertBase(int base, int square) {
    StringBuilder sb = new StringBuilder();

    while (square > 0) {
      sb.append(baseNum[square % base]);
      square /= base;
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

  public static void findAllPalSquare(int base, List<PairVals> res) {
    if (base < 2 || base > 20)
      return;

    for (int i = 1; i <= MAX_VALUE_BASE10; i++) {
      double square = 0.0;
      String squareBased;

      square = Math.pow(i, 2);
      squareBased = convertBase(base, (int)square);

      if (isPalindrome(squareBased))
        res.add(new PairVals(convertBase(base, i), squareBased));
    }
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("palsquare.in"));        // file input
    Formatter out = new Formatter(new File("palsquare.out"));  // file output

    int base = Integer.parseInt(in.nextLine());
    List<PairVals> result = new ArrayList<PairVals>();

    findAllPalSquare(base, result);

    for (int i = 0; i < result.size(); i++) {
      PairVals p = result.get(i);
      out.format("%s %s\n", p.getNum(), p.getSquareNum());
    }
    // out.format("%d\n");  // format() has the same syntax as printf()

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
