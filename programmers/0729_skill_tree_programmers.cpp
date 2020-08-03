#include <string>
#include <vector>

using namespace std;



// string¿¡¼­ 
// 


int in_string(string& str, char ch, int offset)
{
}


int solution(string skill, vector<string> skill_trees)
{
    int counter = 0;


    for (string& s_t : skill_trees)
    {
        bool valid_skil_tree = true;
        bool has_npos = false;
        size_t co{}, po{};// current_order{}, prev_order{};
        for (char c : skill) // 
        {
            po = co;
            co = s_t.find(c);

            if (has_npos == true && co != string::npos)
            {
                valid_skil_tree = false;
                break;
            }

            if (co == string::npos)
            {
                has_npos == true;
            }
            
            if (has_npos == false && po > co)
            {
                valid_skil_tree = false;
                break;
            }
        }
        
        if (valid_skil_tree == true)
        {
            counter += 1;
        }
    }

    return counter;
}