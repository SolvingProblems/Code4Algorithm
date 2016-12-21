import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class mirPrincess {
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    List<String> mirror = new ArrayList<String>();
    List<String> result = new ArrayList<String>();

    int mirSize = input.nextInt();
    int status;

    while (mirSize-- > 0) {
      mirror.add(input.next());
    }

    status = input.nextInt();

    switch(status) {
      case 1:
        for (int i = 0; i < mirror.size(); i++) {
          result.add(mirror.get(i));
        }
        break;
      case 2:
        for (int i = 0; i < mirror.size(); i++) {
          StringBuilder sb = new StringBuilder(mirror.get(i));
          result.add(sb.reverse().toString());
        }
        break;
      case 3:
        for (int i = mirror.size() - 1; i >= 0; i--) {
          result.add(mirror.get(i));
        }
        break;
    }

    for (int i = 0; i < result.size(); i++) {
      System.out.println(result.get(i));
    }
  }
}
