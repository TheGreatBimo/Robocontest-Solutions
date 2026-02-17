[Problem link](https://robocontest.uz/tasks/R072I)
#### Translation
We're given an array of size n and we're asked to find the number of continuous subarrays with sum equal to 0.

#### Solution
We just count number of prexises with sum x as ct[x], whenever we achieve some sum y we add ct[y] to the result.