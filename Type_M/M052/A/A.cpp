#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

const int mod = 1e9;

vector<int> getUsefulNodes(vector<unordered_map<int,int>> &graph){
    int n = graph.size();
    vector<int> reachable(n), reached(n), useful(n);
    reachable[0] = 1; reached[1] = 1;

    queue<int> q; q.push(0);
    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (auto &[to,c] : graph[v]){
            if (!reachable[to]){
                reachable[to] = 1;
                q.push(to);
            }
        }
    }

    vector<vector<int>> inverse(n);
    for (int i = 0; i < n; i++){
        for (auto &[to,c] : graph[i]){
            inverse[to].push_back(i);
        }
    }

    q.push(1);
    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (auto &to : inverse[v]){
            if (!reached[to]){
                reached[to] = 1;
                q.push(to);
            }
        }
    }

    for (int i = 0; i < n; i++){
        useful[i] = reachable[i] && reached[i];
    }
    
    return useful;
}

void dfs(vector<unordered_map<int,int>> &graph, int v, vector<int> &visited, vector<int> &useful, bool &res){
    visited[v] = 1;

    for (auto &[to,c] : graph[v]){
        if (!visited[to] && useful[to]){
            dfs(graph,to,visited,useful,res);
        } else if (visited[to] == 1 && useful[to]){
            res = true;
        }
    }
    
    visited[v] = 2;
}

bool cyclic(vector<unordered_map<int,int>> &graph, vector<int> &useful){
    int n = graph.size();
    bool res = false;
    vector<int> visited(n);
    dfs(graph,0,visited,useful,res);
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    if (n == 1){ cout << 0; return 0;}
    vector<unordered_map<int,int>> graph(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        graph[a][b]++;
    }
    
    vector<int> useful = getUsefulNodes(graph);
    if (!useful[1]){
        cout << 0; return 0;
    } if (cyclic(graph,useful)){
        cout << "inf"; return 0;
    }
    
    
    vector<int> indegree(n);
    for (int i = 0; i < n; i++){
        if (!useful[i]) continue;
        for (auto &[to,c] : graph[i]){
            if (useful[to]) indegree[to]++;
        }
    }
    
    queue<int> q; q.push(0);
    vector<long long> dp(n); dp[0] = 1;
    vector<int> overflow(n);
    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (auto &[to,c] : graph[v]){
            if (useful[to]){
                indegree[to]--;
                if (overflow[v]) overflow[to] = 1;
                if (indegree[to] == 0) q.push(to); // topological ordering
                if (dp[to] + dp[v]*c >= mod) overflow[to] = 1;
                dp[to]+=(dp[v]*c)%mod;
                dp[to]%=mod;
            }
        }
    }
    if (overflow[1]){
        printf("%09lld\n",dp[1]);
    } else {
        cout << dp[1];
    }
    return 0;
}