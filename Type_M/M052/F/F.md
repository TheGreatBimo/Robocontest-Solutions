[Problem link](https://robocontest.uz/tasks/M052F)
#### Problem statement in short
Given an HxW grid.
Need to find the rectangle with largest perimeter, consisting of only '.' characters.

#### Solution:
To solve the problem we first need to solve a subproblem: find the rectangle with the largest perimeter in a histogram.
It uses a solution similar to the one for finding the rectangle with the largest area in a histogram, but instead of calculating the area, we calculate the perimeter.

[Histogram with largest area (leetcode)](https://leetcode.com/problems/largest-rectangle-in-histogram/)

For each i we maintain arrays left and right, where left[i] is the index of the nearest bar to the left of i that is shorter than the bar at i, and right[i] is the index of the nearest bar to the right of i that is shorter than the bar at i. We can calculate these arrays using a monotonic stack in O(n) time.

[More on monotonic stack (geeksforgeeks)](https://www.geeksforgeeks.org/dsa/introduction-to-monotonic-stack-2/)

For each bar at index i, the width of the rectangle that can be formed with height equal to the height of the bar at i is right[i] - left[i] - 1. The perimeter of this rectangle is 2 * (height[i] + width). We can iterate through all bars and calculate the maximum perimeter.

In case height[i] == 0, we can simply continue, otherwise it would give 2*(0 + width) = 2*width, which is not correct since the height of the rectangle would be zero. (sneaky edge case)

We solved the subproblem, but we still need to get the histogram for each row of the grid.

When entering the grid, we maintain a histogram of heights for each column. For each row, we update the histogram based on whether the current cell is '.' or not. If it is '.', we increment the height of that column; if it is not, we reset the height to zero.

After each row we calculate the largest perimeter rectangle for that row.

And we subtract 1 from the final answer, because the problem wanted to add burden for the solver.

Time complexity: O(H*W)
Space complexity: O(W) for the histogram and the left and right arrays (+ we can only store one row of the grid at a time).

Recommended problem to solve:
[Maximal rectangle in a binary matrix (leetcode)](https://leetcode.com/problems/maximal-rectangle/)