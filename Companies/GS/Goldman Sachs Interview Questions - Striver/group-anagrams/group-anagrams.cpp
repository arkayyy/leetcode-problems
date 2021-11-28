class Solution {
public:
    //way to define a custom hash function for any type of data structure as the key of the unordered map
    struct vector_hash
    {
        template <class T1>
        size_t operator () (vector<T1> const &v) const
        {
            return hash<T1>()(v.size());    
        }
    };
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        //BRUTE FORCE soln. - TLE error:-
        
//         unordered_map<vector<int>,vector<string>,vector_hash> mp;
        
//         for(auto str: strs)
//         {
//             vector<int> freqmap(26,0);
//             for(auto c:str)
//             {
//                 freqmap[c-'a']++;
//             }
//             mp[freqmap].push_back(str);
//         }
        
//         for(auto freqm: mp)
//         {vector<string> temp;
//             for(auto s: freqm.second)
//                 temp.push_back(s);
//          ans.push_back(temp);
//         }
        
        
        //A bit more OPTIMAL APPROACH:-
        unordered_map<string,vector<string>> mp;
        
        for(auto str: strs)
        {
            string sortedString = str;
            sort(sortedString.begin(),sortedString.end());//by sorting, all anagrams will result to a same string (sorted one), which will be in turn used as the key to map all similar anagrams
            mp[sortedString].emplace_back(str);
        }
        
        for(auto ele: mp)
        {vector<string> t;
            for(auto s: ele.second)
            {
                t.emplace_back(s);
            }
         ans.push_back(t);
        }
        
        return ans;
    }
};