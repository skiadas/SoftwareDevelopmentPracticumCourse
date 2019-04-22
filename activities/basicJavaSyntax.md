# Basic Java Syntax Sample

```java
// To run:
// 1. View -> Tool Windows -> Terminal
// 2. In Terminal window, type:
//     java -cp out/production/WordPalindrome PalindromeChecker

/*
 * authors: Skiadas, Wilson
 * date: 4/21/2019
 * */

import java.util.Scanner;

public class PalindromeChecker {
  private static final String WHITESPACE_PATTERN = "\\s+";
  private String[] words;

  public PalindromeChecker(String s) {
    words = clean(s).split(WHITESPACE_PATTERN);
  }

  private String clean(String s) {
    return s.toLowerCase().trim();
  }

  boolean isPalindrome() {
    int last = words.length - 1;

    for (int i = 0; i < last - i; i++) {
      String word1 = words[i];
      String word2 = words[last - i];
      if (!word1.equals(word2)) {
        return false;
      }
    }
    return true;
  }

  private String generateResultMessage() {
    return isPalindrome() ?
        "It is a word palindrome!" :
        "It is NOT a word palindrome";
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println(
        "Type a phrase to see if it is a word-level palindrome. " +
            "Press Ctrl-D to end.");

    while (scanner.hasNextLine()) {
      PalindromeChecker checker = new PalindromeChecker(scanner.nextLine());
      System.out.println(checker.generateResultMessage());
    }

    System.out.println("Goodbye!");
  }
}
```

TODO: Theresa, add questions.
