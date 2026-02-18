[Problem link](https://robocontest.uz/tasks/M103C)
#### Translation:
Test

You and your friend took a Yes/No test. Your friend knows how many questions they answered correctly, but not which ones. You compare your answers with your friend’s answers.

Your task is to determine the maximum number of questions you could have answered correctly.

#### Solution:
Where can we gain points from that:
1. Matching positions:
• If your friend was correct -> you were also correct
• If your friend was incorrect -> you were also incorrect

maximum correct matching positions where friend could answer correctly is max(matching,n).

2. Unmatching positions:
• If your friend was correct -> you were incorrect
• If your friend was incorrect -> you were correct

Our friend has total of size - n incorrect answers,
to maximize OUR correct answers we have to maximize HIS incorrect answers,
so maximum incorrect unmatching positions where friend could answer incorrectly is max(unmatching,total_incorrect)

The result is max(matching,n)+max(unmatching,total_incorrect)