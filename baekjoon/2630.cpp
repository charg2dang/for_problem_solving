#include <iostream>
#include <vector>

using namespace std;

short pos[129][129];

int color_counter[2];

int divide_and_conquer(int sy, int sx, int offset, int& color)
{
    if ( offset <= 1 )
    {
        color = pos[sy][sx];
        
        return 0;
    }

    int colors[4]{};
    
    int half_offset = offset / 2;

    int ret2 = divide_and_conquer(sy, sx, half_offset, colors[1]);
    int ret1 = divide_and_conquer(sy , sx + half_offset,  half_offset, colors[0]);
    int ret4 = divide_and_conquer(sy + half_offset, sx + half_offset, half_offset, colors[3]);
    int ret3 = divide_and_conquer(sy + half_offset, sx, half_offset,colors[2]);

    int total = colors[0] + colors[1] + colors[2] + colors[3];

    if (ret1 + ret2 + ret3 + ret4 == 0) // 하나의 상태 
    {
        color = colors[0];
        if (total == 0 || total == 4)
        {
            return 0;
        }
        else
        {
            color_counter[colors[0]] += 1;
            color_counter[colors[1]] += 1;
            color_counter[colors[2]] += 1;
            color_counter[colors[3]] += 1;

            return 1;
        }
    }
    else // 노나진 경우.
    {
        if (ret1 == 0)
        {
            color_counter[colors[0]] += 1;
        }
        
        if (ret2 == 0)
        {
            color_counter[colors[1]] += 1;
        }

        if (ret3 == 0)
        {
            color_counter[colors[2]] += 1;
        }

        if (ret4 == 0)
        {
            color_counter[colors[3]] += 1;
        }

        return 1;
    }
}


int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    for (int y{}; y < N; ++y)
    {
        for (int x{}; x < N; ++x)
        {
            int i;
            cin >> i;
            pos[y][x] = i;
        }
    }

    int output{};
    divide_and_conquer(0, 0, N, output);

    cout << color_counter[0] << "\n";
    cout << color_counter[1] << "\n";

    return 0;
}

