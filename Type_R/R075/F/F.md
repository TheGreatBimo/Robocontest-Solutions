[Problem link](https://robocontest.uz/tasks/R075F)
#### Translation
Crazy Monster Game #1

Azimjon likes to play the Crazy Monster Game. In this game, he must fight n monsters arranged in a line.

To win, he first needs to calculate each monster’s total power.

The i-th monster has a base power c[i], and its total power is defined as the sum of powers of monsters within distance r from it.

Your task is to determine the total power for each monster.

#### Solution
Easy-peasy lemon squeezy.
we calculate prefix sums and find sum of [i-r,i+r] for each i, while handling out of bounds cases.