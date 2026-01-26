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
        parent[b] = a;
        size[a]+=size[b];
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DSU s(n);
    while (q--){
        char t; cin >> t;
        if (t == '!'){
            int a, b;
            cin >> a >> b;
            a--; b--;
            s.union_sets(a,b);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << (s.get(a) == s.get(b)) << ' ';
        }
    }
    return 0;
}