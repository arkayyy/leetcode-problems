class NumArray {
    private:
    vector<int> fen;
    int n;
    vector<int> copy;
    void updateFen(int index, int val)
    {
        int i = index;
        while(i<fen.size())
        {
            fen[i]+=val;
            i += (i&(-i));
        }
    }
    int sum(int i)
    {
        int res = 0;
        while(i>0)
        {
            res+=fen[i];
            i -= (i&(-i));
        }
        return res;
    }
public:
    NumArray(vector<int>& nums) {
        copy = nums;
        n = nums.size();
        fen.resize(n+1,0);
        for(int i = 0; i<n; i++)
            updateFen(i+1,nums[i]);
    }
    
    void update(int index, int val) {
        updateFen(index+1, val-sumRange(index,index));
    }
    
    int sumRange(int left, int right) {
        //if(left==right) return copy[left];
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */