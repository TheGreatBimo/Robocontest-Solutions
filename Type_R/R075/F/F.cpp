#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    vector<long long> a(n+1), pref(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i]=pref[i-1] + a[i];
    }
    for (int i = 1; i <= n; i++){
        cout << pref[min(i+r,n)]-pref[max(0,i-r-1)] << ' ';
    }
    return 0;
}