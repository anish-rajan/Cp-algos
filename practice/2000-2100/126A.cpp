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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    ll t1, t2, x1, x2;
    ld t;
    cin >> t1 >> t2 >> x1 >> x2 >> t;
    ll ans1 = 0, ans2 = x2, ans = 0;
    if (t1 == t2)
        ans1 = x1;
    ld closer = INT64_MAX;
    for (ll i = 0; i <= x1; i++)
    {
        if (t2 == t)
            continue;
        ll x = ((t - t1) * i) / (t2 - t);
        if (i == 0 && x == 0)
            continue;
        ld temp = (t1 * i + t2 * x * 1.0) / (i + x);
        ld temp1 = (t1 * i + t2 * (x + 1) * 1.0) / (i + x + 1);
        if (temp >= t && abs(temp - t) <= closer && x <= x2)
        {
            closer = abs(temp - t);
            if (x + i >= ans)
                ans = x + i, ans1 = i, ans2 = x;
        }
        if (temp1 >= t && abs(temp1 - t) <= closer && x + 1 <= x2)
        {
            closer = abs(temp1 - t);
            if (x + 1 + i >= ans)
                ans = x + i + 1, ans1 = i, ans2 = x + 1;
        }
    }
    // ld temp = (t1 * ans1 + t2 * ans2 * 1.0) / (ans1 + ans2);
    // cout << temp << "\n";
    cout << ans1 << " " << ans2 << "\n";
}