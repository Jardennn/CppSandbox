# Basics 

This file is a general notes file for documenting and note keeping for the basics section, this file will be mostly about the `01_basics` folder inside src.

## What will be covered

- [ ] Basics of a language
  - [ ] Output/Input
  - [ ] Loops
  - [ ] Functions
  - [ ] Classes
  - [ ] Conditions

## Notes

### Output

While all code lines use the standard library (imported with `#include <iostream>` at the top of the file) one line is for displaying output.

```cpp
std::cout << "I use NixOS btw" << std::endl;
```

This line will display the text: "I use NixOS btw", for doing that it uses the `cout` function from the standard library (`std`)

`std::endl` is used for ending the line right after the output (what was passed to `cout`) is done printing. This can replace using `return 0;` at the end of the file.

### Variables (objects)

Objects are the middle man between the program and the memory, they hold value and we use the program to retrieve their value rather than retrieving through the memory.

Objects can be either anonymous or defined as `variables`.

The compiler handles data like: how much memory is allocated for the object, where is it stored (RAM or CPU register), will it be relative to other objects, and when would it be deleted or created.

Definition of an object (variable) looks like this:

```cpp
int x;
```

This defines an `integer` (`int`) variable to be named `x`.

At runtime, the object is getting memory allocated for it, defining how many memory it will use and where (RAM or CPU register). Once allocation occurs, the object is created.

Definition of multiple but same data type variables:

```cpp
int a, b;
```

There is another way to define a variable that is using 

```cpp
int x {5};
```

That way will give the same result as other definitions like `int x = 5`, this one is a more modern way introduced in C++11.

Assigning a value to a variable can be used in various ways.

```cpp
// First defining and then assigning a value
int a;
a = 1;

// Assigning a value on initialization
int b = 2; // copy-initialization

int c (3); // direct-initialization

// Modern assign on initialization methods:
int d {4}; // direct-list-initialization

int e {}; // value initialization (similar to the first initialization method)
```

The difference between the older methods and the more modern ones is mainly that the compiler would return an error if a value that the variable cannot safely hold. For example:

`int x {5.5};`

Will return a compiler error/warning because an int variable cannot hold a fraction number (typically, a number that a `double` variable would hold).

`int x = 5.5;`

In that instance, the compiler will just chop the fraction (the characters that are after the dot including it), and will just use the variable as `5`.

Value initialization is also called a zero initialization.

```cpp
int x {};
```

If you would try to use or see what value does `x` hold, (e.g. using `std::cout`) you'll find that this variable is 0. When using value initialization it will initialize the variable to 0.

There is also a way to initialize multiple variables within the same statement.

```cpp
int a = 1, b = 2 // copy-initialization

int c (3), d (4) // direct-initialization

int e {5}, f {6} // direct-list-initialization

int i {}, j {} // value initialization
```

Unused variables (variables that are defined/initialized but never gets referenced in the code) mainly will get treated by the compiler as warnings and if `treat warnings as errors` is enabled it may even fail to compile.

There is an attribute that was introduced in C++17 called `[[maybe_unused]]` that allows the compiler to ignore unused variables completely. 

Example of a traditional unused variable:
```cpp
int x = 4;

return 0;
```

Here the compiler will be likely to notify you that the variable is unused.

Example of `[[maybe_unused]]` being used:
```cpp
[[maybe_unused]] int x = 4;

return 0;
```

And here the compiler wouldn't notify as it was instructed to ignore that unused variable completely.

Additionally, the compiler will get those unused variable out of allocation and optimize them out of the program so there is no performance impact.

`[[maybe_unused]]` Should only be used for variables that have a reason to be have this added to them, although otherwise those variables will just fall under the carpet.

### Additional stuff (Probably a part of input)

```cpp
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::cin.get();
```

These 3 lines of code are supposed to hold the console until a new line is being read.

all 3 of them use the `cin` function from the standard library (showing difference between `cout` that is used for output and `cin` being used for input)

#### Breakdown

```cpp
std::cin.clear()
```

Clears error flags in the input, so if invalid input was entered `clear()` would be responsible to clear those errors for preserving input acceptance.

---

```cpp
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

Clears leftovers characters from the input buffer. This line says to ignore all characters until a new line is entered. `std::numeric_limits<std::streamsize>::max(),` sets the maximum limit of characters to skip, ensuring all buffer of inappropriate characters are discarded.

---

```cpp
std::cin.get();
```

The line that receives input, it pauses to program to read a single character from the user. Until the user presses enter it will freeze the console.
