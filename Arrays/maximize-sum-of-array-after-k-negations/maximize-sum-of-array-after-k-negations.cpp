class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int negc = 0, mini = INT_MAX;
        vector<int> neg;

        int sum = 0;

        for (auto i : nums)
        {
            if (i < 0)
            {
                neg.emplace_back(abs(i));
                negc++;
            }

            mini = min(mini, abs(i));
            sum += i;
        }

        //since we have to output the max sum, we use a greedy approach...
        //we start by turning the most negative ones to positive, because that'll increase sum by the most.

        sort(neg.begin(), neg.end(), greater<int>());

        int i = 0;
        while ((i < negc) && (k > 0))
        {
            sum += (2 * neg[i]);
            i++;
            k--;
        }

        //if all the negative numbers have already been turned to positive and added, if still we
        //have leftover moves, if the leftover moves is even, we know that we can chose any element ans
        //make it negative then positive in 2 moves, so no effect would be brought to the sum if we make even number of moves.

        if (k)
        {
            if ((k & 1) == 1) //if odd number of moves left, we know we can make the least number in the array as negative which would cause the least decrease in the total sum, thus assuring
                              //max possible sum is being output.
            {
                sum -= (2 * (mini));
            }
        }

        return sum;
    }
};