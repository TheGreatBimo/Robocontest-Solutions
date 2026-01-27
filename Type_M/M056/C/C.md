[Problem link](https://robocontest.uz/tasks/M056C)
#### Translation:
The country Rectangulariston is rectangular, represented as an H × W grid of districts. Each district at row i, column j has a height A[i, j] above sea level.

The president wants to make a big change: he chooses a column k (1 ≤ k < W) and builds a river between columns k and k+1.

After that, districts are considered connected if they are adjacent (share a side), have the same height, and are not separated by the newly built river.

Determine the minimum number of connected districts possible after the president executes his plan.

#### Solution:
We have to chose such column x, so that if we divide the grid into two parts (A and B) on that column,
number of components in A + number of components in B should be minimal.

In order to find that minimum value we will find the number of components in each suffix and each prefix.
result = min over all splits (pref[i] + suf[i+1])

In order to find the number of components in all prefixes we will use DSU
(since 2D DSU takes too much memory, we will compress our 2d grid to 1d, and each coordinate will correspond to y*w+x)

We will process each column and connect it to previous column, and our DSU will let us know the total number of components.

Same done for suffixes.