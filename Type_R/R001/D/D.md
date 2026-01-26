[Problem link](https://robocontest.uz/tasks/R001D)

#### Translation
Print the natural number N in Uzbek Latin script.

#### Solution
We will process the numbers in this order:
111_222_333_444
each part will have its own suffix (milliard, million, ming, -)
and each part may/may not have the suffix "yuz" (hundred)

In order to do that we will use a recursive function as each quarter is processed similarly
f(n)
Base case:
The number is less than 100,
in this case we can just convert it to written number.

Recursive:
If the number is larger than a billion, million, thousand, and hundred (mark this number as m)
we do:
return f(n/m)+suf[m]+f(n%m)
and the rest of the number is processed in the recursive calls

The time complexity of this algorithm is O(1) as we know for sure that we only have 4 quarters, and one quarter is processed in less than 4 recursions, therefore complexity is O(4*some constant) = O(1)