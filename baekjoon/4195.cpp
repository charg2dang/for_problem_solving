#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class disjoint_set
{
public:
    disjoint_set(size_t n) : size{ n }
    {
        ns = new int[n + 1];

        for (int a{}; a <= n; ++a)
        {
            ns[a] = a;
            m.emplace(a, 1);
        }
    }

    ~disjoint_set()
    {
        delete[] ns;
    }

    int get_parent(int x)
    {
        if (ns[x] == x)
        {
            return x;
        }
        else
        {
            ns[x] = get_parent(ns[x]);

            return ns[x];
        }
    }

    bool has_same_parent(int l, int r)
    {
        l = get_parent(l);
        r = get_parent(r);

        return l == r;
    }

    int get_size(int x)
    {
        return m[get_parent(x)];
    }

    void union_child(int l, int r)
    {
        l = get_parent(l);
        r = get_parent(r);

        if (l > r)
        {
            ns[l] = r;
            m[r] += m[l];
            m.erase(l);
        }
        else
        {
            ns[r] = l;
            m[l] += m[r];
            m.erase(r);
        }
    }

    void clear()
    {
        m.clear();

        for (int a{}; a <= size; ++a)
        {
            ns[a] = a;
            m.emplace(a, 1);
        }
    }

private:
    int* ns;
    size_t size;
    std::unordered_map<int, int> m;
};


int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, F;
    cin >> N;

    disjoint_set ds(100'000);



    for (int n{}; n < N; ++n)
    {
        int unique_number{};
        unordered_map<string, int> name_map;
        
        cin >> F;

        for (int f{}; f < F; ++f)
        {
            int unique_num_a, unique_num_b;
            string a, b;

            cin >> a >> b;

            auto it_a = name_map.find(a);
            if (it_a == name_map.end()) // 없는 경우
            {
                name_map.emplace(a, unique_number);
                unique_num_a = unique_number;
                unique_number += 1;
            }
            else
            {
                unique_num_a = it_a->second;
            }

            auto it_b = name_map.find(b);
            if (it_b == name_map.end())
            {
                name_map.emplace(b, unique_number);
                unique_num_b = unique_number;
                unique_number += 1;
            }
            else
            {
                unique_num_b = it_b->second;
            }
            
            if (ds.has_same_parent(unique_num_b, unique_num_a) == false)
            {
                ds.union_child(unique_num_b, unique_num_a);
            }

            cout << ds.get_size(unique_num_a) << "\n";
        }

        ds.clear();
    }


    return 0;

}

