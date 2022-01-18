class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()==1) {if(n) return flowerbed[0]==0; else return true;} //if only one element exists and n>1 the element needs to be 0
        
        int i = 1;
        
        if(flowerbed[0]==0 && flowerbed[1]==0) //if condition is satisfied at the very first index
            {i++; n--;}
        
        while(n>0 && i<flowerbed.size()-1)
        {
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0) //condition satisfied: no adjacents
                {n--; i+=2;}
            else i++;
        }
                
        if(n>0 && i==flowerbed.size()-1 && flowerbed[i]==0 && flowerbed[i-1]==0) //if we arrive at last index and we have flower(s) left to be planted
            n--;
        
        return n==0;
    }
};