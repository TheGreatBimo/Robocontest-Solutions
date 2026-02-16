#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9+7;

int main(){
    int n; cin >> n;
    vector<long long> dp_even(n+1), dp_odd(n+1);

    for (int i = 1; i <= n; i++){
        if (i % 2 == 0){
            dp_odd[i] = dp_odd[i-1];
            dp_even[i] = (dp_even[i-1] + dp_odd[i-1] + 1) % mod;
        } else {
            dp_even[i] = dp_even[i-1];
            dp_odd[i] = (dp_odd[i-1] + dp_even[i-1]+1) % mod;
        }
    }
    cout << (dp_odd[n] + dp_even[n]) % mod;
    return 0;
}