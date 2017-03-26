/*
ID: daeseok1
LANG: JAVA
TASK: combo
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

public class combo {

  public static HashSet<String> resStrs = new HashSet<String>();

  public static void makeCombination(List<List<Integer>> pList, List<Integer> nums, int index) {
    if (nums.size() == 3) {
      StringBuilder sb = new StringBuilder();

      for (int i = 0; i < nums.size(); i++) {
        sb.append(nums.get(i));
        if (i < nums.size() - 1)
          sb.append('_');
      }

      if (!resStrs.contains(sb.toString()))
        resStrs.add(new String(sb.toString()));
      return;
    }

    List<Integer> sub = pList.get(index);

    for (int i = 0; i < sub.size(); i++) {
      nums.add(sub.get(i));
      makeCombination(pList, nums, index + 1);
      nums.remove(index);
    }
  }

  public static List<Integer> rangeOfValue(int start, int n) {
    List<Integer> range = new ArrayList<Integer>();

    int temp = start - 2;

    if (temp <= 0) {
      temp = n + temp;
    }

    for (int i = 0; i < 5; i++) {
      int num = (temp + i) % (n + 1);

      if (num == 0) {
        num++;
        temp++;
      }

      range.add(num);
    }

    return range;
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("combo.in"));        // file input
    Formatter out = new Formatter(new File("combo.out"));  // file output

    List<List<Integer>> possibleList = new ArrayList<List<Integer>>();
    List<Integer> list = new ArrayList<Integer>();

    int n = Integer.parseInt(in.nextLine());
    int [] farms = new int [3];
    int [] master = new int [3];
    int [] combi = new int [6];
    int totalCombi = 0;

    int count = 0;

    while (count < 3) {
      farms[count++] = Integer.parseInt(in.next());
    }

    count = 0;
    while (count < 3) {
      master[count++] = Integer.parseInt(in.next());
    }

    for (int i = 0; i < 3; i++) {
      possibleList.add(rangeOfValue(farms[i], n));
    }

    makeCombination(possibleList, list, 0);
    possibleList.clear();

    for (int i = 0; i < 3; i++) {
      possibleList.add(rangeOfValue(master[i], n));
    }

    makeCombination(possibleList, list, 0);

    //System.out.println(resStrs.size());
    out.format("%d\n", resStrs.size());  // format() has the same syntax as printf()

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
