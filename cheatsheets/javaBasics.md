# Java Basics cheatsheet

## Key Terms

- Most Java programming involves calling **methods** of **objects**. The syntax for this is `obj.method(param1, param2)`.
- Objects are created when we **instantiate classes**. We do so with the *new* keyword: `new Cat("Ziggy")`. This calls the class **constructor**.
- Classes can **extend** other classes, which means that they inherit all the functionality from those other classes (but they can also overwrite some of it).
- We also have **interfaces** which are a set of method signatures. A class can **implement** an interface if it has implementations for all the methods indicated in the interface.
- The `this` keyword is used in an object method to refer to the object itself, and to provide access to its **fields**.

## Visibility

Classes, Variables, and Methods etc have *visibility* indicated by a keyword:

public
  ~ Can be accessed by anyone.

private
  ~ Can only be accessed from objects of the class that contains them.

package-private
  ~ Can be accessed by any classes that are within the same package. This is also the default, if no specific word is used.

protected
  ~ Can be accessed by subclasses of the class.

