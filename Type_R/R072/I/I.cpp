#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a){
        cin >> i;
    }

    unordered_map<long long, int> ct; ct[0] = 1;
    long long sum = 0, res = 0;
    for (auto &i : a){
        sum+=i;
        res+=ct[sum];
        ct[sum]++;
    }
    cout << res;
    return 0;
}