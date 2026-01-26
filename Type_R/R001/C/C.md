[Problem link](https://robocontest.uz/tasks/R001C)

#### Translation
People living on the planet Uxonoid are infinite in number, and none of them ever die.

On this planet, as a result of consuming wild animals, one person became infected with a contagious virus.

This virus is transmitted only when an infected person comes into contact with a healthy person; in that case, the virus passes from the infected person to the healthy one.

Fortunately for the inhabitants of Uxonoid, the local scientists are extremely talented and developed a vaccine against the virus as soon as the virus was detected. However, this vaccine takes effect after one day. All infected patients take the vaccine immediately at the moment they become infected, and after they recover, they never get infected again.

Every person living on the planet meets exactly K people per day.

Determine the maximum possible number of people who have recovered from the virus after N days, starting from the moment one person gets infected by an animal.

Print the number of infected people modulo 1000000007 (1e9+7).

#### Solution
In short:
Every day K times number of previously infected people become infected, and those previously infected people are cured.

| Day        | Number of infected people |      Cured people   |
|------------|---------------------------|---------------------|
| 0 | 1 | 0 |
| 1 | K | 1 |
| 2 | K*K | 1+K |
| 3 | K^3 | 1+K+K^2 |

As we can see number of cured people at any day is a sum of geometric progression.
Formula for the geometric progression sum of n terms is:
b1*(q^n - 1)/(q - 1)
here:
b1 = 1
q = K

As we're asked to find the result modulo 1e9+7 we will have to use modular inverse with binary exponentiation.

to calculate A/B mod c :
a = A mod c,
b = B mod c

the result is a*b^(phi(c)-1) mod c
as we know that c is prime, phi(c) is equal to c-1
so the final result is a*b^(c-2) mod c

[More on Modular Inverse and Binary exponentiation (cp algorithms)](https://cp-algorithms.com/algebra/module-inverse.html)