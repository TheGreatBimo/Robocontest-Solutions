#include <iostream>
using namespace std;

int m=1e9+7;

int BiPow(int a, int b){
    if (b==0) return 1;
    if (b%2==0){
        int x=BiPow(a,b/2);
        return 1LL*x*x%m;
    }
    else return 1LL*a*BiPow(a,b-1)%m;
}

int main(){
    int n, k;
    cin >> n >> k;
    int a = BiPow(k,n)-1;
    cout << 1LL * a*BiPow(k-1,m-2)%m;
    return 0;
}