#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    for (auto &i : a){
        cin >> i;    
    }

    sort(a.begin(),a.end());
    cout << a[(n-1)/2];

    return 0;
}