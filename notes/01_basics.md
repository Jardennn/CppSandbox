# Basics 

This file is a general notes file for documenting and note keeping for the basics section, this file will be mostly about the `01_basics` folder inside src.

## What will be covered

- [ ] Basics of a language
  - [x] Output/Input
  - [ ] Variables
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

---

The `<<` operator (**insertion operator**) is used to feed the `std::cout` call data, either from a string, int value or anything.
You can think of that operator and the other similar operator (`>>`) as conveyor belts that pass data to the function in the direction it's pointing at. You can use multiple operators to pass data in spaces (e.g. `std::cout << "Hello" << " world"`), it will first pass "Hello" to the function and then " world" resulting in an output of "Hello world".
You can also think of it as pointing to the function to what data to read/write to. (read from = output, write to = input)

`std::cout` can also be used to output the value of a variable. For example:
```cpp
int x {5};
std::cout << x;
return 0;
```
This will return the value of `x` (5). This also suggests that you can output anything more than strings with `std::cout` (int, double, bool).

`std::endl` was covered pretty lightly earlier in these notes.
This function serves for ending a line and making a new line (like `Console.WriteLine` in C#), it can be used the same as `\n` would be used for.
It is considered best practice to leave an `std::endl` at the end of every output statement to mark the end of the output and start a new line. Example:
```cpp
std::cout << "Hello!" << std::endl;
std::cout << "I'm in a new line" << std::endl;
```

Beside using `std::endl` there is also the option of using `\n`, using `\n` is considered more efficient as it doesn't flush the buffer (slower when having many lines of output) when it's called (`std::endl`), when calling `std::endl` it both flushes the output and starts a new line, `\n` just starts a new line.
`\n` can be called either in the same string as the output (`"Hello\n"`) or as a single character (`'\n'`/`"\n"`).

Output buffer and flushing is handled by adding each output request to the end of the output buffer, the output request is the `std::cout` call in which that every time you chain data together in a request it gets pieced together onto a request and the request is being added to the output buffer.
Flushing is the process of getting the output out to an output device (such as a console), flushing takes each output request from the top of the output buffer down to the last, flushing mostly happens on a specific trigger, such as when an input stream is read, the buffer fills up, the stream is destroyed upon normal exit or a new line is encountered in a line buffered stream (such as calling `std::endl`).



### Input

`std::cin` is another predefined variable in the `iostream` library and I like to call it the brother of `std::cout`.

As guessed `std::cin` is used for input and one way to use it is by making it write data onto a variable. For example:

```cpp
int x {};
std::cin >> x;

std::cout << "Your number: " << x << '\n';
```

What happens in this code snippet is that `x` is being initialized into zero, then on the next `line std::cin` basically takes over the console and awaits user input and after user input was entered it writes that input onto the variable `x`.
Then after input was entered and passed onto `x` (basically assigning `x` with a new value) `std::cout` will print out `"Your number: <x>`. So if the number 5 was entered in the input prompt, the output would be `Your number: 5`.

Just like with `std::cout` where you can pass multiple bits of output on a single line you can also input more than one value on a single line. For example:

```cpp
int x{};
int y{};
std::cin >> x >> y;

std::cout << "Your number(s)" << x << " " << y << '\n';
```
In this example `std::cin` is called on 2 variable which on runtime results that you can input the value of `x` and `y` separated by whitespace, the program will hang on that `std::cin` call just until the two values have been passed.
Then after the values have been passed it will output the text: `Your number(s) <x> <y>`.
So if the input was: `5 2`, the output would be `Your number(s) 5 2`.

Buffering in input has a similar process as output buffering, the characters entered are added to the end of the input buffer whereas the enter key (that is being used to submit the data) is read as `\n`.
Then the extraction operator (`>>`) removed the read data from the front of the input buffer and assigns the read value to the associated variable (via copy assignment).

To demonstrate an example of the input buffer you can use this snippet:
```cpp
int x {};
std::cin >> x;

int y{};
std::cin >> y;

std::cout << "You've entered" << x << " and " << y;
```

On run 1#, if you would enter at the first input prompt the number 6, `6\n` would be entered into the input buffer and the number will be extracted for then that x will have the value of 6.
Then on the second prompt, you would input the number 7 then `7\n` would be entered to the input buffer and the same process that was for the `x` variable will be applied to the variable `y`. After all of the input was processed, the output in this instance would be `"You've entered 6 and 7"`.

On run 2#, if you would've entered both numbers together with a space between them on the first input prompt (like this: `6 7`) then `6 7\n` would be entered to the input buffer, the number 6 will be passed to the variable `x` and because the number 7 is still in the input buffer, there will be no input prompt for the `y` variable and the number will just be passed onto the variable resulting in the output: `You've entered 6 and 7`.

#### Extraction process
- The extraction process will be aborted if `std::cin` is not in a good state (e.g. prior extraction failed and `std::cin` has not been cleared).

- Whitespace and newlines that are in the front of the buffer are discarded from the input buffer, this will also discard an unextracted newline character from a prior line of input.

- If the input buffer is empty on a `std::cin` call, the program will wait for user input and will ignore any leading whitespace from the entered data.

- The extraction operator (`>>`) extracts as many characters as it can until it encounters either an invalid character for the variable it's working on or a newline character that says the input has ended

- When there is whitespace between two values of data entered (e.g. `6 7`) the operator treats that space as a separator that signals the end of a token in stream extraction rather than an invalid character, but the operator does ignore/discard any leading whitespace in the input buffer. Making ` 7\n` remain in the input buffer.

So if the extraction was aborted, no extraction occurred and nothing really happens.

If any characters were extracted correctly, the extraction process has complete and the characters are converted and assigned with copy-assign to the working variable.

If no character could be extracted, the process has failed and the object/variable being worked with is being copy-assigned the value `0`, any future extraction attempts will fail until `std::cin` is cleared (what the first point is talking about)

And any non extracted characters (including newlines) remain available in the input buffer for the next extraction attempt.

Example snippet:
```cpp
int x {};
std::cin >> x;
```
- Scenario 1: Input: `7c`. The input would be added to the buffer, the number 7 will be converted to an integer and assigned to the variable `x`. `c\n` will remain in the buffer for next extraction. 

- Scenario 2: Input: `b`. Then `b\n` will be added to the buffer and the extractor will encounter an invalid character for the working variable, then there will be an extraction failure. The variable `x` will be assigned to `0` and future extraction will fail until `std::cin` (The input stream) is cleared. 

- Scenario 3: No input, if `std::cin` is not in a good state (e.g. the input stream has not been cleared or prior failed extraction) nothing will happen, nothing has happened with the variable `x`. 

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

---

#### Undefined behaviour and uninitialized variables

C++ and C doesn't automatically initialize a value (like zero for int variables being initialized with direct-list-initialization) to most variables (depending on the initialization type)
When a variable that was not initialized is given a memory address, it will contain whatever (garbage data) that memory address contains. When a variable does not have any value to it (was not initialized or assigned anything), it would be called an `uninitialized variable`

The difference between definition, initialization and assignment:
- Definition: Mostly what makes an `uninitialized variable`, it's when you type `int x;` and not putting anything to that variable.

- initialization: When you define a variable and put (initialize) a value to it, when you write `int x = 5` it's called an initialization.

- Assignment: When you put value to a variable that was either uninitialized or initialized. You assign new value into the variable, when you write `x = 5` that is called an assignment.

Lack of initialization is mainly for speed and optimization purposes from the C language when computers were too slow to read too many values from variables and files. Mostly the benefit today is pretty small so you should just initialize your variables, just defining them should be done in optimization purposes and be done selectively.

```cpp
int t;
std::cout << t << '\n';
```

This is an example of an uninitialized variable, the computer assigns unused memory to the variable `t`, and the value residing on that memory is sent to `std::cout` which will print it interpreted as an integer. Every ran the value can change as it is a random memory address each time.

When I try to compile it I get a warning that `t` is uninitialized, when I ran it on the first time I got the value `32766`, the second ran I got `32767`. This is probably because of my limited memory on my laptop, there is not much to play with.

Undefined behaviour (UB) is when you execute code that wasn't well defined in the C++ language, there is no actual rules to the language to what happens when using undefined code.
Running undefined code may cause inconsistency on runtime, crash immediately or later on, program not even run on some compilers, program may work until you change some unrelated code.

The compiler and it's standard library are called an implementation in C++, the language allows the implementation to determine the behaviour of some language aspects, so that a compiler can choose the most efficient behaviour to the platform. 
Behaviour defined by the implementation is called implementation-defined behavior and it must be documented and consistent to the given implementation.

```cpp
std::cout << sizeof(int) << '\n';

return 0;
```

This code prints how many bytes of memory can an int value take, on some platform it will print `2` and on some `4`.

Unspecified behavior is almost identical to implementation-defined behavior, in that the behavior is left to the implementation to define. The implementation is not required to document the behavior.

We want to avoid those behavior (Unspecified and implementation-defined) as they mean the program might not work correctly if compiled on a different compiler or with different settings on the same compiler.

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
