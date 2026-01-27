#include <iostream>
using namespace std;

using ull = long long;

bool can(ull d, ull n, ull a, ull b, ull w, ull h){
    ull tw = a+2*d, th = b+2*d;
    return (w/tw)*(h/th)>=n || (w/th)*(h/tw)>=n;
}

int main(){
    ull n, a, b, h, w;
    cin >> n >> a >> b >> h >> w;

    ull l = 0, r = 1e18;
    while (l + 1 < r){
        ull mid = l + (r - l) / 2;
        if (can(mid,n,a,b,h,w)){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
    return 0;
}