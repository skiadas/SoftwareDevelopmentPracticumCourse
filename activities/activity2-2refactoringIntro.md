# Activity 2 (Day 2) Introduction to refactoring

- Refactoring is a change in the structure of the code, without changing the behavior of the code.
- Its intent is primarily to make the code:
    - easier to read and understand
    - more amenable to future changes and the addition of new features

Refactoring can therefore be thought of as serving two main uses:

1. Cleaning up the code to make it more friendly to future "visitors". We will call this *the boyscout rule*: **Try to leave the code a little better than you found it**.
2. Preparing the code for the addition of some future elements. We must be careful with this second one, and not do it willy-nilly without a concrete idea of what new elements we want to implement. Trying to anticipate all future requirements and preparing the code ready for it results in overly convoluted code that is hard to work with; and it turns out at the end of the day that most of the features you thought would be added were in fact not added. This situation is typically described by the acronym [YAGNI](https://martinfowler.com/bliki/Yagni.html) for "you aren't gonna need it". The key underlying goal should always be to *keep the design simple*.

Refactoring takes many forms, and a more precise list of these refactorings is described [on this page](../cheatsheets/refactorings.md) as well as the [refactoring book](https://learning.oreilly.com/library/view/refactoring-improving-the/9780134757681/).

As an example of this process, consider the following extremely straightforward but quite long-winded solution to the grade-processing activity. A more printable version of the code for this can also be found [at this link](activity2-2refactoringHandout.md)
```java
public class Main {
  private static String processGrades(Scanner scanner) {
    double t = 0;
    int c = 0;
    while (scanner.hasNextLine()) {
      scanner.next("\\s*\\w+\\s*");
      scanner.next("\\s*\\w+\\s*");
      String l = scanner.next("[ABCDFW][+-]?");
      if (scanner.hasNextLine()) {
        scanner.nextLine();
      }
      switch (l) {
      case "A":
        t += 4.00;
        break;
      case "A-":
        t += 3.67;
        break;
      case "B+":
        t += 3.33;
        break;
      case "B":
        t += 3.00;
        break;
      case "B-":
        t += 2.67;
        break;
      case "C+":
        t += 2.33;
        break;
      case "C":
        t += 2.00;
        break;
      case "C-":
        t += 1.67;
        break;
      case "D+":
        t += 1.33;
        break;
      case "D":
        t += 1.00;
        break;
      case "F":
        t += 0.00;
        break;
      case "W":
        break;
      default:
        throw new RuntimeException();
      }
      if (!l.equals("W")) {
        c += 1;
      }
    }
    double gpa = c == 0 ? 0 : t / c;

    return String.format("Courses: %d\nGPA: %.2f\n", c, gpa);
  }
}
```

**Group activity**: Discuss what features of this code make it hard to read, and possibly hard to change in the future. Do this before reading on.

So let's list a number of problems here:

- The variable names are really not very descriptive at all. Most of them are single letters, and they don't make it clear what is going on. So we will want to rename them. **Renaming** is probably the simplest of all the refactorings.
- There is a large switch statement, whose goal seems to be to figure out what numeric value should correspond to a particular letter grade. This part have a very clear logic of its own, so it should probably be a separate function. **Extracting** a piece of code to create a new method or a new local variable is another fairly simple but extremely important form of refactoring.
- There are various bits and pieces of computations and calls to the `scanner` class that are by themselves somewhat obscure. We could use a comment for them, or we can also extract them into methods and use the method name to describe them.
- Thinking about it, we possibly want to have a separate class that represents a grade, and it knows about the corresponding value for each letter etc.

## Phase 1: Renaming and method extraction

We can start with some simple changes:

- Rename the variable `t` to `total`. We need to do this consistently, and also to make sure there isn't already a variable named `total`. Note how many places this had to change in!
- Rename the variable  `c` to `courses`. This counts the number of courses that we count towards the gpa.
- It seems that `l` stands for a `letter` grade so we'll use that name instead.
- We now select that whole `switch` statement, and extract it into a separate method. Since the switch statement changes the `total` value, we will need to make it return an `int`. And really if we notice the various statements like `t += 1.33;` we probably want our function to simply return the `1.33`, and do the addition at the end. So our code will say something like: `total += getGradeForLetter(letter);`
- The statement `!letter.equals("W")` is really meant to determine if the letter grade should count for credit. we therefore want to replace it with a method call: `countsForCredit(letter)`
- It seems that the line `courses == 0 ? 0 : total / courses` computes the total gpa, so we'll extract it into a function `computeGPA`.
- There are some `scanner.next("\\s*\\w+\\s*");` lines at the beginning. Actually these two lines serve different purposes: The first reads the course department prefix, while the other reads the course number and letter grade. We extract them in two function `readPrefix` and `readCourseNo`. In the future, the code for these might no longer be the same.
- The `scanner.next("[ABCDFW][+-]?");` pattern reads a letter grade. We again extract it to a `readLetterGrade` method.
- The conditional that follows, `if (scanner.hasNewLine()) ...` basically reads to the end of the current line. We should extract this to a method as well: `readToEndOfLine()`.
- Lastly, the `String.format("Courses: %d\nGPA: %.2f\n", courses, gpa);` phrase should probably also be its own method, called `formatSummary`.

At this point our code looks as follows. Notice how much more readable the main function's operations are.
```java
public class Main {
  private static String processGrades(Scanner scanner) {
    double total = 0;
    int courses = 0;
    while (scanner.hasNextLine()) {
      readPrefix(scanner);
      readCourseNo(scanner);
      String letter = readLetterGrade(scanner);
      readToEndOfLine(scanner);
      total += getGradeForLetter(letter);
      if (countsForCredit(letter)) {
        courses += 1;
      }
    }
    double gpa = computeGPA(courses, total);
    return formatSummary(courses, gpa);
  }

  private static void readPrefix(Scanner scanner) {
    scanner.next("\\s*\\w+\\s*");
  }

  private static void readCourseNo(Scanner scanner) {
    scanner.next("\\s*\\w+\\s*");
  }

  private static String readLetterGrade(Scanner scanner) {
    return scanner.next("[ABCDFW][+-]?");
  }

  private static void readToEndOfLine(Scanner scanner) {
    if (scanner.hasNextLine()) { scanner.nextLine(); }
  }

  private static double getGradeForLetter(String letterGrade) {
    switch (letterGrade) {
    case "A": return 4.00;
    case "A-": return 3.67;
    case "B+": return 3.33;
    case "B": return 3.00;
    case "B-": return 2.67;
    case "C+": return 2.33;
    case "C": return 2.00;
    case "C-": return 1.67;
    case "D+": return 1.33;
    case "D": return 1.00;
    case "F": return 0.00;
    case "W": return 0.00;
    default: throw new RuntimeException();
    }
  }

  private static boolean countsForCredit(String letter) {
    return !letter.equals("W");
  }

  private static double computeGPA(int courses, double total) {
    return courses == 0 ? 0 : total / courses;
  }

  private static String formatSummary(int courses, double gpa) {
    return String.format("Courses: %d\nGPA: %.2f\n", courses, gpa);
  }
}
```

## Phase 2: Class extraction, moving elements around

Looking at all these, a couple of things stand out that suggest creating some new classes:

- It seems quantities like `courses`, `total` and `gpa` are often used together. It would make sense for them to all be part of the same class. In fact, since `gpa` is simply computed from the other two, it would make sense for such a class to basically maintain the courses and total, but to be able to report the gpa when asked. Perhaps such a class could be called `Summary`.
- It seems clear that the logic for computing the numeric equivalent of a letter grade, and whether that grade should count for credit or not, is very separate from the rest, and perhaps should be its own `Grade` class.
- Finally, a number of methods deal with processing the input using the scanner. These should also be in a dedicated class, perhaps called a `GradeReader`.

Let's see how we might go about creating these classes.

- We start with the `Summary` class. We will start by performing "Extract Parameter Object" on the `computeGPA` method, to turn those two parameters into one `summary` object of a new `Summary` inner class of `Main`.
- This left a `new Summary(courses, total)` argument inside the `computeGPA` method. We extract it to a variable `summary`.
- We still have the local variables `courses` and `total` around. We gradually replace them with `summary.courses` and `summary.total` after we move the creation of `summary` to just before the while loop. In the process, we have to tell the system that the two fields should not be final.
- We now inline the two local variables, which now are only used by the `Summary` constructor.
- In the `Summary` class, we inline the two parameters in the constructor, as their value should really always start at 0. We then move the initializations to the declarations, and delete the now empty constructor (it will use the default constructor).
- The `computeGPA` method should really be an instance method of the `Summary` class, we move it there and inline its use of `getCourses` and `getTotal`.
- We similarly want to move the `formatSummary` method. But we cannot yet until it has the `summary` as it parameter. We start by inlining the `gpa` local variable.
- Now we perform "Extract Method" on the expression `formatSummary(summary.courses, summary.computeGPA());` to get `format` method with `summary` as its parameter. Then we inline the old `formatSummary` method.
- Then we move the `format` method to an instance method of the `Summary` class, and inline any getters used in its body.
- Now we are left with the four lines that update the `courses` and `total` values. Thinking about it more, these should happen in a single update, something like `summary.add(units, points)`. Or even better, just `summary.addGrade(letter)`. This letter will probably become the grade later on. So we extract a method from those lines and then move it to the `summary` class.
- Lastly, up to now the `Summary` class was an inner class of `Main`. We now move it to its own file, which means we have to make a number of our methods public (or at least package-protected).

Here's how our code looks now:
```java
//  Extracting the Summary class
public class Main {
  private static String processGrades(Scanner scanner) {
    Summary summary = new Summary();
    while (scanner.hasNextLine()) {
      readPrefix(scanner);
      readCourseNo(scanner);
      String letter = readLetterGrade(scanner);
      readToEndOfLine(scanner);
      summary.addGrade(letter);
    }
    return summary.format();
  }

  private static void readPrefix(Scanner scanner) {
    scanner.next("\\s*\\w+\\s*");
  }
  private static void readCourseNo(Scanner scanner) {
    scanner.next("\\s*\\w+\\s*");
  }
  private static String readLetterGrade(Scanner scanner) {
    return scanner.next("[ABCDFW][+-]?");
  }
  private static void readToEndOfLine(Scanner scanner) {
    if (scanner.hasNextLine()) { scanner.nextLine(); }
  }

  static double getGradeForLetter(String letterGrade) {
    switch (letterGrade) {
    case "A": return 4.00;
    case "A-": return 3.67;
    case "B+": return 3.33;
    case "B": return 3.00;
    case "B-": return 2.67;
    case "C+": return 2.33;
    case "C": return 2.00;
    case "C-": return 1.67;
    case "D+": return 1.33;
    case "D": return 1.00;
    case "F": return 0.00;
    case "W": return 0.00;
    default: throw new RuntimeException();
    }
  }

  static boolean countsForCredit(String letter) {
    return !letter.equals("W");
  }
}

class Summary {
  private int courses = 0;
  private double total = 0.00;

  void addGrade(String letter) {
    this.total += Main.getGradeForLetter(letter);
    if (Main.countsForCredit(letter)) { this.courses += 1; }
  }

  String format() {
    return String.format("Courses: %d\nGPA: %.2f\n", courses, computeGPA());
  }

  private double computeGPA() {
    return courses == 0 ? 0 : total / courses;
  }
}
```

Now we proceed with our second class extraction. It looks like it might be nice to have the concept of a *grade* as more than a single letter, namely an entity that has some functions. Maybe later we can turn it into an `enum`, but for now it would be good to simply have a `Grade` class.

- We start from the `addGrade` method in `Summary`, which currently takes as input a `letter`. We perform "Extract Parameter Object" on it to turn that `letter` into a `Grade` class as an inner class of `Summary`.
- We now have to lines in `addGrade` from which we can extract new methods of the `Grade` class: `Main.getGradeForLetter(grade.getLetter());` should become a `getPoints` method and then moved to the `grade` instance. And `Main.countsForCredit(grade.getLetter())` should be extracted to a `countsForCredit` method and then moved to the `Grade` class.
- We now look at the bodies of these two methods and inline the two `Main...` methods that are no longer needed.
- We also move `Grade` to the upper level and adjust the access modifiers of some of its methods.
- Lastly, we notice that `getLetter` is used only internally in `Grade`, and we inline it.

We will also handle the processing steps. We effectively want to replace all uses of the `scanner` with uses of a newly-created `Processor`, with the scanner as part of its constructor. In order to achieve this, we'll have to perform a step that by itself does not appear useful, namely we'll extract the whole `while` loop into a single new method. This is a temporary step so that we have a place where we can perform "Extract object".

- We perform "Extract Method" on the `while` loop to obtain a `processAll` method.
- We perform "Extract Parameter Object" on just the `scanner` parameter of the `processAll` method. We then perform "Inline" on the `processAll` method to eliminate it.
- We now need to perform "Extract Method" to all the various lines that use the processor, as they should mostly be methods there. We extract method called `hasNext`, then move it to be an instance method of processor.
- We repeat this process for `readPrefix(processor.getScanner())` to a method called `readPrefix`, for `readCourseNo(processor.getScanner());` to a method called `readCourseNo`, for `readLetterGrade(processor.getScanner());` to `readLetterGrade` and finally for `readToEndOfLine(processor.getScanner());` to `readToEndOfLine`. We convert each to an instance method of `Processor`. We then inline the `Main...` bodies of these new `Processor` methods, to remove the original methods that are still in the `Main` class.
- We then inline all the uses of `getScanner` and eliminate the method from `Processor`. The rest of the world does not need access to our scanner.
- Lastly, we look back at our main `while` loop. It seems that there are at least four lines there that concern how the processor will process a line, in terms of the order in which events will happen. That really ought to be in the processor. So we will move it there. The conversion of a letter to a `Grade` should also be a part of that, but right now it is intertwined with the `addGrade` call. We start by extracting a `grade` variable from the `new Grade(letter);` expression. Then we grab all but the last line of the body of the `while` loop, and perform extract method for it to a method `getNext` which we then convert to an instance method of the processor. We then inline the `grade` variable we temporarily created.
- Finally, we pull this `Processor` class to the upper level.

Here is our code at this point, nicely separated into four classes. Notice how simple the `processGrades` method has become:

- It creates a summary and a processor.
- It keeps reading grades using the processor, and adding them to the summary.
- It then returns the summary using its formatter.

```java
public class Main {
  private static String processGrades(Scanner scanner) {
    Summary summary = new Summary();
    Processor processor = new Processor(scanner);
    while (processor.hasNext()) {
      summary.addGrade(processor.getNext());
    }
    return summary.format();
  }
}

class Processor {
  private final Scanner scanner;

  Processor(Scanner scanner) { this.scanner = scanner; }

  boolean hasNext() { return scanner.hasNextLine(); }

  Grade getNext() {
    readPrefix();
    readCourseNo();
    String letter = readLetter();
    readToEndOfLine();
    return new Grade(letter);
  }

  private void readPrefix() { scanner.next("\\s*\\w+\\s*"); }

  private void readCourseNo() { scanner.next("\\s*\\w+\\s*"); }

  private String readLetter() { return scanner.next("[ABCDFW][+-]?"); }

  private void readToEndOfLine() {
    if (scanner.hasNextLine()) { scanner.nextLine(); }
  }
}

class Summary {
  private int courses = 0;
  private double total = 0.00;

  void addGrade(Grade grade) {
    this.total += grade.getPoints();
    if (grade.countsForCredit()) { this.courses += 1; }
  }

  String format() {
    return String.format("Courses: %d\nGPA: %.2f\n", courses, computeGPA());
  }

  private double computeGPA() { return courses == 0 ? 0 : total / courses; }
}

class Grade {
  private final String letter;

  Grade(String letter) { this.letter = letter; }

  double getPoints() {
    switch (letter) {
    case "A": return 4.00;
    case "A-": return 3.67;
    case "B+": return 3.33;
    case "B": return 3.00;
    case "B-": return 2.67;
    case "C+": return 2.33;
    case "C": return 2.00;
    case "C-": return 1.67;
    case "D+": return 1.33;
    case "D": return 1.00;
    case "F": return 0.00;
    case "W": return 0.00;
    default: throw new RuntimeException();
    }
  }

  boolean countsForCredit() { return !letter.equals("W"); }
}
```
