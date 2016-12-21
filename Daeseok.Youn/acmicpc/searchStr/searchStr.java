import java.util.Scanner;

public class searchStr {
  public static int countSub(String str, String pat) {
    if (str.length() <= 0) return 0;

    if (str.length() >= pat.length() &&
        str.substring(0, pat.length()).equals(pat))
      return 1 + countSub(str.substring(pat.length()), pat);

    return countSub(str.substring(1), pat);
  }
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String str = input.nextLine();
    String pat = input.nextLine();

    System.out.println(countSub(str, pat));
  }
}
