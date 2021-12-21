class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {

        // NORMAL Sorting approach:-

        // sort(arr.begin(),arr.end());
        vector<vector<int>> ans;

        int minDiff = INT_MAX;

        //         for(int i = 0;i<arr.size()-1;i++)
        //         {
        //             if(abs(arr[i]-arr[i+1])==minDiff)
        //                 ans.push_back({arr[i],arr[i+1]});

        //             else if(abs(arr[i]-arr[i+1]) < minDiff)
        //             {
        //                 minDiff = abs(arr[i]-arr[i+1]);
        //                 ans.clear();
        //                 ans.push_back({arr[i],arr[i+1]});
        //             }
        //         }

        //         return ans;

        // Counting sort approach (TC: O(N)):-
        int mini = (*min_element(arr.begin(), arr.end()));
        int maxi = *max_element(arr.begin(), arr.end());

        int n;

        n = maxi - mini + 1;

        vector<int> freq(n, 0);

        if (mini < 0) // if the min element is negative, the indexing of frequency array will be a bit different
        {
            for (int i = 0; i < arr.size(); i++)
                freq[arr[i] + abs(mini)]++;
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                for (int k = freq[i]; k > 0; k--)
                    arr[j++] = i - abs(mini);
            }
        }
        else
        { // is min element is >=0 indexing will be a bit different (do in notebook you'll understand)
            for (int i = 0; i < arr.size(); i++)
                freq[arr[i] - abs(mini)]++;
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                for (int k = freq[i]; k > 0; k--)
                    arr[j++] = i + abs(mini);
            }
        }

        // finally calculating minDiff and simultaneously storing answer array
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (abs(arr[i] - arr[i + 1]) == minDiff)
                ans.push_back({arr[i], arr[i + 1]});

            else if (abs(arr[i] - arr[i + 1]) < minDiff)
            {
                minDiff = abs(arr[i] - arr[i + 1]);
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};