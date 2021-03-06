#include <iostream>
#include <vector>

using namespace std;
// https://cuijiahua.com/blog/2018/01/basis_32.html
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int length = numbers.size();
        if(length == 0){
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i <　length; i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
private:
    // 升序排序
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};

int main()
{
    return 0;
}