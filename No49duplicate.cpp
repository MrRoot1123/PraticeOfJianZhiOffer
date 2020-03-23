class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for (int i = 0; i < length; ++i)
        {
            int tmp = numbers[i] % length;
            if (numbers[tmp] < length)
                numbers[tmp] += length;
            else
            {
                *duplication = numbers[tmp] - length;
                return 1;
            }
        }
        return 0;
    }
};