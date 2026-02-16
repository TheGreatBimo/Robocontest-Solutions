#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    bitset<1001> b; b[0] = 1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        b |= b << x;
    }
    cout << (b[l] ? "yes" : "no");
    return 0;
}