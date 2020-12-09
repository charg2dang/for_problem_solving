import sys
# input() 사용시 시간 초과 
sys_input = sys.stdin.readline 

n = int(sys_input());
l = list( map(str, sys_input().split()) );

#make palindrome dp 
dp = [ [ 0 for i in range(n+1) ] for i in range(n+1) ];

for i in range(1, n + 1) : # 자기 자신은 다 팰린드롬
    dp[i][i] = 1;

for i in range(1, n) :  # 
    if l[i-1] == l[i]: # 붙엉 잇는 문자끼리 같으면 팰린드롬
        dp[i][i+1] = 1;


for i in range(2, n):
    for j in range(1, ((n+1) - i)):
        if l[j-1] == l[j+i-1] and dp[j+1][j+i-1] == 1:
            dp[j][j+i] = 1;

q_count = int(sys_input());

for t in range(q_count) :
    s, e = map( int, sys_input().split() );
    print(dp[s][e]);

