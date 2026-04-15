#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const double INF = 1e9;

struct price{
    int sell, buy;
};


int main(){
    int n; cin >> n;
    vector<price> prices(n);
    for (auto &i : prices){
        cin >> i.sell >> i.buy;
    }
    vector<vector<double>> dp(n+1,vector<double>(2,-INF));
    dp[0][0] = 100;
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]*100/prices[i-1].buy);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]*prices[i-1].sell/100);
    }
    cout << setprecision(2) << fixed << dp[n][0];
    return 0;
}