#include <iostream>
#include <vector>

using namespace std;

class disjoint_set
{
public:
    disjoint_set(size_t n)
    {
        ns = new int[n+1];

        for (int a{}; a <= n; ++a)
        {
            ns[a] = a;
        }
    }

    ~disjoint_set()
    {
        delete[] ns;
    }

    int get_parnet(int x)
    {
        if (ns[x] == x)
        {
            return x;
        }
        else
        {
            ns[x] = get_parnet(ns[x]);
            
            return ns[x];
        }
    }

    bool has_same_parent(int l, int r)
    {
        l = get_parnet(l);
        r = get_parnet(r);

        return l == r;
    }

    void union_node(int l, int r)
    {
        l = get_parnet(l);
        r = get_parnet(r);

        if (l > r)
        {
            ns[l] = r;
        }
        else
        {
            ns[r] = l;
        }
    }

private:
    int* ns;
};

int main()
{
    int N, M;
    cin >> N >> M;

    disjoint_set ds(N);
    vector<int> is;
    vector<int> travel_path;

    // 행렬로 들어옴.
    for (int a{}; a < N; ++a)
    {
        for (int b{}; b < N; ++b)
        {
            int i;
            cin >> i;
            is.push_back(i);
        }
    }

    // 여행경로 다 이어진건지.
    for (int b{}; b < M; ++b)
    {
        int i;
        cin >> i;
        travel_path.push_back(i);
    }

    // 연결.
    for (int start_node{}; start_node < N; ++start_node)
    {
        for (int end_node{ 0 };  end_node < N; ++end_node )
        {
            int input = is[(start_node * N) + end_node];
            if (input == 1)
            {
                ds.union_node(start_node + 1, end_node + 1);
            }
        }
    }

    int prev_city = travel_path[0];
    for (int b{1}; b < M; ++b)
    {
        int current_city = travel_path[b];
        if (ds.has_same_parent(prev_city, current_city) == false)
        {
            cout << "NO";
            return 0;
        }
        prev_city = current_city;
    }

    cout << "YES";
    return 0;
}

/*
4 3
0 1 0 0
1 0 1 0
0 1 0 0
0 0 0 0
1 2 3

4 4
0 1 0 0
1 0 1 0
0 1 0 0
0 0 0 0
1 2 3 4

4 4
0 1 0 0
1 0 1 1
0 1 0 0
0 1 0 0
1 2 3 4

5
2
0 1 1 0 0
1 0 0 0 0
1 0 0 0 0
0 0 0 0 1
0 0 0 1 0
1 5

1 0
0


*/
