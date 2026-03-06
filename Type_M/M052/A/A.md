[Problem link](https://robocontest.uz/tasks/M052A)
#### Translation
Bicycle Race

In Bitlandia, there are n cities numbered from 1 to n. A bicycle race starts in city 1 and finishes in city 2. There are M one-way roads connecting the cities.

Determine how many different paths exist from city 1 to city 2. If the number of paths is infinite, output inf. If the number is very large, output only the last 9 digits.

There may be multiple roads between the same pair of cities.

#### Solution:
We can just do brute force dfs and call it a day, but we're competitive programmers, meaning that we're supposed to suffer.

This sounds like basic DAG dp, where we just count number of paths, but there is an issue: the graph can be cyclic.
If the graph is cyclic, we can walk in the cycle indefinite amount of times and get out of the cycle and go to the second node.
But there is another issue: we should be able to REACH that cycle and we should be able to reach 2nd node from that cycle.

First we find for each node whether it is useful or no, specifically a node v is useful only and only if:
• There is a path from 1 to v
• There is a path from v to 2

in order to find it we:
• start bfs from 0 and define which nodes are reachable from 1 (if so v1[i] = 1)
• create the inverse of the graph, and find which nodes are reachable from 2 in the inverse graph (if so v2[i] = 1)
the result for each i is:
useful[i] = v1[i] && v2[i]

Nodes 1 and 2 MUST be useful after that, otherwise the answer is 0.

We are going to deal with useful nodes only from now on. (we could get rid of useless nodes actually, but that would be another 50 lines of code)

Next we find: is there a cycle that involves useful nodes?
In order to do that we will just run Cycle-detection dfs on useful nodes.
If so we print "inf"
otherwise, we will do DP on DAG:
We will get indegree array of useful nodes (ignore the useless nodes)
then process the nodes in topological order using Kahn's algorithm

dp[0] = 1 because there is one way to end up in city 1 (0 in 0 indexing): spawn there
if the current node is v, and the target node is to, the transition is:
dp[to]+=dp[v]*c where c is the number of edges between v and to (there can be multiple edges, remember!)

We are also asked to print last 9 digits of the answer if it is too large:
if the answer is 7 we have to print 7
if the answer is 1 000 000 007 we have to print 000 000 007

in order to check for that we will maintain overflow[v] which will be 1 if we need leading zeros
it propagates just like regular DAG DP
in the end we print dp[1] with proper formatting

To the one who made the problem:
Thank you for this brainfuck
