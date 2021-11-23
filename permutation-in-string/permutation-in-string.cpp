class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length()) return false;
        
        vector<int> hash1(26,0); vector<int> hash2(26,0);
        
        for(auto i:s1)
            hash1[i-'a']++;
        
        int len = s1.length();
        
        int i = 0;
        
        int j = i;
        
        while(j<len)
        {
            hash2[s2[j]-'a']++;
            j++;
        }
        
        if(hash1==hash2) return true;
        
         hash2[s2[i]-'a']--;
         i++;
        
        while(i+len-1 < s2.length())
        {

            hash2[s2[i+len-1]-'a']++;
            
            if(hash1==hash2) return true;
            
            hash2[s2[i]-'a']--;
            
            i++;

        }
        
        return false;
        
    }
};