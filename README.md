# 372-Project-2
CPS to PostScript translator

Our program is used on the command line compiled using a makefile.

Makefile commands:
- all: compiles both PS_Translator.out and tests.out
- tests-run: compiles tests.out and runs tests.out
- run: compiles PS_Translator.out and runs PS_Translator.out
- clean: removes all object files and out files

Recommended command: ``` make -j8 ```
  
To create a postscript file: Create a vector holding all the shapes that are desired
Possible shapes are:
1. Simple
   - Circle
   - Triangle
   - Rectangle
   - Polygons with uniform sides
2. Complex - Compositions of shapes
   - Horizontal
   - Vertical 
   - Layered
3. Unique - Non-standard shapes
   - Circle with arcs
