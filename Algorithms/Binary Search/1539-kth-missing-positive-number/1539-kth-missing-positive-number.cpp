class Solution {
public:
    //INTUITION: To find a number of missing elements that just exceeds k
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size()-1;  
        
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1); 
            if(arr[mid]-(mid+1) < k) lo = mid+1; //arr[mid]-(mid+1) signifies the total number of missing number that appears before arr[mid]..because (mid+1) was the expected value at the index mid. 
            //But if the number of missing elements before mid index is less than k, we need to shift to searching in the right section of our range of bin search
            else hi = mid-1; //if kth missing lies in the first half..we shift there
        }
        return lo+k;
    }
};