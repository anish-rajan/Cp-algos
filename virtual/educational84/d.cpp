#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 1000006
#define mod 998244353
#define INF INT_MAX

ll t;
v<ll> fact(N);
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    for (ll i = 1; i <= 1000005; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    ll n, m;
    cin >> n >> m;
    if (n <= 2)
    {
        cout << 0 << "\n";
        return 0;
    }
    ll ans = 0;
    ll temp = powmod(fact[n - 1], mod - 2, mod), temp1 = powmod(fact[m - n + 1], mod - 2, mod);
    temp = (temp * temp1) % mod;
    // cout << temp << " " << fact[m] << "\n";
    ll no = (fact[m] * ((temp * fact[n - 2]) % mod)) % mod;
    // cout << no << "\n";
    for (ll i = 2; i <= n - 1; i++)
    {
        ll temp = (powmod(fact[i - 2], mod - 2, mod) * powmod(fact[n - i - 1], mod - 2, mod)) % mod;
        ans = (ans + ((temp * no) % mod)) % mod;
    }
    cout << ans << "\n";
}