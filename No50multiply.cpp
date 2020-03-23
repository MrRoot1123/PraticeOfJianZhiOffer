#include <vector>

using namespace std;

/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> vec;
        int sz=A.size();
        if(sz==0)
            return vec;
        vec.push_back(1);
        for(int i=0;i<sz-1;i++)
            vec.push_back(vec.back()*A[i]);
        int tmp=1;
        for(int i=sz-1;i>=0;i--)
        {
            vec[i]=vec[i]*tmp;
            tmp=tmp*A[i];
        }
        return vec;
    }
};