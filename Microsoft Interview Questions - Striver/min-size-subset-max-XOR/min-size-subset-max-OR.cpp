#include <bits/stdc++.h>
using namespace std;

int maxOR(vector<int> &nums)
{
    int ans = 0;
    for (auto i : nums)
    {
        ans = ans | i;
    }
    return ans;
}
int main() //Reference: https://www.geeksforgeeks.org/size-of-the-smallest-subset-with-maximum-bitwise-or/
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target = maxOR(nums);
    //cout<<"HI"<<target<<endl;
    vector<vector<int>> count(n + 1, vector<int>(target + 1, INT_MAX));
    vector<vector<bool>> isSubsetValid(n + 1, vector<bool>(target + 1, false));

    //not initializing since no empty subsets are allowed....
    // for(int i = 0; i<= n;i++)
    // {
    //     isSubsetValid[i][0] = true;
    //     count[i][0] = 0;
    // }

    count[0][0] = 0;
    count[0][nums[0]] = 1;
    //  cout<<(5|0)<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            count[i][j] = min(count[i][j], count[i - 1][j]); // not including the element at the ith index

            if (count[i - 1][j] != INT_MAX) // checking that if ith element is not included, can the subset with max OR be formed??
            {
                count[i][j | nums[i - 1]] = min(count[i][j | nums[i - 1]], 1 + count[i - 1][j]);
            }
        }
    }
    cout << count[n][target] << endl;

    return 0;
}