[Problem link](https://robocontest.uz/tasks/M043D)
#### Translation
Center of Mass of a Number

You are given a number n. You need to find its center of mass, defined as a number x such that the sum of numbers from 1 to x equals the sum of numbers from x to n.

If no such number exists, output -1.

#### Solution
Notice if a number x has a center of mass y that means:
(1+2+..+y) == (y+(y+1)+...6+x)
the right hand side can be expressed as (1+2+3+...+x) - (1+2+3+...+y-1)
if we express sum from 1 to n just as sum(n)
then the equality holds:
sum(y) = sum(x)-sum(y-1)

we have sum(x) thanks to the formula x*(x+1)/2
so we just have to find such y where:
sum(y)+sum(y-1) == sum(x)

we will just do brute force on that as the constraints allow us to do that.
IF the constraints were higher, we would be able to do a binary search, achieving the solution in O(logN) time.
But there's no need for that.