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
#define N 100005
#define mod 1000000007
ll n, n1, k;
v<ll> a(N), luck, fact(N);
v<ll> dp(N);
map<ll, ll> cnt;
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
    for (ll i = 1; i <= 100001; i++)
        fact[i] = (i * fact[i - 1]) % mod;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll f = 1, temp = a[i];
        while (temp > 0)
        {
            if (temp % 10 != 4 && temp % 10 != 7)
                f = 0;
            temp /= 10;
        }
        if (f == 1)
            cnt[a[i]]++;
        else
            n1++;
    }
    for (auto itr = cnt.begin(); itr != cnt.end(); itr++)
        luck.pb(itr->second);

    dp[0] = 1;
    for (ll i = 0; i < luck.size(); i++)
    {
        for (ll j = 2000; j >= 1; j--)
        {
            dp[j] = (dp[j] + (dp[j - 1] * luck[i]) % mod) % mod;
        }
    }
    ll ans = 0;
    for (ll j = 0; j <= 2000 && j <= k; j++)
    {
        ll temp = k - j;
        // cout << ans << " " << dp[j] << " " << n1 << " " << temp << "\n";
        if (temp <= n1)
            ans = (ans + ((dp[j] * ((fact[n1] * ((powmod(fact[temp], mod - 2, mod) * powmod(fact[n1 - temp], mod - 2, mod)) % mod)) % mod)) % mod)) % mod;
    }
    cout << ans << "\n";
}