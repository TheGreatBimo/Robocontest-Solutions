n,k = map(int,input().split())
m=10**9+7
a=pow(k,n,m)-1
b=k-1
print(a*pow(b,m-2,m)%m)