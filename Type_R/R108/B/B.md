[Problem link](https://robocontest.uz/tasks/R108B)
#### Problem statement in short
Given two strings a and b.
Check if we can make b only by adding characters to a.

#### Solution
Easy-peasy lemon squeezy.
We solve this problem using two-pointers algorithm.

Edge case: if b is shorter than a, we can never make b out of a by adding characters. (The answer is "NO")

We have pointers i for string b and j for string a
We increment point i and if b[i] == a[j] we increment j as well.

If pointer j reaches the end of string a, that means we encountered every letter of a IN ORDER.
That means the answer is YES.

If j didn't reach the end of string a, the answer is NO.
