# MovieRatingsRanking
Dan Le

CMPSC 24

PA02 Report

Part 1: Searching

Code for search()

Dataset Number of runs
(W)
Minimum Time
(micro seconds)
Maximum time
(micro seconds)
Average
(micro seconds)
20 Ordered 50 54 91 62.
20 Random 50 39 100 45.
100 Ordered 50 3989 4988 4647.
100 Random 50 963 1996 1157.
1000 Ordered 50 424384 451794 428647.
1000 Random 50 14959 15481 14353.
Analysis of Searching in a BST

The ordered datasets take a longer time to searchthan the random datasets, especially for 1000
inputs. The 1000 ordered took around 100 times longerto run than the 100 ordered, while the
1000 random only took around 10 times longer to runthan the 100 random.

I expected that the ordered datasets would take longerto search for a specific movie. The worst
case scenario for the ordered datasets is when themovie being searched for is the most recent
insertion into the binary search tree. Every nodewould need to be visited, making search() very
inefficient in this case. For smaller binary searchtrees, this would not be much of an issue.
However, for big datasets, this would not be a veryefficient way to search.

The worst case scenario is better for random cases. When searching in a random dataset, the root
node would initially be compared to the movie beingsearched for. Then search() would either
return true if the root was the target movie or recursivelytraverse down the left or right subtree
of the root. This means that not every node wouldneed to be visited. The worst case scenario is
when the target movie is at the lowest depth of thebinary search tree. Unlike the ordered case,
the lowest depth in the random datasets can containmore than one node. Searching would thus
be more efficient, and the total runtime would notincrease as much for bigger datasets.

Part 2: Inserting

Scatter Plots of Ordered vs Random for 1000 movies

The number of nodes in the binary tree before insertinga new node (N) was the same as the
number of nodes visited before inserting a new node(N_Visited) for ordered input.
The number of nodes visited before insertion graduallyincreased as the number of nodes in the
binary search tree before inserting a new node (N)increased from 0 to 1000 for random input.
Code for Insert() function

Big O Analysis for the insert() function

The insert() function uses recursion in order to inserta node into the binary search tree.
For the ordered case, there would be no left childrenbecause every node inserted would simply
be the right child of the node before it. However,this would mean that every node in the binary
search tree would have to be visited until a nodewith no right child is found, which is the end of
the tree. The runtime complexity for this implementationin the ordered case is O(N), where N is
the number of nodes in the tree before insertion.

For the random case, the insert() function has a betterruntime than for the ordered case.
Left children would have to be considered in thiscase as well. Each node’s information would
be compared to the information to be inserted. Traversedown the tree until there is an available
spot for the node to be inserted, and insert the nodeinto that spot. Not every node in the tree
would have to be visited, but the worst case is whenthe function would need to traverse to the
lowest level of the tree to insert the new node. Thus, the runtime complexity for the random case
would be O(log(N)).

The scatter plots also support the big Os for theinsert function. For the ordered case, the
scatter plot is a straight line where the N is thesame as N_Visited, so the big O would also be
O(N). For the random case, N_Visited continues toincrease at a decreasing rate as N increases,
meaning that its big O would be O(log(N)).
