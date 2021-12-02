class Solution
{
public:
    void util(int n, int k, int prev, vector<vector<int>> &ans, vector<int> curr)
    {
        if (n < 0 || k < 0)
            return;

        if (n == 0 && k == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = prev + 1; i <= 9; i++)
        {
            curr.push_back(i);
            util(n - i, k - 1, i, ans, curr);
            // backtracking
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;

        util(n, k, 0, ans, {});

        return ans;
    }
};