def do_insertion_sort(v) -> None :
    v_len = len(v);

    # 첫 번째 원소는 정렬된거로 친다.
    for i in range(1, v_len):
        i_item = v[i];
        b = i;

        for a in range(i -1, -1, -1):
            if v[a] > i_item :
                v[a + 1] = v[a];
                b = a;
            else :
                break;

        v[b] = i_item;


v = [10, 3, 5, 7, 2, 9, 0, 1];
#v = [4, 3, 2, 1];

print("before do_insertion_sort");
print(v);

do_insertion_sort(v);
print("do_insertion_sort - done");
print(v);