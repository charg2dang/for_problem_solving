n, m, k = map(int, input().split());
data = list( map( int, input().split() ) );


data.sort(reverse = True);
first = data[0];
second = data[1];

result = 0;


c1  = m // (k + 1);
c2  = m % (k + 1);

result += (c1 * first * k);
result += (c1 * second);
result += (k * c2);

print(result)


