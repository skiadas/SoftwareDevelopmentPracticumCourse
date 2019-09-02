# Activity 2 - Introduction to IntelliJ: Coding the palindrome

In this activity we will walk through the basic steps for creating a new project in IntelliJ.

## Starting up

- Create a directory for your CS321 work.
- Start the IntelliJ application (under Development).
- The license server is `http://alpha.hanover.edu`.
- Follow through the startup process.
- Select *File -> New -> Project*;
    - Make sure the Project SDK is set to Java 11 or later.
    - Follow the Next buttons until you can choose a project name and location.
    - Give a name to the project; call it "WordPalindrome".
    - Navigate to the CS321 directory you created. Create a new folder named WordPalindrome.
- Click Finish.

You are now looking at the main IntelliJ window. The left side has what we call the **project structure**.

## Creating your first class file

- Expand the arrow next to WordPalindrome in the project structure. You should see a blue source folder (`src`). You'll also see two other items there, the `WordPalindrome.iml` file and the `.idea` folder. Both of these hold IntelliJ's information about your project.
- Right-click on the `src` folder to bring up the **context menu**. Choose *New -> Java Class* and name your class `PalindromeChecker`. A new tab will open with the newly-created class file, `PalindromeChecker.java`, containing a basic class definition.
- Starting with the `import java.util.Scanner;` line, type in the code from the handout we discussed earlier. One person can be reading out while the other one is typing. Switch halfway through.
    - Pay attention to IntelliJ's visual queues about what is going on with your code. Did you notice how it denotes syntax errors?

## Testing it out

- Save your file if it is not saved already.
- Right-click the class name and choose "Run". This will bring up a "Run" window at the bottom. You can also click the greeen arrow to the left of the start of the class clause in your code.
- If there were errors during compilation, you will instead see them under a Messages tab. Fix your errors and run again.
- Click in the "Run" window to shift your focus there.
- You should now be able to type in a phrase and press Enter, and the program will tell you if it is a word palindrome or not.
- To end, click the red Stop button on the left, or type Ctrl-D.
