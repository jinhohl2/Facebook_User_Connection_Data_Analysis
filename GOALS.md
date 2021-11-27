# CS 225 Data Structure
## Goals(jinhol2-junhong9-beomkic2-minwoo2)

### Data sets:
The data set we used for the final project is from Stanford Large Network Dataset Collection. 
Stanford Large Network Dataset Collection is a large repo group data sets in a very general format and the link is here: http://snap.stanford.edu/data/.
Among many data sets, we chose to use a data set called "Social circles: Facebook". 
This data set can be downloaded through: http://snap.stanford.edu/data/ego-Facebook.html.
Facebook dataset concists of friend lits from Facebook. Each integer number represents different people.
Through our graph class, we make each person a node and the friend relationship as an edge.
Then, the program will find shortest path towards the most influensive person based on the Page Rank system.

### Algorithms:
Among lots of algorithms we learned and plenty of uncovered options, we chose the following algorithms to accomplish our final goal: 
Depth First Seach, Dijkstra's Algorithm, and Page Rank Algorithm. First, we chose Depth First Seach, because
"Social circles: Facebook" dataset is not a connected graph. It has several disconnected graphs.
With Deph First Search, we can draw out graph that contains the given node. 
For the function DFS, we give a graph for the input. Even though it's a void function, it finds out which vertices are visited. 
We were able to find connected graph by using DFS function. 
Second, we chose Page Rank algorithm, because we wanted to learn one of the most famous algorithm so that we can apply knowledge in a current event.
Page rank is a link analysis algorithm where is measures the importance of a node by assigning numerical value to each element of a hyperlinked set. 
While we count the incoming links, we normalize the number of linkes connected to that node. 
For Page Rank function, we don't need any input. However, after the function runs, it will return a constant reference to a string with the number of 'most influence person'.
Lastly, we chose Dijkstra Algorithm, because all of us were more familiar with Dijkstra than others.
With this function, we can efficiently find a shortest path to the person in goal. In find shortest path function, we give two constant reference to strings: one for source, and one for destination.
After the code is ran, the function returns the vectors of vertices that are between the source node and the destination node. 

### Final Delieverable:
To show that our code is working, we will run the following functions. As we input a 'person' in our main, DFS function will run and find the 'friend group' that person is in. Then, our Page-Rank Algorithm will find the 'most influential person' within the friend group. Lastly, our Shortest Path function will print out 'people' that has to be connected in order to be connected to the most influential person. We can not only run the functions above in main.cpp. We also have test cases for every functinos.

### Timeline:
We divided our team into 2 sub-teams of 2 people: Team A and Team B

Team A and Team B will collaborate and write the initial setup codes together (Node class, file input, and output, etc) that will be used for DFS traversal algorithm, Dijkstra’s algorithm, and Page Rank algorithm by April 12th.

Team A and Team B will also work together to implement a function that returns the connected components of the given node utilizing DFS traversal algorithm by April 18th.

Team A will write the basic implementation of and test cases for the Page Rank algorithm that finds the person with the largest number of hyperlinks connected to him by April 25th.

Team B will write the basic implementation of and test cases for Dijkstra's algorithm that finds the shortest path between a given person and the person with the largest number of friends found by applying Page Rank algorithm by April 25th.

After the Mid-Project Checkin, Team A and Team B will discuss the current progress and readjust the project goal if needed.

Team A will elaborate on and develop the Page Rank algorithm that finds the person with the largest number of hyperlinks connected to him by May 2nd.

Team B will elaborate on and develop Dijkstra's algorithm that finds the shortest path between a given person and the person with the largest number of friends found by applying Page Rank algorithm by May 2nd.

From May 3rd to the Final Project deadline, we will wrap up our codes, put all the pieces together, and make sure the code runs and passes all the test cases without any error.
