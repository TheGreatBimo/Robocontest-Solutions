[Problem link](https://robocontest.uz/tasks/R017E)
#### Translation
Barns

Mirzakarimboyvachcha has n barns, each located at coordinate xᵢ on the number line.

He wants to gather his livestock at a single point, but since he doesn’t want to travel much, he wants to choose a point such that the sum of distances from all barns to that point is minimized.

In other words, find a point k that minimizes the total distance to all xᵢ. If multiple such points exist, choose the smallest one.
#### Solution
Say we have chose the point x. Think about what happens when we move this point to right by 1:
x becomes 1 unit closer to all the points to the right (thus the total distance will decrease by that number)
x becomes 1 unit further from all the points to the left (thus the total distabce will increase by that number)

so moving x right is only beneficial when there are more points on the right, than on the left.
and when this condition is broken, we will probably end up equal number of points on the left and on the right.

That would be the median of all our points.
If N is odd: we just choose the median
if N is even: we will choose the left of the middle two elements. The total distance would be the same if we chose the right one, but the problem asks us to find the smallest one,