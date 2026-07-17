# Student Grader

Simple **C++** project to practice **OOP**.

## Features

- Read students information
- Calculate total and average
- Assign grade
- Rank by grade
- Print results and output as json file

## TODOs

- [x] Read file
- [x] Calculate total and average
- [x] Grade
- [ ] Print in table style
- [ ] Sort
- [ ] Output JSON
- [ ] Refactor
- [ ] Draw flow chart

---

## Compile and Run

```sh
mkdir -p build

g++ ./src/main.cpp -o ./build/main

./build/main
```

---

## Makefile

[Makefile Tutorial](https://makefiletutorial.com/)

After making changes to source codes.

```sh
make

./build/main
```

---

## Clang Format

[Clang LLVM Documentation](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)

### LLVM Style

The default Clang Format style, using standard **C++** formatting conventions.

- 2-space indent
- 80 character line width

### Space Indent

Represents indent uniformly across all code blocks while `Tab` sometimes don't.
