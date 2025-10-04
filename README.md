# Slide Generator

A simple C program that converts text files into HTML slides.

## Text Input Format
- No dashes = Header
- Starts with `-` = Bullet point  
- Empty line = New slide

## Output
Generates `slide0001.html`, `slide0002.html`

## Slide Structure
Slide Title

Bullet point one

Bullet point two

Bullet point three

<previous_slide | next_slide>

## Build
### Requirements
- A C compiler
- Any version of C works
- txt file named "slides.txt" (or modify `fopen("slides.txt", "r")` on line 6)

To build this, I am using CMake, if you're using CMake, the text file should be placed inside build folder. If you want to directly run it then placing txt file in same location as c file will work.

### Direct Compilation
```bash
gcc slide_generator.c -o slides
./slides
```
### CMake
Place slides.txt in your build directory, then:

```bash
cmake ..
cmake --build .
./slide_generator
```
