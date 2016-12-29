import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class coupon {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int t = input.nextInt();
    List<Integer> res = new ArrayList<Integer>();

    while (t-- > 0) {
      int p = input.nextInt();
      int m = input.nextInt();
      int f = input.nextInt();
      int c = input.nextInt();

      int dooy = (((m / p) * c) / f);
      int sang = dooy;
      int temp = dooy;

      System.out.println("dooy : " + dooy);
      while (temp >= f) {
        temp /= f;
        sang += temp;
      }

      System.out.println("sang : " + sang);
      res.add(sang - dooy);
    }

    for (int i = 0; i < res.size(); i++) {
      System.out.println(res.get(i));
    }
  }
}
