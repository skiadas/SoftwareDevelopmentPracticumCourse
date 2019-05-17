# Activity 15-2: Null Object Pattern

## Null Pointer Exception

- Who has encountered a **null pointer exception**?

- Behind the scenes in Java, all variables are pointers.  What are the implications of this for when we are designing and writing code? 

	- Problem: 

	Suppose you have a container class (list, dictionary, set, etc.) that contains `Items`. An obvious method you would want is `getItem`.

	What are the ways you might handle a `getItem(item)` called when the requested item is not in the container?


## Null Object Pattern Example

- `empty_node` class from CS223 binary search tree lab.

## Null Objects

- Null Objects have methods that implement "nothing" in just the right way.

- In this context: "nothing" => "inconsequential"
	- A Null Object must be able to pass through the system without consequence.
	- Ensuring this requires careful thought and planning about how exactly the Null Object should behave for each method.

- The Null Object Pattern is an elegant solution to help eliminate the need null pointer checks.
