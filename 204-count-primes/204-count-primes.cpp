class Solution {
public:
    void buildSieve(vector<bool>& isPrime)
    {
        int n = isPrime.size()-1; //because size of isPrime is n+1
        for(int i = 2; i*i<=n; i++)
        {
            if(!isPrime[i]) continue;
            for(int j = i*i; j<=n; j+=i) //if i is marked as prime, marking all its multiples as not prime(by mathematical logic - multiples of a prime are never prime)
            {
                isPrime[j] = false;
            }
        }
    }
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        buildSieve(isPrime);
        int cnt = 0;
        for(int i = 2; i<n; i++)
            if(isPrime[i])
                cnt++;
        return cnt;
    }
};