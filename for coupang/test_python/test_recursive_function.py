
def recursive_func(i) :
    if i == 0:
        return;
        
    print("재귀");

    recursive_func(i - 1);


def recursive_factorial( n ):
    if n == 1:
        return 1;

    return n * recursive_factorial(n-1);

def factorial( n ):
    result = 1;

    for i in range(1, n  + 1):
        result *= i;

    return result;



recursive_func(10);

r = recursive_factorial(6);
print(r);

r = factorial(6);
print(r);


