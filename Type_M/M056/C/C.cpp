#include <iostream>
#include <vector>
using namespace std;

struct DSU{
    vector<int> parent, size;
    int components;

    DSU(int n){
        parent.assign(n,0);
        size.assign(n,1);
        components = n;

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int get(int a){
        if (parent[a] == a){
            return a;
        } return parent[a] = get(parent[a]);
    }

    void union_sets(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (size[a] < size[b]){
            swap(a,b);
        }
        components--;
        parent[b]=a;
        size[a]+=size[b];
    }
};

const int cx[4] = {0,0,-1,1};
const int cy[4] = {1,-1,0,0};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h,vector<int>(w,0));
    for (auto &row : grid){
        for (auto &c : row){
            cin >> c;
        }
    }

    DSU s(h*w);

    vector<int> ccLeft(w,0), ccRight(w,0);
    for (int x = 0; x < w; x++){
        for (int y = 0; y < h; y++){
            for (int i = 0; i < 4; i++){
                if (i == 3) continue;
                int tx = x + cx[i];
                int ty = y + cy[i];
                if (0 <= tx && tx < w && 0 <= ty && ty < h && grid[y][x] == grid[ty][tx]){
                    s.union_sets(y*w+x,ty*w+tx);
                }
            }
        }
        ccLeft[x] = s.components - h*(w-x-1);
    }

    s = DSU(h*w);

    for (int x = w - 1; x >= 0; x--){
        for (int y = 0; y < h; y++){
            for (int i = 0; i < 4; i++){
                if (i == 2) continue;
                int tx = x + cx[i];
                int ty = y + cy[i];
                if (0 <= tx && tx < w && 0 <= ty && ty < h && grid[y][x] == grid[ty][tx]){
                    s.union_sets(y*w+x,ty*w+tx);
                }
            }
        }
        ccRight[x] = s.components - h*x;
    }

    int res = 1e9;

    for (int i = 0; i < w - 1; i++){
        res = min(res,ccLeft[i]+ccRight[i+1]);
    }
    
    cout << res;

    return 0;
}