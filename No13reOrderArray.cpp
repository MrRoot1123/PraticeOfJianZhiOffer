class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < array.size(); ++i){
            if ((array[i] & 1) == 0) even.push_back(array[i]);
            else odd.push_back(array[i]);
        }
        size_t size_odd = odd.size();
        for (int i = 0; i < size_odd; ++i)
            array[i] = odd[i];
        for (int i = 0; i < even.size(); ++i)
            array[size_odd + i] = even[i];
        return;
    }
};