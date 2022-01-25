class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        
        int i = 1;
        
        while(i<arr.size() && arr[i]>arr[i-1]) //increasing slope
            i++;
        
        if(i==1 || i==arr.size()) //if no incresing slope, or only increasing slope
            return false;
        
        while(i<arr.size() && arr[i]<arr[i-1]) //decreasing slope
            i++;
        
        return i==arr.size(); //if we encounter another increasing sequence it will return false
        
    }
};