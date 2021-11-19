class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {

        //BRUTE FORCE - gives TLE:-

        // unordered_map<int,int> noOfSetBits; //storing number of set bits of every unique number encountered
        //    int ans = 0;
        //   for(int i = 0;i<nums.size();i++)
        //   {
        //       for(int j = i+1; j<nums.size();j++)
        //       {
        //           int n = nums[i]^nums[j];
        //           if(noOfSetBits.find(n)==noOfSetBits.end())
        //           {
        //               while(n)
        //               {
        //                   ans++;
        //                   n &= (n-1);
        //                   if(noOfSetBits.find(n)!=noOfSetBits.end())
        //                       {
        //                       ans+= noOfSetBits[n];
        //                        break;}
        //               }
        //           }
        //           else
        //                ans+= noOfSetBits[n];
        //       }
        //    }
        //    return ans;

        //OPTIMAL approach:-
        //Go from 1st to 32nd bit in every number of the array, and check if they're set. If k numbers have a specific bit as set, (n-k) don't, so that (n-K) elements of the array will contribute towards Haming Dist.
        int ans = 0;
        for (int i = 1; i <= 32; i++)
        {
            int k = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] & (1 << (i - 1))) //checking if i th bit is set or not
                    k++;
            }
            ans += k * (nums.size() - k); //because total number pairs that can be formed between the k numbers (whose ith set bit is 1) and the (nik) numbers (whose ith set bit is 0) is = n*(n-k) i.e. total number of pairs in which ith bit of both numbers are different  ---- Simple Maths
        }
        return ans;
    }
};