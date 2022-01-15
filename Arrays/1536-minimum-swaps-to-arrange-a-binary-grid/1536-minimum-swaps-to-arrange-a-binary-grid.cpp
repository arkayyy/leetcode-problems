// KHATARNAK INTUITIVE
class Solution
{ // EXPLANATION: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/discuss/768076/Min-Adjacent-Swaps-to-Sort-the-array-of-INTEGERS-with-Proof
public:
    // ALGO: We are simply calculating the number of consecutive zeros at the end of every row, and store them in an array
    // We know that for valid grid, every row should contain atleast (n-i-1) consecutive zeros at the end (try out in the example)
    // So we sort this array in descending order now, and the number of swaps required to sort this array would be out actual answer too.
    // So we have successfully converted this grid question into: minimum number of swaps required to convert an array into another given permutation of itself. :-))
    int getZerosAtEnd(vector<int> &vec)
    {
        int cnt = 0;
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            if (vec[i] != 0)
                return cnt;
            cnt++;
        }
        return cnt;
    }
    vector<int> convertToArray(vector<vector<int>> &grid)
    {
        vector<int> vec;
        for (int i = 0; i < grid.size(); i++)
            vec.push_back(getZerosAtEnd(grid[i]));
        return vec;
    }
    int minSwapsArray(vector<int> &vec)
    {
        int cnt = 0;
        int n = vec.size();
        for (int i = 0; i < n; i++)
        {
            if (vec[i] < n - i - 1) // we are checking if any row contradicts the validity condition (no of cons zeros at last < n-i-1)
                                    // if it does we need to swap it with a row which has last cons zeros >= n-i-1
            {
                int j = i;
                while (j < n && vec[j] < (n - i - 1)) // will stop when we find an array with number of consecutive zeros at last >= n-i-1 that satisfies our validity condition
                    j++;

                if (j == n)
                    return -1; // if no such row is found with number of cons zeros at last >= n-i-1

                while (j > i) // we keep swapping adjacent rows until we reach ith row (which we actually had the purpose of swapping)
                {
                    cnt++;
                    swap(vec[j], vec[j - 1]);
                    j--;
                }
            }
        }
        return cnt;
    }
    int minSwaps(vector<vector<int>> &grid)
    {
        vector<int> vec = convertToArray(grid);
        return minSwapsArray(vec);
    }
};