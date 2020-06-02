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
#define N 600005
#define mod 998244353
#define INF INT_MAX

v<ll> a(N);
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

void comp_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}

ll ncr(ll n, ll r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;
    ll t1 = (powmod(fact[r], mod - 2, mod) * powmod(fact[n - r], mod - 2, mod)) % mod;
    t1 = (t1 * fact[n]) % mod;
    return t1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    comp_fact();
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll nos = n / i - 1;
        // cout << ncr(nos, k - 1) << " " << nos << " " << k - 1 << "\n";
        ans = (ans + ncr(nos, k - 1)) % mod;
    }
    cout << ans << '\n';
}