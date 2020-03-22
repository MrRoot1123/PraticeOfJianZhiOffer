#include <string>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string res;
        int end = str.size() - 1, start;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            if (str[i] == ' ')
            {
                start = i + 1;
                for (int j = start; j <= end; ++j)
                {
                    res.append(1, str[j]);
                }
                res.append(1, str[i]);
                end = start - 2;
            }
        }
        for (int i = 0; i <= end; ++i)
        {
            res.append(1, str[i]);
        }
        return res;
    }
};

int main() {
    string a;
    a = "I am a student.";
    Solution s = Solution();
    s.ReverseSentence(a);
    return 0;
}