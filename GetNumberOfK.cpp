#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;     
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> t1 = {1,2,3,3,3,3,4,5};
    vector<int> t2 = {3};
    int k = 3;
    s.GetNumberOfK(t2,3);
    return 0;
}