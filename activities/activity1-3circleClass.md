# Variables and Designing a Java Class

Your team has been tasked with designing a simple `Circle` class. After some back and forth, your  agree that `Circle` objects should be able to do the following:

- create new circle given radius and center
- calculate area
- calculate perimeter
- given a point, determine if point is inside the circle
- shift circle to have a new center
- scale radius
- give center
- give radius 

You may assume the existance of the `Point` class below as you work on your `Circle` class definition.

```java
public class Point {
  private int x;
  private int y;

  public Point (int x, int y) {
    this.x = x;
    this.y = y;
  }

  public int getX() {
    return x;
  }

  public int getY() {
    return y;
  }

  public void shift(int xChange, int yChange) {
    x += xChange;
    y += yChange;
  }
}
```

## Design Questions

As a team, discuss and come to a consensus on your answers to each of the following questions.

1. What data fields would the `Circle` class need to have?

#. What values should be passed to the constructor so that it can initialize the fields of a newly created `Circle`object? 

#. In the list of `Circle` class functionality (top of page), which items describe accessor methods?  

#. Decide on names for your accessor methods, then write the complete definition for each method.

#. Pi is need when calculating the area and perimeter of a circle. Of the four possible kinds of variablews, what should pi be?

#. Write the *signatures only* for the methods needed to complete the remainder of the `Circle` class functionality. Once you are done, compare your method signatures with another team's.
Is there disagreement on any of the following??

  a. method names
  b. parameter names
  c. return values

  **Report out** on ageements/disagreements. As a class, decide on the final signature for each `Circle` method.

# At the board, work out the complete definition for each `Circle` method. When you are done discuss the following:

  - **Could** the variables for the circle's center and radius be declare final? **Should** they be declared final?
  - If the `Point` class did not have a `shift` method, would this cause any problems for your `Circle` class implementation? 
  - Suppose calling `shift` on a point returned a new `Point` object at the shifted location instead of having changing the fields for the existing point. How would your `Circle` class implementation need to change?
  - Suppose the `shift` and `rescale` of the `Circle` class were changed to return a new `Circle` object instead of changing the existing circle. 
    - Could the fields for the `Circle` class  be changed to *final*? 
    - What would be the implications of this change, assuming it is possible?

  **Report out** and dicuss answers to questions.R



 


