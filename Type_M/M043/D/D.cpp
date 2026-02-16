#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n; cin >> n;
    vector<long long> sums(n+1);
    long long targ = n*(n+1)/2;
    for (int i = 1; i < n+1; i++){
        sums[i] = i + sums[i-1];
        if (targ-sums[i-1]==sums[i]){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}