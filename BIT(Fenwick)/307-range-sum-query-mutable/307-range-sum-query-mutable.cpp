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
        n = nums.size();
        fen.resize(n+1,0);
        for(int i = 0; i<n; i++)
            updateFen(i+1,nums[i]); //i+1 is updated because 1 based indexing is followed
    }
    
    void update(int index, int val) {
        updateFen(index+1, val-sumRange(index,index)); //we are passing val-sumRange(index,index) which is same as val-nums[index]...we are passing the difference val-nums[i] because the elements to the right side of index in fenwick array need to be summed with this difference that is produced.
        //because fenwick already stores sum of a range of elements
    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left); //right+1 because 1 based indexing
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */