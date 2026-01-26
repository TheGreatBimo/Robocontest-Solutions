def FindSum(a):
    i=0
    while a>0:
        i+=a%10
        a=a//10
    return i
a=int(input())
i=0
s=0
while i!=a:
    s+=1
    if s%FindSum(s)**2==0:
        i+=1
print(s)