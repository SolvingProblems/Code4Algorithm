import java.util.Scanner;
import java.util.HashMap;
import java.lang.StringBuilder;

public class OctalToDecimal {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    HashMap<String, String> octalToDec = new HashMap<String, String>();

    octalToDec.put("000", "0");
    octalToDec.put("001", "1");
    octalToDec.put("010", "2");
    octalToDec.put("011", "3");
    octalToDec.put("100", "4");
    octalToDec.put("101", "5");
    octalToDec.put("110", "6");
    octalToDec.put("111", "7");

    String binStr = input.next();
    StringBuilder sb = new StringBuilder(binStr);
    StringBuilder res = new StringBuilder();

    if (binStr.length() % 3 != 0) {
      for (int i = 0; i < 3 - (binStr.length() % 3); i++)
        sb.insert(0, "0");
    }

    binStr = sb.toString();
    int index = 0;

    while (index <= binStr.length() - 3) {
      String sub = binStr.substring(index, index + 3);
      index += 3;

      res.append(octalToDec.get(sub));
    }

    System.out.println(res.toString());
  }
}
