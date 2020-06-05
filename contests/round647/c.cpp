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
#define N 3003
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

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

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    ll p1 = (ll)log2(1e18) + 2;
    v<ll> a(p1), cum(p1);
    v<ll> pow2;
    a[0] = 1, a[1] = 3;
    cum[0] = 1;
    for (ll i = 1; i <= p1 - 1; i++)
        a[i] = cum[i - 1] + i + 1, cum[i] = cum[i - 1] + a[i];
    ll p2 = 1;
    while (p2 <= 1e18)
    {
        pow2.pb(p2);
        p2 *= 2;
        // cout << pow2.back() << " ";
    }
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        while (n > 0)
        {
            ll p = log2(n);
            if (pow2[p] > n)
                p--;
            // cout << (ld)p << " ";
            ans += a[p];
            // cout << p << " " << a[p] << "\n";
            p = pow2[p];
            // cout << p << " " << 2 * p << " " << n << "\n";
            n -= p;
        }
        cout << ans << "\n";
    }
}