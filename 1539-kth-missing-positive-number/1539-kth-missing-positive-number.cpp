class Solution {
public:
    //INTUITION: To find a number of missing elements that just exceeds k
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size()-1;  
        
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1); 
            if(arr[mid]-mid-1 < k) lo = mid+1; //arr[mid]-(mid+1) signifies the total number of missing number that appears before arr[mid]
            else hi = mid-1;
        }
        return lo+k;
    }
};