#include <iostream>
using namespace std;

int summa(int a){
    int sum=0;
    while (a>0){
        sum+=a%10;
        a/=10;
    }
    return sum*sum;
}

int main(){
    long long s = 0;
    int a;
    cin >> a;
    for (int i = 0; i < a;){
        s++;
        if (s%summa(s)==0){
            i++;
        }
    }
    cout << s;
    return 0;
}