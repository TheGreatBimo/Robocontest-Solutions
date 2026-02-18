#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s; cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); i++){
        int n = s[i] - '0';
        if (i == 0 && n == 1) res++;
        else if (n == 0 || n == 9) res++;
        else res+=2;
    }
    cout << res;
    return 0;
}