# Activity 7-3: The Interface Segregation Principle

## Introduction

**03:24-06:50    overview**

## Interfaces

**14:28-21:00    interfaces**

1. What is the problem with the `Switch -> Light` dependency?
2. What do interfaces have more in commmon with? Their users *or* their clients?
3. Explain the terms **physical coupling** and **logical coupling** and the phrase ``Inheritance is the strongest of the physical couplings but the weakest of the logical couplings''.
4. How should we *name* interfaces?

## Fat classes

**24:40-33:42  fat classes example: the job class**
**33:42-36:30 the problem with fat classes**

1. Fat classes have large fan-____
2. Fat classes can be protected from their clients by creating a separate interface for each client.

TODO: Discuss how to prevent classes coupled to each other because of they depend on the same large class.

**45:00- 50:00 the interface segregation principle**

1. What does the interface segregation principle say?
2. How can a change to a module affect other modules that don't depend on it?

**54:00-58:25 the need to know**
