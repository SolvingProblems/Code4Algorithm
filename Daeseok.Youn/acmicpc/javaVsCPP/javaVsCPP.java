import java.util.Scanner;

public class javaVsCPP {
  public static boolean isUpperCase(char ch) {
    return (ch >= 'A' && ch <= 'Z');
  }

  public static int checkType(String varName) {

    int underScore = 0;
    int upperCase = 0;
    int i;

    for (i = 0; i < varName.length(); i++) {
      char ch = varName.charAt(i);

      if (ch == '_') {
        underScore++;
        if (i == 0 || (i < varName.length() - 1 &&
            varName.charAt(i + 1) == '_'))
          return -1;
      }
      else if (isUpperCase(ch)) {
        upperCase++;
        if (i == 0)
          return -1;
      }
    }

    if (underScore > 0 && upperCase > 0 ||
        varName.charAt(i - 1) == '_')
      return -1; // none
    else if (underScore > 0)
      return 0;  // c++

    return 1; // java
  }

  public static String convertJavaToCpp(String varName) {
    StringBuilder sb = new StringBuilder(varName);

    for (int i = 0; i < sb.length(); i++) {
      char ch = sb.charAt(i);

      if (isUpperCase(ch)) {
          sb.replace(i, i + 1, Character.toString(Character.toLowerCase(ch)));
          sb.insert(i, '_');
      }
    }

//    if (sb.toString().startsWith("java"))
//      return sb.toString().replaceFirst("java", "c");
//    else
      return sb.toString();
  }

  public static String convertCppToJava(String varName) {
    StringBuilder sb = new StringBuilder(varName);
    int idx = -1;

//    if ((idx = sb.indexOf("c")) == 0) {
//      sb.replace(idx, idx + 1, "java");
//    }
//
    for (int i = 0; i < sb.length(); i++) {
      char ch = sb.charAt(i);
      if (ch == '_') {
        sb.replace(i + 1, i + 2,
                   Character.toString(Character.toUpperCase(sb.charAt(i + 1))));
      }
    }

    return sb.toString().replaceAll("_", "");
  }

  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);

    String str = input.next();

    switch(checkType(str)) {
      case 0:
        System.out.println(convertCppToJava(str));
        break;
      case 1:
        System.out.println(convertJavaToCpp(str));
        break;
      default:
        System.out.println("Error!");
    }
  }
}
