[Problem link](https://robocontest.uz/tasks/R097C)
#### Translation
Azimjon and the Number Game

Azimjon plays an online game with n players. Each player chooses a number in the range [1, 10¹²].

Then, the average of all chosen numbers is computed and multiplied by 0.8. The player whose number is closest to this value wins.

Azimjon can see all other players’ chosen numbers. Determine what number he should choose to win.

#### Solution
The value of

$$ \frac{(S + x)}{(n + 1)} \cdot 0.8 $$ 

should be as close as possible to x, where S is the sum of all other players’ numbers and x is the number Azimjon chooses.

Let's make this value equal to x and solve for x:

$$ \frac{(S + x)}{(n + 1)} \cdot 0.8 = x $$

$$ 0.8S + 0.8x = (n + 1)x $$

$$ 0.8S = (n + 1 - 0.8)x $$

to avoid floating point precision issues, we can multiply both sides by 5:

$$ 4S = (5n + 5 - 4)x $$

$$ x = \frac{4S}{5n + 1} $$

in case floating point precision issues arise, we can also check the numbers around this value to find the closest one.
we check from floor(x)-2 to floor(x)+2 to find the number with the smallest

$$ \left| (5n+1)x - 4S \right| $$

The number with the smallest value of this expression will be the closest to the desired value.
The time complexity of this solution is O(n) to calculate the sum and O(1) to check the 5 numbers around the calculated x, so the overall time complexity is O(n).
The binary search tag is weird, but it can be solved with binary search as well, but we're not going to do that since the O(n) solution is efficient enough for this problem.