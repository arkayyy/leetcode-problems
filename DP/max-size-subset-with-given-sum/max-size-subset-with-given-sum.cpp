#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, target;
    cin >> n >> target;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Dynamic Programming approach (Bottoms up..no memoization) (For reference: https://www.geeksforgeeks.org/maximum-size-subset-given-sum/) :-

    vector<vector<bool>> isSubsetValid(n + 1, vector<bool>(target + 1, false));
    vector<vector<int>> count(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        isSubsetValid[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            isSubsetValid[i][j] = isSubsetValid[i - 1][j]; //not including the ith index element in nums
            count[i][j] = count[i - 1][j];                 //not including the ith index element in nums

            if (j >= nums[i - 1])
            {
                isSubsetValid[i][j] = (isSubsetValid[i][j] || isSubsetValid[i - 1][j - nums[i - 1]]); //checking if a valid subset will be present if the current elemen is also included

                if (isSubsetValid[i - 1][j - nums[i - 1]])                             //checking if after taking the current element, a valid subset is present with the given target
                    count[i][j] = max(count[i][j], 1 + count[i - 1][j - nums[i - 1]]); // taking max count because max size subset needs to be output
            }
        }
    }
    cout << count[nums.size()][target] << endl;
    return 0;
}