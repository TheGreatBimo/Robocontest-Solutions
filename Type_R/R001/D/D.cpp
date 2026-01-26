#include <iostream>
#include <string>
using namespace std;

long a[] = {1000000000, 1000000, 1000, 100};
string b[] = {"milliard ","million ","ming ","yuz "};
string c[] = {"","o'n ","yigirma ","o'ttiz ","qirq ","ellik ","oltmish ","yetmish ","sakson ","to'qson "};
string d[] = {"","bir ","ikki ","uch ","to'rt ","besh ", "olti ","yetti ","sakkiz ","to'qqiz "};

string number(long n){
    for (int i = 0; i < 4; i++){
        if (n >= a[i]){
            return number(n/a[i])+b[i]+number(n%a[i]);
        }
    }
    return c[n/10] + d[n%10];
}

int main(){
    long n;
    cin >> n;
    cout << number(n);
    return 0;
}