#include <iostream>
#include <vector>
using namespace std;

const int max_N = 1e6;

vector<int> primes = {2,3,5,7};

int main(){
    vector<int> res(max_N+1,max_N);
    for (auto &i : primes){
        res[i]=1;
    }
    for (int i = 2; i <= max_N; i++){
        for (auto &p : primes){
            if (p > i) continue;
            res[i]=min(res[i],res[i-p]+1);
        }
    }
    
    int t; cin >> t;
    while (t--){
        int a; cin >> a;
        cout << (res[a] == max_N ? -1 : res[a]) << '\n';
    }
    return 0;
}