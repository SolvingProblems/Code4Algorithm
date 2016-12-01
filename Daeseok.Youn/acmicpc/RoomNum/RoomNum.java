import java.util.Scanner;

public class RoomNum {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    int [] roomNums = new int[10];
    int max = 0;
    int i = 0;

    String nums = input.next();

    for (i = 0; i < nums.length(); i++) {
      roomNums[(nums.charAt(i) - '0')]++;
    }

    for (i = 0; i < 9; i++) {
      int value = 0;
      value = roomNums[i];

      if (i == 6) {
        value = roomNums[9];
        value = (int)Math.ceil(value / 2.0);
      }

      if (max < value)
        max = value;
    }

    System.out.println(max);
  }
}
