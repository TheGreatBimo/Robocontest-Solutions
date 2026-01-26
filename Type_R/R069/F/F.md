[Problem link](https://robocontest.uz/tasks/R069F)
#### Problem statement in short
Elf Friends

At the North Pole, programming has become very popular in recent years. This year, Santa set up an office to bring programmer elves together.

The elves don’t know each other initially. Santa believes it’s important for everyone in the team to know each other, so he observes them daily and records:

! a b — elves a and b are seen together, so they become friends.

? a b — asks whether elves a and b are friends. Friendship is transitive: if a is friends with b and b is friends with c, then a is also friends with c.

For each query, update friendships or answer whether two elves are friends.
#### Solution
This is basic Disjoint Sets Union problem.
We will use DSU with path compression and size ranking in order to make it efficient.

[More on DSU](https://cp-algorithms.com/data_structures/disjoint_set_union.html)