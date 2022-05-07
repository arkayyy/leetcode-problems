class Solution {
public:
    //INTUITION: Using a sliding window and an additional third pointer, we can determine the valid substring as well as
    //we can also find out the total number of unique substrings that can be made using each cluster of vowels
    //present in the string.
    
    //ALGO: Sliding window and three pointers...See HW Notes for visual explanations...
    int countVowelSubstrings(string word) {
        int j = 0, k = 0, vowels = 0, ans = 0;
        unordered_map<char,int> mp;
        mp['a'] = 0, mp['e'] = 0, mp['i'] = 0, mp['o'] = 0, mp['u'] = 0;
        for(int i = 0; i<word.size(); i++)
        {
            if(mp.find(word[i])!=mp.end()) //vowel found
            {
                vowels += (++mp[word[i]] == 1);//vowels increase only if a new vowel is found
                
                //Now we are looping k forward until there exists a valid all vowel substr b/w k and i :-
                while(vowels==5)
                    {vowels-= (--mp[word[k++]] == 0);} //vowels decreases only if all occurence of a vowel is eliminated
                
                ans+= (k-j); //because with the valid all vowel substr b/w k and i, every letter b/w k and j can also be associated to make a unique substring..
                //so adding all such possibilities to answer
            }
            else //consonant found
            {//resetting all vowel frequencies once any non vowel is found
                mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 0;
                vowels = 0;
                j = k = i+1; 
            }
        }
        
        return ans;
    }
};