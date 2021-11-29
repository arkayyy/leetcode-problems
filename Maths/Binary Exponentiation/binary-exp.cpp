#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    ll res = power(a, b / 2, m);

    if ((b & 1) == 0)
        return (res * res) % m;

    return (((res * res) % m) * a) % m;
}

//WITHOUT RECURSION (FASTER):-
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// a^b mod m calculation:-
long long binpowModM(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ll m = 998244353;
    cout << power(2, 6, m) << endl;

    return 0;
}