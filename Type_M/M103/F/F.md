[Problem link](https://robocontest.uz/tasks/M103F)
#### Translation:
Bilmasvoy

Bilmasvoy is interested in similar numbers. He considers two numbers a and b similar if exactly one digit differs by 1, and all other digits are the same.

For example, 1903 is similar to 1803, 1913, 1902, 1904, and 2903.

Given a number, determine how many numbers are similar to it.
#### Solution:
Easy-peasy lemon squeezy.
For each digit we just count in how many ways can this be replaced and add the count to the result.

Most digits only have 2 ways, there are 2 edge cases:

1. 1 as the first digit:

We can't turn it into 0 because that will change the number of digits in our number

2. 0 and 9:
these only have 1 way to change.