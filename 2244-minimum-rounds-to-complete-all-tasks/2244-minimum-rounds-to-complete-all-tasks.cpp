class Solution {
public:
    //INTUITION: We can greedily want to minimize the no. of rounds by taking max no. of 3 task groups possible.
    //Now whatever the number of tasks be, it can either be divisible by 3, or leave a remainder of 1 or 2 when divided by 3.
    
    //Say 8 tasks are there ########...we can group them like ###/###/##, so remainder of 2, and 2 tasks are grouped into an extra group
    //Say 7 tasks are there #######.. we can divide like ###/###/#, that would leave 1 task ungrouped, so we would group it like ###/##/##
    //So in both cases of remainder 1 or 2 when divided by 3, we need to create an extra group apart from the 3-task groups
    
    
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto t:tasks) ++mp[t];
        int ans = 0;
        for(auto m:mp) {
            if(m.second==1) return -1;
            ans+=m.second/3 + (m.second%3!=0 ? 1 : 0); //adding 1 extra group only when dividing by 3 leaves a remainder(either 1 or 2)
        }
        return ans;
    }
};