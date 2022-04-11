class Trie {
    private:
    struct TrieNode
    {
        vector<TrieNode*> children;
        bool end;
        TrieNode()
        {
            end = false;
            children = vector<TrieNode*> (26,NULL);
        }
    };
    TrieNode* head = NULL;
public:
    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = head;
        for(auto ch:word)
        {
            if(!curr->children[ch-'a'])
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = head;
        for(auto ch: word)
        {
            if(!curr->children[ch-'a'])
                return false;
            curr = curr->children[ch-'a'];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = head;
        for(auto ch: prefix)
        {
            if(!curr->children[ch-'a'])
                return false;
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */