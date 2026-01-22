[Problem link](https://robocontest.uz/tasks/R001A)

#### Translation:
On this planet, one person became infected with a contagious virus as a result of consuming wild animals.

This virus is transmitted only when a person infected with the virus comes into contact with a healthy person;
in that case, the virus passes from the infected person to the healthy one.

Every person living on the planet Uxonoid meets exactly K people per day.

Determine the minimum possible number of infected people on the planet after N days,
starting from the moment one person gets infected by the animal.

#### Solution:
Notice that the problem is asking for minimum possible number of infected people.
If all infected people only meet with each other, the virus will stop spreading and will be stuck among K+1 people.
So the minimum number of infected people is always K+1 with one exception: On day 0 only the patient zero is infected, so there are only 1 infected people.