import sys
k = 0
n = 0
dp = [[-1 for i in range(110)] for _ in range(110)]
def go(i, ult):
    if(i == n): return ult == k
    r = dp[i][ult]
    if(r !=-1): return r
    r = 0
    for j in range(1,ult+1):
        r= r +go(i+1,ult)
    if(ult != k): r = r+go(i+1,ult+1)
    dp[i][ult]=r
    return r


if __name__ == '__main__':
    sys.setrecursionlimit(50000)
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    args = input().split(' ')
    k = int(args[0])
    n = int(args[1])
    fact = 1
    for i in range(1,k+1): fact = fact*i
    ans = go(0,0)*fact
    print(str(go(0, 0)*fact))