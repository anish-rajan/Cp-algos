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
ll t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        v<ll> t(n + 1, 0), l(n + 1, 0), h(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            cin >> t[i] >> l[i] >> h[i];
        ll f = 1;
        ll lt = m, ht = m;
        for (ll i = 1; i <= n; i++)
        {
            ll time = t[i] - t[i - 1];
            ll lt1 = lt, ht1 = ht;
            if (lt >= l[i])
                lt1 = max(l[i], lt1 - time);
            else
                lt1 = min(l[i], lt1 + time);
            if (ht >= h[i])
                ht1 = max(h[i], ht1 - time);
            else
                ht1 = min(h[i], ht1 + time);
            if (l[i] > ht1 || lt1 > h[i])
            {
                f = 0;
                break;
            }
            if (lt1 > lt)
            {
                lt = l[i];
                if (ht1 > h[i])
                    ht = h[i];
                else
                    ht = ht1;
            }
            else
            {
                lt = lt1;
                if (lt1 <= h[i] && ht1 > h[i])
                    ht = h[i];
                else
                    ht = ht1;
            }
            // cout << lt << " " << ht << "\n";
        }
        if (f == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}