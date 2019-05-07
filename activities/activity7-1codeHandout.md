# Accounting Example: Expense Report Original Design

```java
public class Expense {
  public enum Type {DINNER, BREAKFAST, CAR_RENTAL};
  public Type type;
  public int amount;

  public Expense(Type type, int amount) {
    this.type = type;
    this.amount = amount;
  }
}
```

```java
public class printReport {

  public void printReport(ReportPrinter printer) {
    int total = 0;
    int mealExpenses = 0;

    printer.print("Expenses " + getDate() + "\n");

    for (Expense expense : expenses) {
      if (expense.type == BREAKFAST || expense.type == DINNER)
        mealExpenses += expense.amount;

      String name = "TILT";
      switch (expense.type) {
        case DINNER: name = "Dinner"; break;
        case BREAKFAST: name = "Breakfast"; break;
        case CAR_RENTAL: name = "Car Rental"; break;
      }

      printer.print(String.format("%s\t%s\t$%.02f\n",
              (  (expense.type == DINNER && expense.amount > 5000)
              || (expense.type == BREAKFAST && expense.amount > 1000)) ? "X" : " "),
              name, expense.amount / 100.0);

      total += expense.amount;
    }
    printer.print(String.format("\nMeal Expenses $%.02f", mealExpenses / 100.0));
    printer.print(String.format("\nTotal $%.02f", total / 100.0));
  }
}
```


