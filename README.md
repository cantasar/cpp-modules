# C++ Modules - École 42

C++ modules from École 42. Each module focuses on specific concepts of C++ programming, gradually introducing object-oriented programming principles.

## Table of Contents

- [Overview](#overview)
- [Modules Summary](#modules-summary)
- [Detailed Module Descriptions](#detailed-module-descriptions)
- [Installation and Usage](#installation-and-usage)

## Overview

These modules are designed to introduce C++ programming concepts progressively, starting from basic syntax and moving to advanced object-oriented features. Each module contains several exercises that build upon each other, reinforcing learning through practical implementation.

## Modules Summary

| Module | Topic | Key Concepts | Repository Link |
|--------|-------|--------------|-----------------|
| CPP00 | Namespaces, Classes | Classes, Member functions, Stdio streams | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp00) |
| CPP01 | Memory Allocation | Pointers, References, File streams | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp01) |
| CPP02 | Ad-hoc Polymorphism | Operator overloading, Fixed-point numbers | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp02) |
| CPP03 | Inheritance | Class inheritance, Multiple inheritance | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp03) |
| CPP04 | Polymorphism | Abstract classes, Virtual functions | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp04) |
| CPP05 | Exceptions | Try-catch blocks, Custom exceptions | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp05) |
| CPP06 | Casts | Static cast, Dynamic cast, Type conversions | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp06) |
| CPP07 | Templates | Function templates, Class templates | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp07) |
| CPP08 | Containers | STL containers, Iterators, Algorithms | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp08) |
| CPP09 | STL | Advanced STL usage, Lambdas, Functors | [View Code](https://github.com/cantasar/cpp-modules/tree/main/cpp09) |

## Detailed Module Descriptions

### CPP00: Namespaces, Classes, and More

| Concept | Description | Projects |
|---------|-------------|----------|
| Classes | Object-oriented design foundations | Megaphone, PhoneBook |
| Namespaces | Code organization and scope | All exercises |
| Member Functions | Methods within classes | PhoneBook, Account |
| Static & Const | Immutable and shared members | Account |

### CPP01: Memory Allocation and References

| Concept | Description | Projects |
|---------|-------------|----------|
| Memory Allocation | Dynamic memory with new/delete | Zombie |
| References | Alternative to pointers | Brain |
| File Streams | Reading/writing files | Violence, Sed |
| Switch Statement | Control flow | All exercises |

### CPP02: Ad-hoc Polymorphism and Operator Overloading

| Concept | Description | Projects |
|---------|-------------|----------|
| Operator Overloading | Customizing operators | Fixed |
| Canonical Form | Standard class structure | All exercises |
| Fixed-point Numbers | Non-floating point implementation | Fixed |

### CPP03: Inheritance

| Concept | Description | Projects |
|---------|-------------|----------|
| Class Inheritance | Derived classes functionality | ClapTrap, ScavTrap |
| Multiple Inheritance | Inheriting from multiple bases | DiamondTrap |
| Diamond Problem | Ambiguity in multiple inheritance | DiamondTrap |

### CPP04: Subtype Polymorphism and Abstract Classes

| Concept | Description | Projects |
|---------|-------------|----------|
| Virtual Functions | Runtime polymorphism | Animal, Dog, Cat |
| Abstract Classes | Classes with pure virtual functions | Interface implementation |
| Deep Copy | Proper resource management | Brain |

### CPP05: Exceptions

| Concept | Description | Projects |
|---------|-------------|----------|
| Try-Catch Blocks | Exception handling | Bureaucrat |
| Custom Exceptions | User-defined exception classes | Form hierarchy |
| Error Propagation | Passing exceptions up the call stack | All exercises |

### CPP06: Casts

| Concept | Description | Projects |
|---------|-------------|----------|
| Static Cast | Compile-time type conversion | ScalarConverter |
| Dynamic Cast | Runtime type checking and conversion | Type exercises |
| Reinterpret Cast | Low-level memory reinterpretation | Cast demonstrations |
| Const Cast | Const modifier manipulation | Various examples |

### CPP07: Templates

| Concept | Description | Projects |
|---------|-------------|----------|
| Function Templates | Generic functions | Swap, Min/Max |
| Class Templates | Generic classes | Array |
| Template Specialization | Custom implementations for types | Various examples |

### CPP08: Templated Containers and Iterators

| Concept | Description | Projects |
|---------|-------------|----------|
| STL Containers | Standard library data structures | Easy Find |
| Iterators | Sequential access to containers | Span |
| Algorithms | Operations on container elements | MutantStack |

### CPP09: STL

| Concept | Description | Projects |
|---------|-------------|----------|
| Advanced Containers | Complex STL usage | BitcoinExchange |
| Algorithms | Standard library algorithms | PmergeMe |
| Functional Programming | Lambdas and functors | RPN |

## Installation and Usage

| Command | Description |
|---------|-------------|
| `cd cpp-modules/cpp0X` | Navigate to module directory |
| `make` | Compile the project |
| `./executable_name [args]` | Run the compiled program |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Recompile the project |

