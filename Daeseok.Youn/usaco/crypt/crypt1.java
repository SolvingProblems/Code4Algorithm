/*
ID: daeseok1
LANG: JAVA
TASK: crypt1
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class crypt1 {

  public static final int NUM_LEN = 3;
  public static HashSet<Integer> numsSet = new HashSet<Integer>();

  public static void makeCombination(List<String> output, int [] nums,
                                     StringBuilder sb, int maxLen) {
    if (sb.length() == maxLen) {
      output.add(sb.toString());
      return;
    }

    for (int i = 0; i < nums.length; i++) {
      StringBuilder old = sb;
      sb.append(nums[i]);
      makeCombination(output, nums, sb, maxLen);
      sb.setLength(sb.length() - 1);
    }
  }

  public static boolean isNumberInRange(int num, int cnt) {
    int divide = (int)Math.pow(10, cnt - 1);

    return (num / divide) < 10;
  }

  public static boolean numberCheck(int num, int [] nums) {
    while (num > 0) {
      int temp = num % 10;

      if (!numsSet.contains(temp))
        break;
      num /= 10;
    }

    return num == 0;
  }

  public static void main (String [] args) throws IOException {
    Scanner in = new Scanner(new File("crypt1.in"));        // file input
    Formatter out = new Formatter(new File("crypt1.out"));  // file output

    int cnt = Integer.parseInt(in.nextLine());
    int [] nums = new int [cnt];
    List<String> combiList = new ArrayList<String>();
    List<String> multiList = new ArrayList<String>();

    StringBuilder sb = new StringBuilder();
    int totalSolution = 0;

    int k = 0;
    while (cnt-- > 0) {
      nums[k++] = Integer.parseInt(in.next());
    }

    Arrays.sort(nums);

    for (int i = 0; i < nums.length; i++) {
      numsSet.add(nums[i]);
    }

    makeCombination(combiList, nums, sb, NUM_LEN);
    makeCombination(multiList, nums, sb, 2);
/*
    System.out.println(combiList);
    System.out.println(multiList);
*/
    for (int i = 0; i < combiList.size(); i++) {
      for (int j = 0; j < multiList.size(); j++) {
        int p1 = Integer.parseInt(combiList.get(i)) * (multiList.get(j).charAt(0) - '0');
        int p2 = Integer.parseInt(combiList.get(i)) * (multiList.get(j).charAt(1) - '0');

        int sum = p1 + (p2 * 10);

        if (isNumberInRange(p1, 3) && isNumberInRange(p2, 3) &&
            isNumberInRange(sum, 4) && numberCheck(p1, nums) &&
            numberCheck(p2, nums) && numberCheck(sum, nums))
          totalSolution++;
      }
    }

    out.format("%d\n", totalSolution);  // format() has the same syntax as printf()

    out.close();    // flush the output and close the output file
    System.exit(0); // likely needed in USACO
  }
}
