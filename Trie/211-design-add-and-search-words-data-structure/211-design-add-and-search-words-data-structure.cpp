class WordDictionary {
    private:
    struct trie
    {
        bool endOfWord = false;
        vector<trie*>next = vector<trie*>(256,NULL);
        trie()
        {
            
        }
    };
public:
    trie* dict;
    WordDictionary() {
        dict = new trie();
    }
    
    void addWord(string word) {
        trie* curr = dict;
        int idx = 0;
        while(idx<word.size())
        {
            if(curr->next[(int)word[idx]])
            {
                curr = curr->next[(int)word[idx]];
            }
            else
            {
                curr->next[(int)word[idx]] = new trie();
                curr = curr->next[(int)word[idx]];
            }
            idx++;    
        }
        curr->endOfWord = true;
    }
    bool searchUtil(int idx,trie* curr, string word)
    {
        if(idx==word.size() && curr->endOfWord) return true;
        if(idx==word.size() && !curr->endOfWord) return false;
        if(word[idx]=='.')
        {
            bool ans = false;
            for(int i = 0; i<256; i++)
                if(curr->next[i]!=NULL)
                    ans = ans || searchUtil(idx+1, curr->next[i], word);
            return ans;
        }
        else
        {
            if(!curr->next[(int)word[idx]]) return false;
            return searchUtil(idx+1, curr->next[(int)word[idx]], word);
        }
    }
    bool search(string word) {
        return searchUtil(0, dict, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */