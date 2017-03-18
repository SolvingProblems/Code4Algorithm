/*
ID: daeseok1
LANG: JAVA
TASK: milk
*/

import java.util.Scanner;
import java.util.Formatter;
import java.io.File;
import java.io.IOException;

import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;

public class milk {  // saved as test.java
   public static void main (String [] args) throws IOException {
      Scanner in = new Scanner(new File("milk.in"));        // file input
      Formatter out = new Formatter(new File("milk.out"));  // file output

      int totalAmount = Integer.parseInt(in.next());
      int maxFarmers = Integer.parseInt(in.next());
      int pay = 0;

      List<FarmerInfo> farmers = new ArrayList<FarmerInfo>();

      while (maxFarmers-- > 0) {
        int unitPrice = Integer.parseInt(in.next());
        int totalUnit = Integer.parseInt(in.next());

        farmers.add(new FarmerInfo(totalUnit, unitPrice));
      }

      Collections.sort(farmers, new Comparator<FarmerInfo>() {
        @Override
        public int compare(FarmerInfo f0, FarmerInfo f1) {
          return f0.getPrice() - f1.getPrice();
        }
      });

      for (FarmerInfo f : farmers) {
        int p = f.getPrice();
        int units = f.getUnits();

        int cntBuy = Math.min(totalAmount, units);
        totalAmount -= cntBuy;

        pay = pay + (cntBuy * p);
        if (totalAmount <= 0) {
          break;
        }
      }

      out.format("%d\n", pay);  // format() has the same syntax as printf()

      out.close();    // flush the output and close the output file
      System.exit(0); // likely needed in USACO
   }

   private static class FarmerInfo {
     private int units;
     private int price;

     FarmerInfo(int u, int p) {
       this.units = u;
       this.price = p;
     }

     public int getUnits() {
       return this.units;
     }

     public int getPrice() {
       return this.price;
     }
   }
}
