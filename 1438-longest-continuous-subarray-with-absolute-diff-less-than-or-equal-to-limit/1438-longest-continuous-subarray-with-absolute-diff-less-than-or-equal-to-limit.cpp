class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //--------------APPROACH 1: Multiset------------------//
        // int i = 0, j;
        // multiset<int> m;
        // for (j = 0; j < nums.size(); ++j) {
        //     m.insert(nums[j]);
        //     if (*m.rbegin() - *m.begin() > limit)
        //         m.erase(m.find(nums[i++]));
        // }
        // return j - i;
        
        //-------------APPROACH 2: 2 Monotonic Dequeues--------------------//
        deque<int> maxd, mind;
        int i = 0, j;
        for (j = 0; j < nums.size(); ++j) {
            while (!maxd.empty() && nums[j] > maxd.back()) maxd.pop_back(); 
            while (!mind.empty() && nums[j] < mind.back()) mind.pop_back();
            maxd.push_back(nums[j]);//maxd stores number in descending order from start to end
            mind.push_back(nums[j]);//mind stores number in ascending order from start to end
            if (maxd.front() - mind.front() > limit) { //maxd.front() - min. element till now
                //mind.front() - max element till now
                if (maxd.front() == nums[i]) maxd.pop_front();
                if (mind.front() == nums[i]) mind.pop_front();
                ++i;
            }
        }
        return nums.size() - i;
    }
};