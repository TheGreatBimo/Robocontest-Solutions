[Problem link](https://robocontest.uz/tasks/M053C)
#### Problem statement in short:
Space Bases

To explore Mars, a research base must be built from n identical modules, each originally of size a × b meters. (width a, height b)

To increase reliability, each module gets a protective layer of integer thickness d, the same for all modules. With protection, a module’s size becomes (a + 2d) × (b + 2d).

All modules must be placed inside a w × h rectangular area, arranged in a regular grid, aligned with the sides of the area.

Given n, a, b, w, h, determine the maximum possible thickness d of the protective layer.
#### Solution:
We can determine if thickness d is small enough to fit all the modules in the area:
w/(a+2d) * h/(b+2d) >= n

If d is small enough, it can be proven that d-1 is also small enough.
If d is NOT small enough, it can be proven that d+1 is also not small enough.

Therefore we can deduce that the function can(d) is monotonic:
111111110000000000

We are asked to find the maximum d that fits, and in order to do that we can do binary search on answer.
