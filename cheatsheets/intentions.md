# Intentions

Intentions are triggered in IntelliJ when you use option/alt+enter over some code element. The available options differ depending on the code element. You can see all available intentions in the `Editor -> Intentions` section of the IntelliJ preferences/settings.

Here are the most important categories:

- Boolean (expand boolean to if statements, flip or negate comparisons, ...)
- Conditional/ternary operator (flip conditional, replace if-else with conditional)
- Control flow:
    - Create enum switch branches, create switch statement
    - Extract if conditions
    - Invert if, merge else if, split if, swap ifs
    - Iterate
    - Replace for-each loop with indexed or iterator for loop
- Declarations
    - Assign parameter to field, bind parameters to fields, create field for parameter
    - Convert interface to abstract class
    - Join/split declaration and assignment, move initializer to constructor/setup
    - Create test class for a class
    - Generate overloaded method with default parameter values
    - Implement abstract class
- Imports
    - Add on-demand static import, expand static import
    - Add single member static import
- Visibility/scope (make package-private/private/protected/public)
- Various
    - Add clarifying parens
    - Compute constant value
    - Call chain <----> call sequence
- Refactorings
    - Introduce local variable
    - Encapsulate field
- Strings
    - Break string at newlines
    - Join concatenated literals
    - Replace + with StringBuilder
    - String concat <-----> String.format
