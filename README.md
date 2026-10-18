# C++ Module 02 — Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form

A fixed-point number class in C++, built step by step: canonical form, conversions, and full operator overloading.

*This project was created as part of the 42 curriculum by jpflegha.*

## Exercises

| Exercise | What it adds |
|:---|:---|
| `ex00` | `Fixed` class in **Orthodox Canonical Form**: default constructor, copy constructor, copy assignment operator, destructor, `getRawBits` / `setRawBits`. |
| `ex01` | Constructors from `int` and `float`, `toFloat()`, `toInt()` and `operator<<` for printing. |
| `ex02` | Comparison operators (`> < >= <= == !=`), arithmetic (`+ - * /`), pre/post increment and decrement, and static `min` / `max` (const and non-const). |

The number is stored as an `int` with **8 fractional bits**, so the smallest step is 1/256 = 0.00390625.

## Key concepts

- Orthodox Canonical Form (rule of three)
- Fixed-point representation with bit shifts and rounding (`roundf`)
- Operator overloading (member and non-member), stream insertion operator
- Pre- vs. post-increment semantics, function overloading for const objects

## Build and run

```bash
git clone https://github.com/jpfleghaar/CPP02.git
cd CPP02/ex02 && make && ./Fixed
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

Each exercise has its own Makefile (`c++ -Wall -Wextra -Werror -std=c++17`); the program is called `Fixed` in every exercise.

## Project structure

```
ex00/  Fixed.{hpp,cpp}, main.cpp
ex01/  Fixed.{hpp,cpp}, main.cpp
ex02/  Fixed.{hpp,cpp}, main.cpp
```

## What I learned

- Why every class that manages its data should define (or deliberately use) the four canonical functions.
- How fixed-point numbers trade range for exact, predictable precision compared to floats.
- How to overload operators so a custom type feels like a built-in one, and why post-increment returns a copy.
