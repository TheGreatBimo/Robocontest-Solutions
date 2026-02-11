#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n,1);
    
    for (auto &i : a){
        int x; cin >> x;
        if (x % 2){
            i*=-1;
        }
    }

    unordered_map<int,int> ct; ct[0] = 1;

    int sum = 0, res = 0;
    for (int i = 0; i < n; i++){
        sum+=a[i];
        res+=ct[sum];
        ct[sum]++;
    }
    cout << res;
    return 0;
}