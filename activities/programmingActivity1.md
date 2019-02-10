# Programming Activity 1

You have one hour to complete a program that reads a series of courses and grades, and returns a summary of how many courses there are and what the average GPA is. The format of the data you will be reading is as follows:

```
CS  234         A
MAT 243         B+
...
```

Namely, each line consists of a sequence of letters indicating the department, followed by a number of spaces and then the course number. After one or more spaces a letter grade for the course is present. The letter grades correspond to GPA scores as follows:
```
A    4.00
A-   3.67
B+   3.33
B    3.00
B-   2.67
C+   2.33
C    2.00
C-   1.67
D+   1.33
D    1.00
F    0
W    The course should not count at all towards the total or the GPA calculation.
```

You are given some start code to help you get started. You will need to:

1. Check out (clone) the `grades` project from GitHub: [https://github.com/sdp-resources/grades](https://github.com/sdp-resources/grades)
2. Start a new IntelliJ project based off of the directory where you cloned the project.
3. Make sure to include the JUnit4 library to the classpath, by using the intention context menu on the import part of `Main.java`.
4. There are a few tests there in the Main class, which you can run by *creating a new JUnit4 configuration to run all tests in the package `sdp`*. They should all be failing right now.

The method you need to write, `processGrades` is given as input a "scanner". A scanner is going to skip whitespaces and return the remaining "tokens" to you when you call an appropriate `next...` method of it. Check out the [Java Scanner documentation](https://docs.oracle.com/javase/7/docs/api/java/util/Scanner.html) for more details.

## Problem Extensions

These are further directions that we will take this program. We'll ideally want our code to accomodate them.

1. Keep track of the courses and grades, and include in the final report an alphabetical listing of the courses.
2. Allow courses to have the "IP" grade for in-progress. In-progress units are reported in the totals if present.
3. Allow S and U courses that are pass/fail and do not contribute to GPA but can count towards graduation.
4. Add "units" to courses (0.5, 1 etc).
5. Add "term/year" to courses to indicate when taken. Generate reports based on each term, and compute term gpas and cumulative term gpas.
