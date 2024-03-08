# **C++ Module 08**

My solutions for the C++ module exercises at 42 School. Each exercise is to understand C++ concepts, mostly templating and STL (Standard Template Library), inheritance, polymorphism, and container adaptors.

### **Prerequisites**

- A C++ compiler supporting the C++98 standard

### **Compilation**

Each exercise directory contains a Makefile for easy compilation. To compile an exercise, navigate to its directory and run:

```bash

cd ex00 && make && ./ex00
```

This will produce an executable named after the exercise (e.g., **`ex00`**, **`ex01`**, etc.), which you can then run:

## Status
Validated 27/02/2024. Grade: 100%.

## **Exercise 00: Easy Find**

- **Directory**: **`ex00/`**
- **Objective**: Implement a template function **`easyfind`** that searches for a given integer in any STL container and throws an exception if the integer is not found.
- **Key Concepts**: Templating, STL algorithms, Exception handling.

## **Exercise 01: Span**

- **Directory**: **`ex01/`**
- **Objective**: Develop a **`Span`** class capable of storing a maximum number of integers and providing the shortest and longest span between stored integers.
- **Key Concepts**: Class design, STL containers and algorithms, Dynamic memory management.

## **Exercise 02: Mutated Abomination**

- **Directory**: **`ex02/`**
- **Objective**: Extend the **`std::stack`** container to make it iterable, without altering its original functionality. By inheriting from **`std::stack`**, we introduce iterability to the **`MutantStack`** class without changing its original stack functionality. This involves exposing iterators that allow traversal of the stack elements from bottom to top, effectively turning the stack into a linearly iterable container while retaining its LIFO (Last In, First Out) nature
- **Key Concepts**: Inheritance, Container adaptors, Iterator protocol.

## **Running the Tests**

Each exercise includes a main function with comprehensive tests to demonstrate the functionality and to ensure correctness. After compiling an exercise, run the executable to see the test outcomes.
