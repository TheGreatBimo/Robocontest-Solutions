#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    double S = 0;
    for (auto &i : a){
        cin >> i; S+=i;
    }
    long long x = floor(4*S/(5*n+1));
    long long res = 0, resDelta = 1e18;
    for (long long i = x - 1; i <= x+1; i++){
        long long newDelta = abs((5*n+1)*i-4*S);
        if (newDelta <= resDelta){
            res = i; resDelta = newDelta;
        }
    }
    cout << res;
    return 0;
}