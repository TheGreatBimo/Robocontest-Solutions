#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    if (b.size() < a.size()){
        cout << "NO";
        return 0;
    }
    int j = 0;
    for (int i = 0; i < b.size() && j < a.size(); i++){
        if (b[i] == a[j]) j++;
    }

    if (j == a.size()){
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}