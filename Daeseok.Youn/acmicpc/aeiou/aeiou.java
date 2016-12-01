import java.util.Scanner;

public class aeiou {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    int [] alphaCount = new int[26];
    int [] aeiouIdx = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    int i = 0;

    String str = input.next();

    for (i = 0; i < str.length(); i++) {
      alphaCount[str.charAt(i) - 'a']++;
    }

    for (i = 0; i < aeiouIdx.length; i++) {
      count += alphaCount[aeiouIdx[i] - 'a'];
    }

    System.out.println(count);
  }
}
