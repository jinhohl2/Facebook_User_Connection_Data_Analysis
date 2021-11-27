# CS 225 Data Structure
## Development(jinhohl2-junhong9-beomkic2-minwoo2)
### Graph Implementation:

### Traversal:
We use the property of DFS and BFS that they can only traverse the connected component that the given starting node belongs to. Traversal class executes DFS traversal to traverse the entire connected subgraph including the given startnode and return it as Graph instance. 

### Pagerank:
Team B worked on the Page Rank system. With the Page Rank algorithm, we are able to find a person with most friends. PageRank algorithm was implemented with the adjacency matrix of connected subgraph provided by traversal class. Since we used an adjacency matrix for graph implementation, and found a “connected” subgraph of it using traversal, we decided that our algorithm can be best represented as a discrete Markov chain problem with irreducible probability transition matrix. The page rank algorithm needs multiple iterations of multiplication of vector and matrix. In order to do so, we must get column vectors from the matrix  which requires us to access each row vector and find the nth variables since the 2-d matrix was implemented with row vectors. To avoid having to iterate through double for-loop in each iteration, we decided to transpose the Markov matrix. Then, we save the transposed Markov matrix as a private variable. Afterwards, we define an initial distribution vector which has a size equal to the number of nodes in the connected subgraph. Moreover, each component of the vector must have equal value which sum up to 1. Based on the stationary distribution property of Markov chain, we multiply the transposed Markov matrix to the initial vector until the product has a difference less than epsilon (defined in PageRank.h) compared to the product of previous iteration. This final product vector can be defined as the page rank of all nodes in the connected subgraph. Therefore, we return the index of the vector component that has the highest value.

### Finding Shortest Path (Dijkstra):
Team B focused on developing Dijkstra's algorithm that finds the shortest path. The DFS traversal will mark all the visited nodes from the start node, and it will generate a graph that only contains the start node, because unvisited nodes will be removed. That way, if we run page rank algorithm on the new graph, there will always be a path to the one with the highest pagerank value. The Dijkstra's algorithm process the graph to find the shortest path between the strat node and the most popular guy in the graph. We used priority queues in the shortest path finder function, and in each iteration of the while loop, we updated each vertex's distance from the begining node, and what the previous node was. Then we backtracked the information to get the full shortest path from the beginning node to the end.

### Example Demonstration
Below are images of a simple graph that we used as an example to demonstrate the functionality of our code. The first image is a text file representing the graph edges, and the second image is a visual drawing. It is a disconnected graph with two connected linear components. <br/>

<img width="82" alt="graph_txt" src="https://media.github-dev.cs.illinois.edu/user/11294/files/dce89d00-b0ea-11eb-9904-e530bf480ee7"> <br/>
![graph_drawing](https://media.github-dev.cs.illinois.edu/user/11294/files/dc500680-b0ea-11eb-8264-1ff20572209e) <br/>

Using DFS and findConnectedSubgraph function in Traversal class, we find the subgraph containing the start node. In this execution, since we set the starting node to be 5, the subgraph must contain 0, 1, 2, and 5. <br/>
<img width="351" alt="connected_comp" src="https://media.github-dev.cs.illinois.edu/user/11294/files/dc500680-b0ea-11eb-8827-474b00909845"> <br/>

Then, getHighestRank function in the PageRank class calculates the page rank of all nodes in the subgraph and returns the index of the node with the highest page rank. Here, it is obvious that 0 and 2 have the highest rank. In this project, this node is defined as the "most influential" user identity. <br/>
<img width="344" alt="pagerank" src="https://media.github-dev.cs.illinois.edu/user/11294/files/dce89d00-b0ea-11eb-897d-2338b893406e"> <br/>

Finally, we run findShortestPath in Graph class to find the shortest path from the starting node to the most influential user identity. <br/>
<img width="264" alt="shortest_path" src="https://media.github-dev.cs.illinois.edu/user/11294/files/db1ed980-b0ea-11eb-9d14-458242c9d9c0"> <br/>

Therefore, we achieved the goal that we want to find the most influential user in the online community that I belong to, and find the fastest way to socialize with that personnel.





