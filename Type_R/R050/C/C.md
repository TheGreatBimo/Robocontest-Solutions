[Problem link](https://robocontest.uz/tasks/R050C)
#### Translation
Runway #1

A team of builder elves constructed a new runway for Santa. One final task remains: filling the spaces between special rails with tiles.

They have N tiles, each fitting perfectly between the rails. The question is whether it is possible to completely cover a runway of length L using these tiles.

#### Solution
We're being asked: can we make sum L by adding some of the N given numbers.
This is a classic DP problem, we just keep track of all the sums we can get.

We will use bitset shift trick to make it O(N).