# How to compile ?

if you want to compile this code just open command promt in this directory and type "mingw32-make" or "make"
if all "mingw32-make" and "make" not work use this command 
g++ -o main src/*.cpp src/sortSource/*.cpp -I ./include/ -I ./include/sortHeader 

# Algorithm Mode
Run a sorting algorithm on user-provided data

Prototype: [Execution file] -a [Algorithm] [Input filename] [Output parameter(s)]
Example: a.exe -a radix-sort input.txt -both
Run a sorting algorithm on the data generated automatically with specified size and order

Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
Example: a.exe -a selection-sort 50 -rand -time
Run a sorting algorithm on ALL data arrangements of a specified size

Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
Example: a.exe -a quick-sort 70000 -comp

# Comparison Mode
Run two sorting algorithms on user-provided data

Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input filename]
Example: a.exe -c heap-sort merge-sort input.txt
Run two sorting algorithms on the data generated automatically with specified size and order

Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
Example: a.exe -c quick-sort merge-sort 100000 -nsorted

# Input Arguments
Mode:

-a: Algorithm mode
-c: Comparison mode
Algorithm name: Lowercase, words are connected by hyphens (e.g., selection-sort, heap-sort).

Input size: Integer (≤ 1,000,000).

Input order:

-rand: Randomized data
-nsorted: Nearly sorted data
-sorted: Sorted data
-rev: Reverse sorted data
Given input (file): Path to the input file. The file format is as follows:

1st line: an integer n, indicating the number of elements in the input data.
2nd line: n integers, separated by a single space.
Output parameters:

-time: Algorithm’s running time
-comp: Number of comparisons
-both: Both running time and number of comparisons
These prototypes will help you set up your commands to run the specified sorting algorithms and compare their performance based on the given input data or automatically generated data.