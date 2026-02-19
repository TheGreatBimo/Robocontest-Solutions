[Problem link](https://robocontest.uz/tasks/M103G)
#### Translation:
ICPC

Sunnat is responsible for preparing students at TATU for the ICPC. There are n students, each with a strength f[i].

Students must be divided into teams of three. The strength of a team of three is the median of their individual strengths.

Help Sunnat form k teams of three so that the total strength (sum of all team strengths) is maximized.
#### Solution:
Easy-peasy lemon squeezy.
We will greedily solve the problem.

We will always form teams from 1 weakest and 2 strongest available students, that way weak students don't appear in the median.
in order to find the weak and strong students we will sort the students first.