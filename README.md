# Slide Generator

A simple C program that converts text files into HTML slides.

## Text Input Format
### For Intro Page Text FORMAT
    Title:`<single space>`Presentation Title<br>
    Presenter:`<single space>`Presenters Name<br>
    Email:`<single space>`email<br>
    Date:`<single space>`Date of Presentation<br>
### Rest of the slides
- No dashes = Header
- Starts with `-` = Bullet point + `<single space>` after the hyphen(`-`)
- Empty line = New slide
- checkout sample [slides.txt](slides.txt) file as an example
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
- txt file named "slides.txt" (or modify `fopen("slides.txt", "w")` on line 5)

To build this, I am using CMake, if you're using CMake, the text file should be placed inside build folder. If you want to directly run it then placing txt file in same location as c file will work.

### Direct Compilation
```bash
gcc slide_gen.c -o slides
./slides
```
### CMake
Place slides.txt in your build directory, then:

```bash
mkdir build
cd build
cmake ..
cmake --build .
./slide_generator
```
## Screenshots of slides
[Title Slide](examples/intro_slide.jpg)<br>
[Title Slide](examples/normal_slides.jpg)