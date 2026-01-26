#include <iostream>
#include <vector>
using namespace std;

struct DSU{
    vector<int> parent, size;

    DSU(int n){
        parent.assign(n,0);
        size.assign(n,1);

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
        parent[b]=a;
        size[a]+=size[b];
    }

    bool connected(int a, int b){
        return get(a) == get(b);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a){
        cin >> i;
    }

    DSU s(n);
    while (m--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        s.union_sets(l,r);
    }

    int res = 0;
    for (int i = 0; i < n; i++){
        int x = a[i] - 1;
        if (s.connected(i,x)) res++;
    }
    
    cout << res;

    return 0;
}