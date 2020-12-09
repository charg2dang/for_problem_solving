
import sys
sys_input = sys.stdin.readline

n = int(sys_input());
l = [0] + list(map(int, input().split()));
d = [1] * ( n + 1 );

for i in range(1, n + 1) :
    for j in range(1, i) :
        if l[j] < l[i] :
            d[i] = max(d[i], d[j] + 1);

print(max(d));


