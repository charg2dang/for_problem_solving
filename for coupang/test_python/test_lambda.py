from collections import defaultdict;

d = defaultdict(lambda : 10);

print(d[0])
print(d[2])

print((lambda x : x + 10)(2));