import java.util.Scanner;
import java.util.Comparator;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class kayakRun {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int r = input.nextInt();
    int c = input.nextInt();
    int lineNum = 0; // line num.
    List<kayak> kayakList = new ArrayList<kayak>();
    int [][] rankingTable = new int[51][1];
    int rank = 1;

    input.nextLine();

    while (r-- > 0) {
      String line = input.nextLine();
      kayak k = new kayak();
      int closer = 0;
      k.setLineNum(lineNum++);

      for (int i = line.length() - 2; i >= 0; i--) {
        if (line.charAt(i) != '.')
          break;
        closer++;
      }
      k.setCloser(closer);

      kayakList.add(k);
    }

    Collections.sort(kayakList, new kayakComparator());

    int prev = kayakList.get(0).getCloser();
    int maxIdx = 0;

    rankingTable[kayakList.get(0).getLine()][0] = rank;

    for (int i = 1; i < kayakList.size(); i++) {
      int curr = kayakList.get(i).getCloser();

      if (prev != curr) {
        rank++;
        prev = curr;
      }

      rankingTable[kayakList.get(i).getLine()][0] = rank;
    }

    maxIdx = Math.min(kayakList.size(), 9);

    for (int i = 0; i < maxIdx; i++) {
      System.out.println(rankingTable[i][0]);
    }
  }
}

class kayak {
  private int line;
  private int closer;

  public kayak() {
    line = 0;
    closer = 0;
  }

  public int getLine() {
    return line;
  }

  public int getCloser() {
    return closer;
  }

  public void setLineNum(int n) {
    line = n;
  }

  public void setCloser(int c) {
    closer = c;
  }
}

class kayakComparator implements Comparator<kayak> {
  @Override
  public int compare(kayak first, kayak sec) {
    if (first.getCloser() > sec.getCloser()) {
      return 1;
    }
    return -1;
  }
}

