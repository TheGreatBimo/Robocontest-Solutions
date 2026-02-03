[Problem link](https://robocontest.uz/tasks/R080E)
#### Problem statement in short
You are given a 3×3 matrix containing the digits 1, 2, …, 9.

Your task is to transform the matrix into this configuration:
1 2 3
4 5 6
7 8 9
In each move, you can swap any two adjacent numbers (horizontally or vertically).

Determine the minimum number of moves required to achieve the target arrangement

#### Solution

We will use breadth-first-search algorithm to find the number of steps required.
We will store the matrix as 9-digit number, and we store edges of adjacent cells (there will be 12 edges)
See the image in the folder to understand how it works;

We start at the given matrix, and go through the edges to find the distance to permutation "123456789"
If we store 9-digit numbers in the dist[] it will take too much memory, and if we use map or unordered_map it will take too much time.

therefore we optimize how we store the permutation, we use permutation indexing where:
123456789 = 0
123456798 = 1
...
987654321 = 362879

Notice that the indexing gives us permutations in lexicographical order, and the index of the last permutation is exactly 9!-1
This is small enough to store in a vector, but we will have to calculate the permutation's index each time.

In order to calculate it only once, in the queue we store {perm,index} as the index is used for comparisons of distance

Now when it comes to getting the index: it is called factoradic number system.

[Factorial number system (wikipedia)](https://en.wikipedia.org/wiki/Factorial_number_system)

Converting numbers and permutations to factoradic work differently.
Basically: for each number from left to right, we count how many numbers smaller than it we didn't use (let that be unused).
We can do that in O(81)=O(1) time, but if the size of the permutation varies, we might have to use segment tree.

Then we add unused*(8-i)! to the index.

Two examples:
[1,2,3,4,5,6,7,8,9]
| Step | i | p[i] | smalled unused numbers | what's added to id | id |
|------|---|------|------------------------|--------------------|----|
| 1 | 0 | 1 | 0 | 0*8! | 0 |
| 2 | 1 | 2 | 0 | 0*7! | 0 |
| 3 | 2 | 3 | 0 | 0*6! | 0 |
| 4 | 3 | 4 | 0 | 0*5! | 0 |
| 5 | 4 | 5 | 0 | 0*4! | 0 |
| 6 | 5 | 6 | 0 | 0*3! | 0 |
| 7 | 6 | 7 | 0 | 0*2! | 0 |
| 8 | 7 | 8 | 0 | 0*1! | 0 |
| 9 | 8 | 9 | 0 | 0*0! | 0 |
The permutation [1,2,3,4,5,6,7,8,9] has index 0.

[9,8,7,6,5,4,3,2,1]
| Step | i | p[i] | smalled unused numbers | what's added to id | id |
|------|---|------|------------------------|--------------------|----|
| 1 | 0 | 9 | 8 | 8*8! | 322,560 |
| 2 | 1 | 8 | 7 | 7*7! | 357,840 |
| 3 | 2 | 7 | 6 | 6*6! | 362,160 |
| 4 | 3 | 6 | 5 | 5*5! | 362,760 |
| 5 | 4 | 5 | 4 | 4*4! | 362,856 |
| 6 | 5 | 4 | 3 | 3*3! | 362,874 |
| 7 | 6 | 3 | 2 | 2*2! | 362,878 |
| 8 | 7 | 2 | 1 | 1*1! | 362,879 |
| 9 | 8 | 1 | 0 | 0*0! | 362,879 |
The permutation [9,8,7,6,5,4,3,2,1] has index 362,879 (which is exactly 9!-1).

Practice problem for permutation indexing
[Codeforces 501D](https://codeforces.com/contest/501/problem/D)