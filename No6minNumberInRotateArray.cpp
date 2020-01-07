class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) return 0;
        int result = rotateArray[0];
        for (int i = rotateArray.size(); i > 0; --i){
            if (result < rotateArray[i-1]) break;
            else result = rotateArray[i-1];
        }
        return result;
    }
};