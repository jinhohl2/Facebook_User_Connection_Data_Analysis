# CS 225 Data Structure
## Development(jinhohl2-junhong9-beomkic2-minwoo2)
### Week 1:
During first week, it was important to decide the final goal of the project. Therefore, all the team members met up and decided the goal of the project.
We not only ended up deciding on the goal and writing Proposal.md, but we also picked/studied methods and algorithms that we are going to use to accomplish the goal. We chose to use the facebook dataset which have the connections between people and our goal was to find the shortest path to the most influential person.
Next time the members met, we wrote initial setup classes required for the project: vertex, graph, edge, make, etc. We decided to use adjacency matrix for the graph.

### Week 2:
After we made component classes needed for our final goal, all the members worked on Depth First Search method which is the first algorithm we are using.
By Utilizing Depth First Search, we could effectively return the connected component of given node. We also started making test files. We decided to use PageRank algorithm and Dijkstra's algorithm to achieve our goal which is to find the most influential person and the shortest path.
During mid-check point, we confirmed our goal and algorithms with the TA.

### Week 3:
In week 3, team B worked on the Page Rank system. With the Page Rank algorithm, we are able to find a person with most friends. PageRank algorithm was implemented with the adjacency matrix provided by the closed graph. Markov's matrix was created and transposed. The PageRank distribution vector was multiplied by matrix.  It was done by while loop and we also created a function to detect whether the vectors are same to detect when to stop the loop. Page Rank algorithm gave the most influential person that we can connect. 

### Week 4:
This week, team A implemented Dijkstra's algorithm and test cases associated with it. In order to utilize Dijkstra's algorithm, we modified the Vertex class structure, and added “distance” and “previous vertex” member variables. And then, we implemented the shortest fast function using Dijkstra’s algorithm (priority queue and updating the distance and previous vertex) that finds the shortest path between a given person and the 'most influential' person found by Page Rank algorithm.

### Week 5:
On the last week, all the team members gathered to write the documents. In specific, the team wrote RESULT.md README.md. We also made slideshows that we need to record the video. In addition, we finished our DEVELOPMENT.md, GOALS.md,  We made sure that everyone has fully understood the code and have completed all the required parts.
