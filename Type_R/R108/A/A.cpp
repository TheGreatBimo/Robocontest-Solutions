#include <iostream>
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    cout << min((a-b+7)%7,(b-a+7)%7) << '\n';
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}