# CS 225 Data Structure
## (jinhohl2-junhong9-beomkic2-minwoo2)

## This program finds the most popular person among a friend group, and find a shortest path from start vertex to the most popular one.

### Dependency
 - clang++
 
### location of the dataset (./ is the project root folder)
 - ./facebook_combined.txt
 - ./test/small_graph.txt
 - ./test/large_graph.txt
 
 The dataset should contain information about each edge in each line, separated by new line and there has to be no empty line at the end of the file.
 
### location of the source codes
 - ./include
  include folder contains the header(.h) files of classes uses in this program.
 - ./src
  src folder contains the source(.cpp) files of classes uses in this program.
  
### How to run the program

 1. To make the main executable file, run <br />

```
make main
```
or <br />
```
make
```
in terminal to make the main exe file.

<br /><br />
 2. To run the main exe file, type in
```
./main <data file> <start vertex number>
```
For example, if the dataset is `./data/graph1.txt`, and we want to find the most popular person and the path to him from person `0`, the command line argument should be
```
./main ./data/graph1.txt 0
```
<br /><br />
3. The result will be printed to the console.

The program will print out the post popular person found from Page Rank algorithm and the shortest path found from Dijsktra's algrithm.
<br />
The result will be as follows when we run the program with `./main combined_facebook.txt 0`, which means use the graph in "combined_facebook.txt" and find the shortest path from "person 0" to the most popular person in his friend group.
  
```
Reading data from file.
Done.

Finding connected component that includes 0 with DFS.
Done.

Finding the most influential person among the group.
End node found by PageRank: 3437

Start: 0, The most influential person: 3437
*** Shortest path from 0 to 3437 ***
0 - 107 - 1085 - 3437
```
<br /><br />
4. Test cases
We used catch to test our program.<br />
All the test cases are included in `./test/test.cpp` and you can run all the test cases with typing `make tests && ./tests` in terminal.<br />
  
