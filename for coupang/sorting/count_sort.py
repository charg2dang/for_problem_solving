def count_sort(v):
    arr = [0 for i in range(max(v) + 1)];

    for i in v:
        arr[i] += 1;
    
    v.clear();

    n = 0;
    for i in arr:
        for j in range(i):
            v.append(n);
        n += 1;
    
        


a = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0 , 5, 2];
print (a);
count_sort(a);
print (a);