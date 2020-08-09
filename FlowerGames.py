t = int(input())
for i in range(t):
    n = int(input())
    n1 = n
    lo = 0
    while(n1 > 0):
        n1//= 2
        lo+=1
    print(2*(n - (2**(lo-1)-1)) - 1)
