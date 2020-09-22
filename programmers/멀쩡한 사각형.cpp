

using namespace std;


long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long solution(int w, int h)
{
    long long gcd_value = gcd(h, w);

    long long width = w / gcd_value;
    long long height = h / gcd_value;

    long long sum = (long long)w * (long long)h;

    long long answer = sum - gcd_value * ( width + height -1 );

    return answer;
}

