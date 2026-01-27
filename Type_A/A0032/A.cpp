#include <iostream>
using namespace std;

int main(){
    int a,b,t;
    cin >> a >> b >> t;
    long long l = 0, r=1e9;
    while (l+1<r){
        long long m = l + (r-l)/2;
        if (m*b+b*t>=a*t) r=m;
        else l=m;
    }
    cout << r;
    return 0;
}