class Solution {
    private:
    //simple arithmetic hashing using a prime no., can use any hashing algo
    unsigned int hash_function(const string& str) {
        unsigned int hash = 67;
        unsigned int prime = 79;

        for(int i = 0; i < str.size(); ++i) {
            int value = str[i];
            hash = hash ^ value;
            hash *= prime;
        }

        return hash;
    }
    
    unordered_map<string, string> long_to_short;
    unordered_map<string, string> short_to_long;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long_to_short[longUrl] = "http://tinyurl.com/" + to_string(hash_function(longUrl));
        short_to_long[long_to_short[longUrl]] = longUrl;
        return long_to_short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));v