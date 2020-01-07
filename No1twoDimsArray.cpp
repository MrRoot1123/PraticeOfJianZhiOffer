#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    bool FindArray(int target, vector<int> array){
        int head = 0, tail = array.size() - 1;
        if (array[tail] < target || array[head] > target) return false;
        int mid = (head + tail)/2;
        while(head != tail && tail != head+1){
            
            if (array[mid] == target)
                return true;
            else if (array[mid] < target)
                head = mid;
            else
                tail = mid;
            mid = (head + tail)/2;
        }
        if (array[head]==target||array[tail]==target)
            return true;
        return false;
    }

    bool Find(int target, vector<vector<int> > array) {
        for (int i = 0; i < array.size(); ++i)
        {
            if (FindArray(target,array[i]))
                return true;
        }
        return false;
    }
};

int main(void)
{
    Solution s = Solution();
    vector<vector<int> > array = {{1,2,3,4,5,6,7,8,9,10},{2,3,4,5,6,7,8,9,10,11},{21,22,23,24,25,26,27,28,29,30}};
    if (s.Find(15,array)) cout << "success" << endl;
    else cout << "fail" << endl;
    return 0;
}