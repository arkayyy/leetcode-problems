class Solution {
public:
    
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length()) return false;
        
        //MOST OPTIMAL Approach - SLIDING WINDOW - the window size would always be the length of string s1 whose characters we are looking for.
        
        vector<int> hash1(26,0); //frequency array of string s1
        vector<int> hash2(26,0); //freq array of string s2 (every window in s2's freq would be stored in this)
        
        for(auto i:s1)
            hash1[i-'a']++; //setting freq array for s1
        
        int len = s1.length();
        
        int i = 0;
        
        int j = i;
        
        while(j<len)  //setting one window characters freq in the freq array for intialization of window.
        {
            hash2[s2[j]-'a']++;    
            j++;
        }
        
        if(hash1==hash2) return true; //if already freq array found to be same for both, return true
        
        //shifting window by one character ahead: 
        hash2[s2[i]-'a']--; //decreasing freq of the removed character from the window
         i++; //moving starting position of window one step ahead
        
        while(i+len-1 < s2.length())
        {
            //including freq of the new character included in the window
            hash2[s2[i+len-1]-'a']++;
            
            if(hash1==hash2) return true;
            
            hash2[s2[i]-'a']--; //if same frequency array not found for s1 and the window of s2, removing the character at ith index's freq, and forwarding the starting point of the window one step ahead.
            
            i++;

        }
        
        return false;
        
    }
};