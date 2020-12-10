"""
2352

O (n log n) lis problem 

reference
https://hyun-am-coding.tistory.com/entry/%EC%B5%9C%EC%9E%A5-%EC%A6%9D%EA%B0%80-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4LIS-%EA%B0%9C%EB%85%90?category=778332

"""
 
import sys
sys_input = sys.stdin.readline

def binary_search(arr, val): 
    s = 0;
    e = len(arr)-1; 
    
    while s <= e: 
        m = (s+e)//2; 
        if arr[m] > val: 
            e = m-1;
        else: 
            s = m+1;
    return s;


#input
n = int(sys_input());
l = list(map(int, sys_input().split()));
lower_bounds = [];

for i in l:
    if len(lower_bounds) == 0 or lower_bounds[-1] < i:
        lower_bounds.append(i);
    else:
        lower_bounds[binary_search(lower_bounds, i)] = i;

print(len(lower_bounds));


