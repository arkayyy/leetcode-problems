class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //Nice method but involves changing the input matrix which is not preferred:-
        
//         int xor1 = nums[0];
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[abs(nums[i])]<0)
//                 return abs(nums[i]);
            
//             nums[abs(nums[i])] = -1 * (nums[abs(nums[i])]);

//         }
//         return -1;
        
        //OPTIMAL METHOD:- (Floyd Cycle Method)
        int slo = nums[0], fast = nums[0];
        slo = nums[slo];  //initial step of slo
        fast = nums[nums[fast]];  //initial step of fast (fast takes step of double size than slo)
        
        while(slo!=fast)
        {
            slo = nums[slo];
            fast = nums[nums[fast]];          //moving fast at double speed than slo, until slo is equal to fast (i.e if cycle is detected)
        }
        
        fast = nums[0];
        
        while(slo!=fast)   //moving both at same speed
        {
            slo = nums[slo];
            fast = nums[fast];
        }
        
        return slo;
        
    }
};