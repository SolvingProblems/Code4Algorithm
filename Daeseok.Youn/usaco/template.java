/*
ID: yourID
LANG: JAVA
TASK: test
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

public class template {  // saved as test.java
   public static void main (String [] args) throws IOException {
      Scanner in = new Scanner(new File("test.in"));        // file input
      Formatter out = new Formatter(new File("test.out"));  // file output

      int a = in.nextInt();
      int b = in.nextInt();
      out.format("%d\n",a+b);  // format() has the same syntax as printf()

      out.close();    // flush the output and close the output file
      System.exit(0); // likely needed in USACO
   }
}
