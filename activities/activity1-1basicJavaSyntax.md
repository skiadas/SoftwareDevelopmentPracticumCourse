# Basic Java Syntax - Example Program

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

### Questions:

1. What does it mean that the `WHITESPACE_PATTERN` field has been declared *static*?
2. What does it mean that `WHITESPACE_PATTERN` has been declared *final*?
3. How many constructors does the `PalindromeChecker` class have?
4. What does it mean that the `clean` method has been declared *private*?
5. What is the scope of the `isPalindrome` method?
6. Can the signature of the `main` method be changed?
7. Which class methods do not take any parameters?
8. Which class methods do not declare any local variables?
9. How many `PalindromeChecker` objects will be created when the program executes?
10. Translate the body of `generateResultMessage` into an if-then statement.
11. What does `clean(s).split(WHITESPACE_PATTERN)` in `PalindromeChecker` accomplish?
12. What method is used to print to standard output?
13. What is the scope of variable `i` in the `isPalindrome` method?
14. Translate the for loop from `isPalindrome` into English.
