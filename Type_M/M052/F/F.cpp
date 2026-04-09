#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long per(vector<int> &histo){
    int n = histo.size();
    vector<int> left(n,-1), right(n,n);
    stack<int> st;
    for (int i = 0; i < n; i++){
        while (!st.empty() && histo[st.top()] > histo[i]){
            right[st.top()] = i;
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; i++){
        long long h = histo[i], w = right[i] - left[i] - 1;
        if (h == 0) continue;
        res = max(res, 2*(h + w));
    }
    return res;
}

int main(){
    int h, w;
    cin >> h >> w;
    string row;
    vector<int> histogram(w, 0);
    long long res = 0;
    for(int i = 0; i < h; i++){
        cin >> row;
        for(int j = 0; j < w; j++){
            if(row[j] == '.'){
                histogram[j]++;
            } else {
                histogram[j] = 0;
            }
        }
        res = max(res,per(histogram));
    }
    cout << max(0LL,res-1);
    return 0;
}