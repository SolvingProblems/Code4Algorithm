/*
ID: daeseok1
LANG: JAVA
TASK: transform
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class transform {  // saved as test.java

  public static final int DEGREE_90 = 1;
  public static final int DEGREE_180 = 2;
  public static final int DEGREE_270 = 3;
  public static final int REFLECT = 4;
  public static final int COMBINATION = 5;
  public static final int NO_CHANGE = 6;
  public static final int INVALID = 7;

  public static final int debug = 0;

  public static boolean isSamePattern(StringBuilder [] ori, String [] target) {
    for (int i = 0; i < ori.length; i++) {
      if (!target[i].equals(ori[i].toString()))
        return false;
    }

    return true;
  }

  public static boolean isReflectAndSave(StringBuilder [] ori, String [] target) {
    /*
    List<String> listPattern = new ArrayList<String>();

    for (int i = 0; i < ori.length; i++)
      listPattern.add(ori[i].toString());

    Collections.reverse(listPattern);
    */
    for (int i = 0; i < ori.length; i++)
      ori[i].replace(0, ori[i].length(), ori[i].reverse().toString());

    return isSamePattern(ori, target);
  }

  public static boolean rotatePattern(StringBuilder [] ori, String [] target, int rotate) {
    StringBuilder [] sbOri = new StringBuilder[ori.length];
    StringBuilder [] oriTemp = new StringBuilder[ori.length];

    for (int i = 0; i < ori.length; i++) {
      sbOri[i] = new StringBuilder();
      sbOri[i].setLength(ori.length);

      oriTemp[i] = new StringBuilder(ori[i].toString());
    }

    while (rotate-- >= 0) {
      for (int i = 0; i < oriTemp.length; i++) {
        for (int j = 0; j < oriTemp[0].length(); j++) {
          sbOri[j].setCharAt(oriTemp[0].length() - 1 - i, oriTemp[i].charAt(j));
        }
      }

      if (rotate >= 0) {
        for (int i = 0; i < sbOri.length; i++)
          //copy temp sbOri to temp
          oriTemp[i].replace(0, oriTemp[i].length(), sbOri[i].toString());
      }
    }

    if (debug != 0) {
      System.out.println("-------------------------------------");
      for (int i = 0; i < sbOri.length; i++) {
        System.out.println(sbOri[i]);
      }
      System.out.println("-------------------------------------");
    }

    return isSamePattern(sbOri, target);
  }

  public static int checkTransformation(StringBuilder [] ori, String [] trans) {
    if (debug != 0) {
      System.out.println("----------original-----------------");
      for (int i = 0; i < ori.length; i++) {
        System.out.println(ori[i]);
      }

      System.out.println("----------rotate-----------------");
    }
    // 90, 180, 270 degree rotation check
    for (int i = 0; i < 3; i++) {
      if (rotatePattern(ori, trans, i)) {
        return DEGREE_90 + i;
      }
    }

    if (debug != 0) {
      System.out.println("----------before reflect-----------------");
      for (int i = 0; i < ori.length; i++) {
        System.out.println(ori[i]);
      }
    }

    if (isSamePattern(ori, trans))
      return NO_CHANGE;

    // check reflection and change ori string
    if (isReflectAndSave(ori, trans))
      return REFLECT;

    if (debug != 0) {
      System.out.println("----------reflect-----------------");
      for (int i = 0; i < ori.length; i++) {
        System.out.println(ori[i]);
      }
      System.out.println("-------------------------------------");
    }

    for (int i = 0; i < 3; i++) {
      if (rotatePattern(ori, trans, i)) {
        return COMBINATION;
      }
    }

    return INVALID;
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("transform.in"));        // file input
    Formatter out = new Formatter(new File("transform.out"));  // file output

    int numLine = Integer.parseInt(in.nextLine());
    int countLine = 0;

    StringBuilder [] ori = new StringBuilder [numLine];
    String [] trans = new String [numLine];

    for (int i = 0; i < numLine; i++) {
      ori[i] = new StringBuilder();
    }
    while (countLine < numLine) {
      ori[countLine++].append(in.nextLine());
    }

    countLine = 0;

    while (countLine < numLine) {
      trans[countLine++] = in.nextLine();
    }

    int res = checkTransformation(ori, trans);

    out.format("%d\n", res);  // format() has the same syntax as printf()

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
