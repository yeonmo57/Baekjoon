import sys

n = int(sys.stdin.readline())
num =[]

for i in range(n):
    a= int(sys.stdin.readline())
    if a == 0 :
        num.pop()
    else:
        num.append(a)

print(sum(num))


