def quick_sort(v, start, end) -> None :
    if start >= end:
        return;

    low = start;
    high = end;
    pivot = v[( end + start ) // 2];

    while low <= high :
        while v[low] < pivot:
            low += 1;

        while v[high] > pivot:
            high -= 1;

        if low <= high:
            v[low], v[high] = v[high], v[low];

            low += 1;
            high -= 1;

    quick_sort(v, start, high);
    quick_sort(v, low, end);


v = [10, 3, 5, 7, 2, 9, 0, 1];

print(v);
quick_sort(v, 0, len(v)-1);
print(v);
print("qsort - done");