#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);

    for (auto &i : a){
        cin >> i;
    }
    
    vector<bitset<1000>> nums(1001);
    bitset<1001> b; b[0] = 1;

    for (int i = 0; i < n; i++){
        for (int s = 1000; s >= a[i]; s--){
            if (b[s-a[i]]){
                b[s] = 1;
                nums[s]=nums[s-a[i]]; nums[s][i] = 1;
            }
        }
    }
    if (b[l]){
        for (int i = 0; i < n; i++){
            if (nums[l][i]) cout << i << ' ';
        }
    } else {
        cout << "no";
    }
    return 0;
}