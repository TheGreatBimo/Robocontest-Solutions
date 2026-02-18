#include <iostream>
#include <string>
using namespace std;

int main(){
    int total_correct; cin >> total_correct;
    string a, b;
    cin >> a >> b;
    int s = a.size(), matching = 0;
    for (int i = 0; i < s; i++){
        if (a[i] == b[i]) matching++;
    }

    int unmatching = s - matching;
    int reverse_n = s - total_correct;

    int matching_correct = min(matching,total_correct);
    int unmatching_correct = min(unmatching,reverse_n);
    cout << matching_correct + unmatching_correct;
    return 0;
}