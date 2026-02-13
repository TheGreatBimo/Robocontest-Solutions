#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9+7;

vector<vector<long long>> M = {
    {1,1,1},
    {1,0,0},
    {0,1,0}
};

vector<vector<long long>> unit = {
    {1,0,0},
    {0,1,0},
    {0,0,1}
};

vector<vector<vector<long long>>> powers(64);

vector<vector<long long>> matrix_mul(vector<vector<long long>> &a, vector<vector<long long>> &b){
    vector<vector<long long>> res(3,vector<long long>(3,0));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int x = 0; x < 3; x++){
                res[i][j]+=a[i][x]*b[x][j];
                res[i][j]%=mod;
            }
        }
    }
    return res;
}

void build_powers(){
    powers[0] = M;
    for (int i = 1; i < 64; i++){
        powers[i] = matrix_mul(powers[i-1],powers[i-1]);
    }
}

vector<vector<long long>> matrix_exp(long long b){
    vector<vector<long long>> res = unit;
    int i = 0;
    while (b > 0){
        if (b & 1){
            res = matrix_mul(res,powers[i]);
        }
        b>>=1; i++;
    }
    return res;
}

void solve(){
    long long a; cin >> a;
    vector<vector<long long>> T = matrix_exp(a-1);
    vector<long long> res = {
        T[0][0]+T[0][1],
        T[1][0]+T[1][1],
        T[2][0]+T[2][1]
    };
    cout << (res[0]+res[1]+res[2]+mod)%mod << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    build_powers();

    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}