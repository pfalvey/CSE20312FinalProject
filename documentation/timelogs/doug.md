##  Project Time Log
### Doug Smith

Wed, Mar 15 2017

11:30P-12:30A  Began comparative research for Boost library. 
    It seems like it implements all of the algorithms that we could want for traversing a graph and comparing edge weights.
    The syntax for graph construction also seems fairly logical given that we have a list of the nodes and distances between them would need to be calculated seperately.
    I don't know if we could build a better version, so I'm going to focus on a sample implementation using Boost.



Fri, Mar 17 2017

3:30P - 6:30P  Getting a boost graph implementation sorted out
    Boost installed no problem, but I might have some trouble getting a generalized installer working for everyone else... solution: post-break pair-coding!
    Lost a lot of time pouring over boost docs... everything is recorded but I found the code samples sparse and unhelpful.
    Was able to get a graph_test running where boost is used to creat an undirected graph with weighted edges, which seems ideal for mapping points by relative distances.
    Also started building a Graph class, which will be a wrapper for all the boost code (I find it a little verbose to interact with, so I'm seperating from future algorithms).
    The class and its test driver are still basic, but they're enough to get us started on boost interactions and extending a shared syntax for graph work.



Mon, Mar 20

5:30 - 6:30P Further refined interface, looked into solutions for Boost dependency on student machines (for submission)



Sun, Mar 26

3:00 - 4:00P Added insert/access functions to boost wrapper



4/4/2017
Time: 9:10pm-11:00pm
Content:
  Further refined our A* algorithm that we will use to solve paths.
  Talked about how to reduce redundancy in paths and optimization of our paths.
  Decided to use a map on the backend to store all of our nodes.



4/12/17
Time: 5:00pm - 6:45

Finalized graph implementation - replace Boost with custom implementation



4/16/17
Time: 3:30 - 5:00P
Implemented new graph node storage with access function



4/18/17
Time: 9:00pm - 10:00
Worked on progress report.
Reorganized repository



4/20/17
Time: 6:00 - 8:00
Refactored edge storage
Added general template for distance definition


4/25/17
Time: 5:15 - 8:15
Added function for reading locations.txt file into graph



4/27/17
Time: 6:00 - 7:00
Read in edges.txt file for the graph builder instead
Added error-checking for graph access



5/1/17
Time: 5:15 - 6:15
Refactoring of A* Algorithm





Cumulative: 18:15 hr.




