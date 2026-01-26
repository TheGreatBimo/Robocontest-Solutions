[Problem link](https://robocontest.uz/tasks/R001E)

#### Translation
A number is "wonderful" when it is divisible by the square of the sum of its numbers.
e.g 162 is a "wonderful" number because
1+6+2=9
9*9=81
and 162 IS divisible by 81

#### Solution
As we can see the input limit is quite low (N <= 30000)
So we can use Brute Force solution:
We will check whether a number is wonderful and do so until we find the N-th one.
Checking is O(logN)
total complexity is O(RlogN) where R is the resulting number