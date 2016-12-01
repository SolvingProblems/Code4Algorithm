import java.util.Scanner;

public class fiveAndSix
{
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    String first = input.next();
    String second = input.next();

    int sum = minMaxSum(first, second, false);

    System.out.print(sum + " ");

    sum = minMaxSum(first, second, true);

    System.out.println(sum);
  }

  public static int minMaxSum(String fir, String sec, boolean maxFlag) {
    int i = 0;

    int firNum = 0;
    int secNum = 0;
    int index = 1;

    for (i = fir.length() - 1; i >= 0; i--) {
      int num = fir.charAt(i) - '0';

      if (!maxFlag && num == 6)
        num--;
      else if (maxFlag && num == 5)
        num++;

      firNum += (index * num);
      index *= 10;
    }

    index = 1;

    for (i = sec.length() - 1; i >= 0; i--) {
      int num = sec.charAt(i) - '0';

      if (!maxFlag && num == 6)
        num--;
      else if (maxFlag && num == 5)
        num++;

      secNum += (index * num);
      index *= 10;
    }

    return (int)(firNum + secNum);
  }
}

