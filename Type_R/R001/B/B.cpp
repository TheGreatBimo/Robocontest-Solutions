#include <iostream>
using namespace std;

int m=1000000007;

int BiPow(int a, int b){
    if (b==0) return 1;
    if (b%2==0)
    {
        int x=BiPow(a,b/2);
        return 1LL*x*x%m;
    }
    else
        return 1LL*a*BiPow(a,b-1)%m;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << BiPow(b+1,a);
    return 0;
}