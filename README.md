# Travelling salesman
Compare the precise solution of Travelling salesman's problem and the solution which uses the minimum spanning tree.

**Plan**:  
1) Generate normal distribution of points using Box-Muller transform.
2) Find the way using MST.
3) Find the shortest way with recursive algorithm.
4) Compare the ways' lengths

**Results**:  
n is number of towns(vertices in the graph).  
The first column is the ratio of the shortest path length to the one found using MST.  
The second number is standard deviation.

n = 4 : 1	        (0)  
n = 5 : 0.961545	(0.0503306)  
n = 6 : 0.90562	  (0.0683352)  
n = 7 : 0.910749	(0.0545197)  
n = 8 : 0.858915	(0.018681)  
n = 9 : 0.889024	(0.0506872)  
n = 10 : 0.842636	(0.0481151)  
