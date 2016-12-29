import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class foxsay {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    int testCase = input.nextInt();
    boolean [] bitMap = new boolean[101];
    Arrays.fill(bitMap, false);

    input.nextLine();

    while (testCase-- > 0) {
      String recored = input.nextLine();

      List<String> splited = new ArrayList<String>(Arrays.asList(recored.split(" ")));
      for (int i = 0; i < splited.size(); i++) {
        bitMap[i] = true;
      }

      while (true) {
        String sound = input.nextLine();

        if (sound.equals("what does the fox say?"))
          break;

        String splitedSnd = sound.split(" ")[2];

        for (int j = 0; j < splited.size(); j++)
          if (splited.get(j).equals(splitedSnd))
            bitMap[j] = false;
      }

      for (int i = 0; i < splited.size(); i++) {
        if (bitMap[i])
          System.out.print(splited.get(i) + " ");
      }
      System.out.println();
    }
  }
}
