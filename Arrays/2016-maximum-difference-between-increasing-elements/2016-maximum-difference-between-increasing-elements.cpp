class Solution
{
public:
    // ALGO: Just like buy and sell stocks...
    int maximumDifference(vector<int> &nums)
    {

        int mini = INT_MAX;
        int maxDiff = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < mini) // if any number less than current minimum is found, we reset current minimum
            {
                mini = nums[i];
            }
            else // else we try to maximise the distance using current minimum
            {
                maxDiff = max(maxDiff, nums[i] - mini);
            }
        }
        return (maxDiff == 0 ? -1 : maxDiff);
    }
};