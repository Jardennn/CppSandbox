# Cpp learning sandbox

A personal workspace for exploring C++ concepts, flow control, systems programming patterns and overall low level programming.

I'm using `learncpp.com` as a book/tutorial for learning the language, I may reference chapters for subjects in the goals section.

## Goals 
- [ ] Basics (Syntax, Input and output, statements, loops, functions)
  - [ ] Flow control - variables, functions, operators and standard code flow
  - [ ] Compound types - References and pointers
  - [ ] Project: A dynamic variable manager tool in Console.

- [ ] Memory management and processor architecture
  - [ ] Scope, Duration, and Linkage - Understanding between Stack and Heap
  - [ ] Pointers and Dynamically Allocated Memory - learning deeper about memory and working with pointers
  - [ ] Function pointers - How pointers to functions work
  - [ ] Smart pointers - use of `std::unique_ptr` and `std::shared_ptr`
  - [ ] Project: A program that will create a complex data structure in a Heap and prints the address of those variables in memory.

- [ ] OOP and reverse engineering
  - [ ] Classes and Object-Oriented Programming - Encapsulation concepts
  - [ ] Inheritance and Polymorphism - How inheritance works between classes and V-table (how the compiler show virtual functions in memory)
  - [ ] Vectors and Standard Template Library (STL) - Work with integrated data structures (`std::vector`, `std::map`)
  - [ ] Project: integrating a physics and logic part in a video game, not really decided yet. Modern work with classes, inheritance and safe memory management

- [ ] WinAPI and Memory Injection
  - [ ] Windows Syscalls / WinAPI - How the program requests access from the OS to another program
  - [ ] Specific functions in Windows
    - [ ] `OpenProcess` - Getting access to the process of a program
    - [ ] `ReadProcessMemory` / `WriteProcessMemory` - Read and writing in memory
    - [ ] `VirtualAllocEx` - Base for DLL injection, memory setting inside another process
  - [ ] Project: SinglePlayer Video game cheats - An external cheating program that finds the game PID, scans its memory, finds the pointer for useful information (e.g. health, ammo) and changes in real time those pointers with WinAPI.

## Structure

```
CppSandbox/
|
|---README.md - this file you're reading now.
|---CMakeLists.txt - Main build configuration (currently empty)
|---notes/ - General notes and study material, all file names are supposed to point to their folder of sandbox (inside src/)
|---src/ - Code exercises and experiments
     |---01_basics/ - Topic subfolder with codes and topic specific notes
```


