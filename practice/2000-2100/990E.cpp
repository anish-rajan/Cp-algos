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
#define N 2000006
#define mod 1000000007
#define INF INT64_MAX

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

ll n, m, k;
v<ll> a(N), s(N), pre(N), nex(N);

ll comp(ll l)
{
    ll count = 0;
    for (ll i = 0; i < n;)
    {
        if (i - pre[i] >= l)
            return -1;
        i = pre[i] + l;
        count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m >> k;
    for (ll i = 1; i <= m; i++)
    {
        ll val;
        cin >> val;
        s[val] = 1;
    }
    s[n] = 1;
    for (ll i = 0; i <= n; i++)
    {
        if (!s[i])
            pre[i] = i;
        else if (i != 0)
            pre[i] = pre[i - 1];
        else
            pre[i] = -1;
    }
    for (ll i = n; i >= 0; i--)
    {
        if (!s[i] && i != n)
            nex[i] = i;
        else if (i != n)
            nex[i] = nex[i + 1];
        else
            nex[i] = n;
    }
    for (ll i = 1; i <= k; i++)
        cin >> a[i];
    if (pre[0] == -1)
    {
        cout << -1 << "\n";
        return 0;
    }
    ll ans = INF;
    for (ll i = 1; i <= k; i++)
    {
        ll temp = comp(i);
        // cout << i << " " << temp << "\n";
        if (temp != -1)
            ans = min(ans, a[i] * temp);
    }
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}