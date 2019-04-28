# Activity 2 - Introduction to IntelliJ: Coding the palindrome

In this activity we will walk through the basic steps for creating a new project in IntelliJ.

## Starting up

- Create a directory for your CS321 work.
- Start the IntelliJ application (under Development).
- The license server is `https://alpha.hanover.edu`.
- Follow through the startup process.
- Select *File -> New -> Project*; follow the Next buttons until you can choose a project name and location. Navigate to the CS321 directory you created. Call the project "WordPalindrome".
- Click Finish.

You are now looking at the main IntelliJ window. The left side has what we call the **project structure**.

## Creating your first class file

- Expand the arrow next to WordPalindrome in the project structure. You should see a blue source folder (`src`). You'll also see two other items there, the `WordPalindrome.iml` file and the `.idea` folder. Both of these hold IntelliJ's information about your project.
- Right-click on the `src` folder to bring up the **context menu**. Choose *New -> Java Class* and name your class `PalindromeChecker`. A new tab will open with the newly-created class file, `PalindromeChecker.java`, containing a basic class definition.
- Starting with the `import java.util.Scanner;` line, type in the code from the handout we discussed earlier. One person can be reading out while the other one is typing. Switch halfway through.

## Testing it out

- Save your file if it is not saved already.
- Right-click the class and choose "Run". This will bring up a "Run" window at the bottom.
- If there were errors during compilation, you will instead see them under a Messages tab. Fix your errors and run again.
- Click in the "Run" window to shift your focus there.
- You should now be able to type in a phrase and press Enter, and the program will tell you if it is a word palindrome or not.
- To end, click the red Stop button on the left.
