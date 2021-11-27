# CS 225 Data Structures
## Proposal (jinhohl2-junhong9-beomkic2-minwoo2)

### Leading Question 
Our goal for the final project is to find the person who has most the influence and way to get close to the influencer. Given Facebook friend dataset and a code base, we can find out the amount of influence a person have and find fastest path to be ‘friends’ with the influencer. We decided to use Google’s page rank algorithm to calculate the amount of influence a person have.  Then, we will find shortest path using Dijkstra’s algorithm. Our ‘successful’ project will be able to update the influencer and the path every time we get different data set. 

### Dataset Acquisition and Processing
Our dataset is "Social circles: Facebook" and it contains two columns of numbers.  Each row of the dataset shows each connection between people. For example, if a and b are connected as friends, a b is saved in a row. Facebook’s friend edge is undirected graph meaning that if a is friend of b then b is also friend of a. Therefore, if a b is in the dataset, it also implies that b is connected to a. This data will be downloaded from http://snap.stanford.edu/  in txt file. Using this dataset, we will find out whom the most popular person is and the fastest path to connect to the person. However, since this data is real world data we can have conflicts such as data including several closed graphs if people in facebook don’t actively add friends to each other. Therefore, we would address this buy stating our goal to find the most popular person that we can possibly connect and find the path. 

### Graph Algorithms
1. Depth First Search

"Social circles: Facebook" dataset consists of multiple disconnected componentes. However, we are primarily intersted in only the nodes that are connected to the starting node because it is not possible to find a path between two disconnected nodes. Therefore, we will use DFS traversal algorithm to distinguish the component that the starting node belongs to from the entire dataset. We will only use those nodes in the following stages of this project, and disregard the nodes that are not connected to the starting node. The input will be the entire graph, and this function will output the component that includes the given node. Time complexity of this algorithm is O(n).


2. Page Rank

Page rank is a link analysis algorithm where is measures the importance of a node by assigning numerical value to each element of a hyperlinked set. While we count the incoming lniks, we normalize the number of linkes connected to that node. As this algorithm is utilized in Google search engine to roughly estimate how "important" such page is, we will be able to inplement this algorithm to determine the most "influential" user ID of the Facebook social network. The input will be the component found by applying DFS, and this function will output the most "influential" user ID. Time complexity of this algorithm is O(k * n) where k is the number iteration.


3. Dijikstra Algorithm

Dijikstra Algorithm is a shortest-path finding algorithm used in dynamic programming. Once we identify the most important user ID in the Facebook social network, we will integrate the Dijikstra algorithm to reach from a certain ID to the identified most influential ID. This will define the most efficient route of users for us to contact in the real world to reach certain target. The input will be the component found by applying DFS, the starting node, and the end node (most influential user), and this function will output the shortest path between two nodes. Time complexity of this algorithm is O(b^(1+C/e)) where b is the max number of neighbors of a node, C is the length of the shortest path, and e is the cost for each edge.



### Timeline

We divided our team into 2 sub-teams of 2 people: Team A and Team B

Team A and Team B will collaborate and write the initial setup codes together (Node class, file input, and output, etc) that will be used for DFS traversal algorithm, Dijkstra’s algorithm, and Page Rank algorithm by April 12th.

Team A and Team B will also work together to implement a function that returns the connected components of the given node utilizing DFS traversal algorithm by April 18th.

Team A will write the basic implementation of and test cases for the Page Rank algorithm that finds the person with the largest number of hyperlinks connected to him by April 25th.

Team B will write the basic implementation of and test cases for Dijkstra's algorithm that finds the shortest path between a given person and the person with the largest number of friends found by applying Page Rank algorithm by April 25th.

After the Mid-Project Checkin, Team A and Team B will discuss the current progress and readjust the project goal if needed. 

Team A will elaborate on and develop the Page Rank algorithm that finds the person with the largest number of hyperlinks connected to him by May 2nd.

Team B will elaborate on and develop Dijkstra's algorithm that finds the shortest path between a given person and the person with the largest number of friends found by applying Page Rank algorithm by May 2nd.

From May 3rd to the Final Project deadline, we will wrap up our codes, put all the pieces together, and make sure the code runs and passes all the test cases without any error.


