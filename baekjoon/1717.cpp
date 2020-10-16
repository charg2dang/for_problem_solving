#include <iostream>
#include <vector>

using namespace std;

class disjoing_set
{
public:
    disjoing_set(size_t n)
    {
        ns = new int[n+1];

        for (int a{}; a <= n; ++a)
        {
            ns[a] = a;
        }
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

    disjoing_set ds(N);
    vector<int> is;


    for (int n{}; n < M; ++n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        is.push_back(a);
        is.push_back(b);
        is.push_back(c);
    }

    for (int n{}; n < M; ++n)
    {
        int a = is[(n * 3)];
        int b = is[(n * 3) + 1];
        int c = is[(n * 3) + 2];


        switch (a)
        {
        case 0:
            ds.union_node(b, c);
            break;

        case 1:
            if (ds.has_same_parent(b, c) == true)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            break;
        }
    }

    return 0;
}
