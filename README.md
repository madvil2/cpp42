# C++ Modules (42 School)

This repository contains solutions for the C++ modules from 42 School curriculum, covering fundamental to advanced C++ programming concepts.

## 📚 Project Overview

The C++ modules are designed to teach modern C++ programming from the ground up, starting with basic syntax and progressing to advanced topics like templates, STL containers, and algorithms.

## 🗂️ Module Structure

### Module 00 - Basics
- **ex00**: Megaphone - Basic string manipulation and output
- **ex01**: PhoneBook - Introduction to classes, objects, and basic I/O
- **ex02**: Account - Working with static members and file I/O

### Module 01 - Memory Management
- **ex00**: BraiiiiiiinnnzzzZ - Stack vs Heap allocation
- **ex01**: Moar brainz! - Dynamic memory allocation with arrays
- **ex02**: HI THIS IS BRAIN - References and pointers
- **ex03**: Unnecessary violence - Object composition and references
- **ex04**: Sed is for losers - File manipulation and string replacement
- **ex05**: Harl 2.0 - Switch statements and member function pointers

### Module 02 - Ad-hoc Polymorphism
- **ex00**: Fixed Point Numbers - Orthodox Canonical Class Form
- **ex01**: Towards a more useful fixed-point number class - Constructors and conversions
- **ex02**: Now we're talking - Operator overloading

### Module 03 - Inheritance
- **ex00**: ClapTrap - Basic class implementation
- **ex01**: ScavTrap - Single inheritance
- **ex02**: FragTrap - Multiple inheritance concepts

### Module 04 - Subtype Polymorphism
- **ex00**: Polymorphism - Virtual functions and abstract classes
- **ex01**: I don't want to set the world on fire - Deep copy and memory management
- **ex02**: Abstract class - Pure virtual functions

### Module 05 - Exceptions
- **ex00**: Bureaucrat - Exception handling basics
- **ex01**: Form up, maggots! - Custom exceptions
- **ex02**: No, you need form 28B, not 28C... - Abstract classes with exceptions
- **ex03**: At least this beats coffee-making - Factory pattern

### Module 06 - C++ Casts
- **ex00**: Conversion of scalar types - Static cast and type conversion
- **ex01**: Serialization - Reinterpret cast
- **ex02**: Identify real type - Dynamic cast and RTTI

### Module 07 - C++ Templates
- **ex00**: Start with a few functions - Function templates
- **ex01**: Iter - Template functions with iterators
- **ex02**: Array - Class templates

### Module 08 - Templated Containers
- **ex00**: Easy find - STL algorithms
- **ex01**: Span - Custom container implementation
- **ex02**: Mutated abomination - Advanced STL usage

### Module 09 - STL
- **ex00**: Bitcoin Exchange - File parsing and STL containers
- **ex01**: Reverse Polish Notation - Stack implementation
- **ex02**: PmergeMe - Advanced sorting algorithms

## 🛠️ Compilation

Each exercise includes a Makefile for compilation. To build any exercise:

```bash
cd module0X/exXX
make
```

### Compilation Flags
All projects are compiled with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## 🚀 Usage Examples

### Module 00 - PhoneBook
```bash
cd module00/ex01
make
./phonebook
# Commands: ADD, SEARCH, EXIT
```

### Module 01 - Zombie
```bash
cd module01/ex00
make
./zombie
```

### Module 09 - RPN Calculator
```bash
cd module09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## 📋 Key Learning Objectives

- **Memory Management**: Understanding stack vs heap, RAII principles
- **Object-Oriented Programming**: Classes, inheritance, polymorphism
- **Exception Handling**: Try-catch blocks, custom exceptions
- **Templates**: Generic programming, template specialization
- **STL**: Standard Template Library containers and algorithms
- **C++98 Standard**: Working within older C++ standards

## 🔧 Requirements

- C++ compiler supporting C++98 standard (g++, clang++)
- Make utility
- Unix-like operating system (Linux, macOS)

## 📝 Coding Standards

This project follows 42 School coding standards:
- No comments in code
- Orthodox Canonical Class Form for classes
- Proper memory management (no leaks)
- Exception safety
- Const correctness

## 🎯 Skills Developed

- Low-level memory management
- Object-oriented design patterns
- Template metaprogramming
- STL proficiency
- Exception-safe programming
- Performance optimization

## 🤝 Contributing

This repository contains educational solutions. While contributions are welcome for improvements or bug fixes, please ensure they maintain the educational value and follow 42 School guidelines.

## 📄 License

This project is part of 42 School curriculum. Please respect academic integrity policies when using this code.

---

*Made with ❤️ at 42 School*