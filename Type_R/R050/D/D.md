[Problem link](https://robocontest.uz/tasks/R050D)
#### Translation
Runway #2

A team of builder elves constructed a new runway for Santa. One final task remains: filling the spaces between special rails with tiles.

They have N tiles, each fitting perfectly between the rails. The question is whether it is possible to completely cover a runway of length L using these tiles.

#### Solution
We're being asked: can we make sum L by adding some of the N given numbers.
But this time we're also asked which numbers can we use.
Again, we just keep track of all the sums we can get.
But we will also keep track of which numbers were used.

We can't use bitset shift trick so it will be O(N^2) and constraints allow us to do that.