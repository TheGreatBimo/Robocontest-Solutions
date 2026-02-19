#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a){
        cin >> i;
    }

    sort(a.begin(),a.end());

    long long res = 0;
    for (int l = 0, r = n - 1; l < r;){
        l++; r--; res+=a[r]; r--;
    }
    cout << res;
    
    return 0;
}