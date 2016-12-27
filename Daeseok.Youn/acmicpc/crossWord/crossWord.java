import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class crossWord {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String horizontal = input.next();
    String vertical = input.next();

    int i = 0, j = 0;

    for (i = 0; i < horizontal.length(); i++) {
      for (j = 0; j < vertical.length(); j++) {
        if (horizontal.charAt(i) == vertical.charAt(j))
          break;
      }
      if (j != vertical.length())
        break;
    }

    int hozIdx = i;
    int vertIdx = j;

    //System.out.println("hozIdx " + hozIdx + " ver : " + vertIdx);
    List<String> strList = new ArrayList<String>();

    j = 0;

    for (i = 0; i < vertical.length(); i++) {
      char [] initArr = new char[horizontal.length()];
      Arrays.fill(initArr, '.');

      StringBuilder sb = new StringBuilder(new String(initArr));

      if (i != vertIdx) {
        sb.setCharAt(hozIdx, vertical.charAt(j++));
        strList.add(sb.toString());
      } else {
        strList.add(horizontal);
        j++;
      }
    }

    for (i = 0; i < strList.size(); i++)
      System.out.println(strList.get(i));
  }
}
