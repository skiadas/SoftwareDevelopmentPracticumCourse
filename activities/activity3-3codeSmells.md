# Code Smells

A **code smell** is a feature of the code that makes suggests something is wrong. They were introduced in the [refactoring](https://learning.oreilly.com/library/view/refactoring-improving-the/9780134757681/ch03.xhtml) book (chapter 3), and also extended and discussed in the [clean code](https://learning.oreilly.com/library/view/clean-code/9780136083238/chapter17.html) book, chapter 17.

Comment smells
  ~ - Obsolete comments or comments that hold information better maintained by other means like a version control system.
    - Redundant comments that do little more than restate what the code says.
    - Commented-out code

Naming smells
  ~ - Non-descriptive names.
    - Names at wrong levels of abstractions.
    - Ambiguous names.
    - Type encoding in names.
    - Names that hide side-effects.
    - Function names that don't correctly say what the functions do

Function smells
  ~ - Too many arguments on a function.
    - Flag arguments (booleans).
    - Wrong Levels of Abstraction. The code in each method should be at the same level of abstraction.
    - Feature Envy. A function that uses more methods from another class than its own possibly belongs to that other class.
    - Inappropriate Static functions. When creating static functions, make sure they would not more naturally be housed in the class of one of their parameters.
    - Long functions.

Behavioral smells
  ~ - Obvious behavior not implemented: Functions should implement reasonably expected behavior.
    - Incorrect Behavior at the Boundaries.
    - Code Duplication should be avoided (Don't Repeat Yourself)
    - Parts of the code that have too much knowledge
    - Dead code
    - Artificial Coupling. Don't make parts of your application know about each other if they don't have to.
    - Misplaced Responsibility. Code should go where it is most expected to be found, not where it is most convenient for the programmer.
    - Hidden temporal couplings.
    - Transitive Navigation / Train wrecks.
    - Divergent Change. When a module changes for many different reasons.
    - Shotgun Surgery. When we have to change many modules to effect a single behavioral change.
    - Data Clumps. Data that tends to stick together should be in a class.
    - Primitive Obsession. The overuse of primitive types.
    - Speculative Generality. Unneeded abstractions that make the code harder to read.

Form
  ~ - Vertical Separation. Variables and functions should be close to their use.
    - Inconsistency. Do things in similar ways when possible.
    - Obscured Intent. Various aspects of the code make it hard to discern the code's intent.
    - Lack of Explanatory Variables. Make variables or functions out of complicated expressions.
    - Magic numbers.
    - Complex conditional tests that are not extracted as functions.
    - Temporary field. A field that is not always set/used.
