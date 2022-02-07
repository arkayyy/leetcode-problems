class Solution {
public:
    //INTUITION: Our target is to remove all the negative signs in the matrix to maximize the sum.
    //It can be done in 2 ways:-
    //1. If any two negatives are adjacent they can be made positive together. 
    //2. If two -ve elements are not adjacent they can be flipped signs with their +ve adjacents in such a direction that at last we get 2 adjacent -ve nos, which we flip together to mke both +ve.
    //So, we count the number of negatives and check if that is odd or even. We know every pair of negatives can be made positive for surem, so if no. of negatives are even, max sum=abs value of all values in matrix.
    //If odd, max sum = abs value sum of all elems - (2*minimum abs value element) (because we choose to leave the least magnitude no. -ve as it would decrease least from the sum)
    
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long negativeCount = 0;
        long long minElement = INT_MAX;
        long long sum = 0;
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                sum+=abs(matrix[i][j]); 
                if(matrix[i][j]<0) negativeCount++;
                minElement = min(minElement,(long long)abs(matrix[i][j]));
            }
        }
        if(negativeCount&1)
            return sum-(2*minElement);
        else
            return sum;
    }
};