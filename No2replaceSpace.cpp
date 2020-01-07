#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {

        if(str==NULL)
            return ;

        int CntofBlanks = 0;
        int OriginalLength = 0;
        int len = 0;

        for (int i = 0; str[i] != '\0'; ++i){
            ++OriginalLength;
            if (str[i] == ' '){
                ++CntofBlanks;
            }
        }

        len = OriginalLength + 2*CntofBlanks;
        if (len + 1 > length)
            return;
        
        char *pStr1 = str + OriginalLength;
        char *pStr2 = str + len;

        while (pStr1 != pStr2){
            if (*pStr1 == ' '){
                *pStr2-- = '0';
                *pStr2-- = '2';
                *pStr2-- = '%';
            }
            else{
                *pStr2-- = *pStr1;
            }
            --pStr1;
        }
        return;
	}
};

int main(void)
{
    Solution s = Solution();
    char str[23] = {'W','e',' ','a','r','e',' ','h','a','p','p','y'};
    s.replaceSpace(str, 23);
    for (char c : str) cout << c;
    cout << endl;
    return 0;
}