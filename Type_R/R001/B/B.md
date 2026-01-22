[Problem link](https://robocontest.uz/tasks/R001B)

#### Translation:
On this planet, one person became infected with a contagious virus as a result of consuming wild animals.

This virus is transmitted only when a person infected with the virus comes into contact with a healthy person;
in that case, the virus passes from the infected person to the healthy one.

Every person living on the planet Uxonoid meets exactly K people per day.

Determine the maximum possible number of infected people on the planet after N days,
starting from the moment one person gets infected by the animal.

Print the number of infected people modulo 1000000007 (1e9+7).

#### Solution:
Now this problem is asking to find the MAXIMUM possible number of infected people.
If every day one infected person will infect K new people, the number of infected people will increase exponentially.
So number of new infections each day will be K times the number of infected people on the last day.

| Day | Number of infected people | New infections |
|----------|----------|----------|
| 0    | 1     | 0 |
| 1    | 1+K     |  K |
| 2    | 1+K+K*(1+K) | K |

If the number of infected people on the last day is A, the next day will have K*A new infections, thus total number of new infected people will be
    A+A*K=A*(K+1).

Therefore the number of infected people multiply by K+1 every day.

so the result for day N will be:
    (K+1)^N

In order to exponentiate the number fast enough we will use Modular Inverse with Binary exponentiation.
[More on Modular Inverse (cp algorithms)](https://cp-algorithms.com/algebra/module-inverse.html)