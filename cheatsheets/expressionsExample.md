# Expressions classes example

```java
public abstract class Expression {
  public abstract int getValue();
  public abstract String format();
}
```
```java
public class IntegerExpression extends Expression {
  private int integer;

  IntegerExpression(int integer) {
    this.integer = integer;
  }

  public int getValue() {
    return integer;
  }

  public String format() {
    return String.valueOf(integer);
  }
}
```
```java
public class SumExpression extends Expression {
  private final Expression term1;
  private final Expression term2;

  SumExpression(Expression term1, Expression term2) {
    this.term1 = term1;
    this.term2 = term2;
  }

  public int getValue() {
    return term1.getValue() + term2.getValue();
  }

  public String format() {
    return String.format("(%s + %s)", term1.format(), term2.format());
  }
}
```
```java
import org.junit.Test;

import static org.junit.Assert.*;

public class ExpressionTest {
  @Test
  public void integerExpressions() {
    Expression one = new IntegerExpression(1);
    assertEquals(1, one.getValue());
    assertEquals("1", one.format());
  }

  @Test
  public void sumExpressions() {
    Expression one = new IntegerExpression(1);
    Expression two = new IntegerExpression(2);
    Expression sum = new SumExpression(one, two);
    assertEquals(3, sum.getValue());
    assertEquals("(1 + 2)", sum.format());
    Expression biggerSum = new SumExpression(sum, new IntegerExpression(3));
    assertEquals(6, biggerSum.getValue());
    assertEquals("((1 + 2) + 3)", biggerSum.format());
  }
}
```
