# Java Variables

THERESA IS STILL WORKING ON THIS


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

Part 1: Static variables

Sometimes there are variables that can or should be shared between all the objects in the class. These are called class variables or static variables.

Need examples.


Goal: Design a class to represent circles.  What would we want our circle to be able to do?
- create new circle given radius and center
- calculate area
- calculate perimeter
- given a point, determine if point is inside the circle
- shift circle to have a new center
- scale radius
- getCenter
- getRadius


What instance variables would we need to have?
center
radius

Write constructor: What parameters should the constructor have?


What are the accessors?  Write those methods.


Question: Aside from the accessors, which methods can do their job just using the instance variables?

 ==> Should lead to a discussion of needing pi for calculating area and perimeter. 
     - How & where should we declare a variable for pi?
     - What sort of variable should pi be?

 ==> Talk about keywords "static" and "final". "final" here means the value of the variable 
cannot be changed, i.e., it's a constant.


Write the signatures for remaining methods. Have groups compare answers. This will hopefully raise
questions.

REPORT OUT: 
   - Were there disagreements in the name for methods? Names for parameters?
   - Were there disagreements about what should be returned. For example, shift and rescale.
   - Decide as a class on final signatures for our methods.


Write the implementations (at the board)

Questions:
   - Could the center or the radius be declare final?  Should they?
   - How would you do the shift for the circle if the point class didn't have a shift method? Would that cause any problems.
   - What if the shift method was returning a new point instead of changing it's own fields. How would your Circle implementation need to change?
   - Suppose we change shift and rescale to return a new Circle, instead of changing the existing circle. Could the fields for the Circle be changed to final? What would be the implications of doing this, assuming it is possible?

REPORT OUT:
   - Go over questions.

Consi



 


