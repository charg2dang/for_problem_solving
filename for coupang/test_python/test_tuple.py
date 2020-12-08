

def return_4and5() -> tuple :
    return (4, 5);

def return_a_and_b(a:int, b:int) -> tuple :
    return (a, b);




print(return_4and5());
print(return_a_and_b(1, 2));
print(return_a_and_b(1, 2)[0]);
#print(return_a_and_b(1, 2)[2]); #out of range
