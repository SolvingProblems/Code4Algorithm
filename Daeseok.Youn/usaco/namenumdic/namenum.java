/*
ID: daeseok1
LANG: JAVA
TASK: namenum
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class namenum {  // saved as test.java
  public static final boolean debug = false;
  public static HashSet<String> dictWords = new HashSet<String>();

  public static StringBuilder sb = new StringBuilder();
  public static List<String> resList = new ArrayList<String>();

  public static void findWordfromDict(List<String> selected, int index) {
    if (selected.size() <= index) {
      if (dictWords.contains(sb.toString())) {
        resList.add(sb.toString());
      }
      return;
    }

    String str = selected.get(index);

    for (int i = 0; i < str.length(); i++) {
      sb.append(str.charAt(i));
      findWordfromDict(selected, index + 1);
      sb.setLength(sb.length() - 1);
    }
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("namenum.in"));        // file input
    Scanner dictFile = new Scanner(new File("dict.txt"));        // file input
    Formatter out = new Formatter(new File("namenum.out"));  // file output

    List<String> mapNumChar = new ArrayList<String>();
    mapNumChar.add("ABC");  // 2
    mapNumChar.add("DEF");  // 3
    mapNumChar.add("GHI");  // 4
    mapNumChar.add("JKL");  // 5
    mapNumChar.add("MNO");  // 6
    mapNumChar.add("PRS");  // 7
    mapNumChar.add("TUV");  // 8
    mapNumChar.add("WXY");  // 9

    List<String> selected = new ArrayList<String>();

    while (dictFile.hasNextLine()) {
      dictWords.add(dictFile.nextLine());
    }

    if (debug) {
      Iterator<String> iter = dictWords.iterator();

      while (iter.hasNext()) {
        System.out.println(iter.next());
      }
    }

    String inputNum = in.nextLine();
    for (int i = 0; i < inputNum.length(); i++) {
      selected.add(mapNumChar.get(inputNum.charAt(i) - '0' - 2));
    }

    findWordfromDict(selected, 0);

    if (resList.size() == 0) {
      resList.add("NONE");
    }

    for (int i = 0; i < resList.size(); i++) {
      out.format("%s\n", resList.get(i));
    }

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
