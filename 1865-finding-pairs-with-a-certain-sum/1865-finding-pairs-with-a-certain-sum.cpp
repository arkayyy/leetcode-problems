class FindSumPairs {
    //INTUITION: If we can keep storing and updating frequencies of elements, we can count number of pairs at each call.
    
    //ALGO: Using two maps for both group of numbers, we can count the total suitable pairs by finding frequency of the difference(i.e. (total-(element from a map)) ) in other map
    private:
    vector<int> nums2New; //to store updated values
    map<int,int> mp1; //taking ordered map for first group of numbers so that we can avoid extra traversal of elements>=total, while counting pairs
    unordered_map<int,int> mp2; //taking hash map since we will be mainly finding in it, which takes only O(1) time 
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        nums2New = nums2;
        for(auto n:nums1) mp1[n]++;
        for(auto n:nums2) mp2[n]++;
    }
    
    void add(int index, int val) {
        mp2[nums2New[index]]--;
        nums2New[index]+=val;
        mp2[nums2New[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto m: mp1)
        {
            if(m.first>=tot)
                 break;
            if(mp2.count(tot-m.first))
                cnt+= (m.second * mp2[tot-m.first]);//adding count of all possible pairs
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */