/*
ID: daeseok1
LANG: JAVA
TASK: wormhole
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;
import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

public class wormhole {
   public static void main (String [] args) throws IOException {
      Scanner in = new Scanner(new File("wormhole.in"));        // file input
      Formatter out = new Formatter(new File("wormhole.out"));  // file output

      int n = Integer.parseInt(in.nextLine());

      int pairs = 0;
      Map<Integer, Integer> maps = new HashMap<Integer, Integer>();

      int inCnt = n;
      while (inCnt-- > 0) {
        int x = Integer.parseInt(in.next());
        int y = Integer.parseInt(in.next());

        if (maps.containsKey(y)) {
          maps.put(y, maps.get(y) + 1);
        } else {
          maps.put(y, 1);
        }
      }

      Iterator<Integer> iter = maps.keySet().iterator();

      while (iter.hasNext()) {
        int key = iter.next();

        pairs += maps.get(key)/ 2;
      }

      out.format("%d\n",pairs);  // format() has the same syntax as printf()

      out.close();    // flush the output and close the output file
      System.exit(0); // likely needed in USACO
   }
}
