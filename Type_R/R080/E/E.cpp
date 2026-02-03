#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <string>
using namespace std;

vector<pair<int,int>> edges = {{1,2},{1,4},{2,3},{2,5},{3,6},{4,5},
{4,7},{5,8},{5,6},{6,9},{7,8},{8,9}};

vector<int> fact = {1,1,2,6,24,120,720,5040,40320,362880};

int hashF(int v[9]){
    int id = 0;
    bool used[10] = {0}; used[0] = 1;
    for (int i = 0; i < 9; i++){
        int unused = 0;
        for (int j = 0; j < v[i]; j++){
            if (!used[j]) unused++;
        }
        id += unused * fact[8-i];
        used[v[i]] = 1;
    }
    return id;
}

const int INF = 1e9;

long long bfs(int start){
    vector<int> dist(362880,INF);
    queue<pair<int,int>> q;

    int tmp = start;
    int digits[9];
    for (int i = 8; i >= 0; i--) {
        digits[i] = tmp % 10;
        tmp /= 10;
    }
    
    dist[hashF(digits)] = 0;
    q.push({start,hashF(digits)});

    while (!q.empty()){
        auto [v,h] = q.front();
        q.pop();
        
        int tmp = v;
        int digits[9];
        for (int i = 8; i >= 0; i--) {
            digits[i] = tmp % 10;
            tmp /= 10;
        }

        for (int i = 0; i < 12; i++){
            auto [a,b] = edges[i];
            a--; b--;

            swap(digits[a],digits[b]);
            int to = 0;
            for (int i = 0; i < 9; i++) to = to*10 + digits[i];
            int hashTO = hashF(digits);
            swap(digits[a],digits[b]);

            if (dist[hashTO] > dist[h] + 1){
                dist[hashTO] = dist[h] + 1;
                q.push({to,hashTO});
            }
        }
        
    }

    return dist[0];
}

int main(){
    int s = 0;
    for (int i = 0; i < 9; i++){
        int c; cin >> c;
        s*=10; s+=c;
    }
    cout << bfs(s);
    return 0;
}