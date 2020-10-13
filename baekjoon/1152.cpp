#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    getline(cin, str);

    int word_count {0};

    bool is_word{false};
    for (char c : str)
    {
        if (is_word == false)
        {
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            {
                word_count += 1;
                is_word = true;
            }
        }
        else
        {
            if (('a' > c || c > 'z') && ('A' > c || c > 'Z'))
            {
                is_word = false;
            }
        }
    }

    cout << word_count << endl;

    return 0;
}
