#include <iostream>
#include <vector>
using namespace std;

struct station{
    int x, y;

    bool common(station b){
        return x == b.x || y == b.y;
    }
};

struct DSU{
    vector<int> parent, size;
    int components;

    DSU(int n){
        parent.assign(n,0);
        size.assign(n,1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        components = n;
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
        components--;
        if (size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a]+=size[b];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<station> a(n);
    for (auto &[x,y] : a){
        cin >> x >> y;
    }
    
    DSU s(n);
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i].common(a[j])){
                s.union_sets(i,j);
            }
        }
    }
    cout << s.components - 1;
    
    return 0;
}