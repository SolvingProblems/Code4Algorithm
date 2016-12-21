import java.util.Scanner;

public class makesEnigma {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String firstStr = input.next();
    String secondStr = input.next();

    char [] firstCntChar = new char[26];
    char [] secondCntChar = new char[26];
    int result = 0;

    for (int i = 0; i < firstStr.length(); i++)
      firstCntChar[firstStr.charAt(i) - 'a']++;

    for (int i = 0; i < secondStr.length(); i++)
      secondCntChar[secondStr.charAt(i) - 'a']++;

    for (int i = 0; i < 26; i++) {
      if (firstCntChar[i] != secondCntChar[i]) {
        result += (int)Math.abs(firstCntChar[i] - secondCntChar[i]);
      }
    }

    System.out.println(result);
  }
}
