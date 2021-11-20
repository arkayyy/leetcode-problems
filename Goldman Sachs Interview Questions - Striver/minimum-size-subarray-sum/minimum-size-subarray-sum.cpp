class Solution
{
public:
    //function for checking if any subarray of given size satisfies the condition (sum of subarray>=target)
    bool slidingWindow(int size, int target, vector<int> &prefixSum)
    {
        int n = prefixSum.size();

        for (int i = 0; (i + size) < n; i++)
        {
            if (prefixSum[i + size] - prefixSum[i] >= target) //prefix sum is used because prefix[i+size]-prefix[i] gives the sum of subarray between i and i+size-1 (subarray of given size), in O(1) time complexity. Otherwise summing up every subarray would take a lot of time.
                return true;
        }

        return false;
    }
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int n = nums.size();

        vector<int> prefixSum(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] += (prefixSum[i - 1] + nums[i - 1]);
        }

        int lo = 0, hi = n;
        int ans = INT_MAX;

        while (lo <= hi)
        {
            int mid = (lo + ((hi - lo) >> 1));

            if (slidingWindow(mid, target, prefixSum)) //checking if any subarray of given size=mid satisfies the condition (sum of subarray>=target)
            {
                ans = min(ans, mid);
                hi = mid - 1;
            } // if subarray of size=mid exists, we decrease the higher size limit to (mid-1), and store this value of mid into final ans.
            else
                lo = mid + 1; //otherwise increasing the lower size limit to (mid+1)
        }
        if (ans == INT_MAX)
            return 0; //no such subarray exists
        return ans;
    }
};