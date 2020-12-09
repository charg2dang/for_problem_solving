
def fibonacci( n ) :
    if n <= 2 :
        return 1;

    return fibonacci(n - 1) + fibonacci( n - 2);

def f_dp( n ) :
    ns = [0, 1, 1];
    for i in range(3, n + 1):
        ns.append(ns[i-1] + ns[i-2]);

    return ns[n];


for i in range(1, 10) :
    print(fibonacci(i));


    
for i in range(1, 10) :
    print(f_dp(i));


st = "ABCDEDCBA"
for i in range(len(st) // 2) :
    print(st[i], st[-(i+1)])

#print(st[0])
#print(st[1])
#print(st[-2])
