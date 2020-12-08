def selection_sort(a) -> None:
    for i in range(len(a)) :
        min_idx = i;
        for j in range( i + 1, len(a) ) :
            if a[min_idx] > a[j] :
                min_idx = j;
    
        a[i], a[min_idx] = a[min_idx], a[i];


a = [1, 3, 5, 7, 2, 9, 0];
print(a);
selection_sort(a);
print(a);
