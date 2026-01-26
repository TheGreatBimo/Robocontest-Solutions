[Problem link](https://robocontest.uz/tasks/M046E)
#### Translation
You are given a permutation P of numbers from 1 to N, and M pairs of the form (x, y). You can swap the values at positions Px and Py as many times as you like.

A number in the permutation is considered “in place” if it equals its index (indexing starts from 1).

Determine the maximum number of elements that can be placed “in place” after performing any allowed swaps.

#### Solution
Let the pairs (x,y) represent an edge in a graph, it can be proven that any connected components can be sorted.

We will create a DSU based on these M pairs.
Then for each item in permutation we will check if the item can be placed in its proper place.
To do that we will check if item's current index and item's proper index belong to same component.