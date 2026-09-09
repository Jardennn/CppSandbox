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
