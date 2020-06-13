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
#define N 500005
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
        v<v<ll>> a(n + 1, v<ll>(m + 1));
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                cin >> a[i][j];
        ll ans = 0;
        for (ll i = 0; i <= (n - 1 + m - 1) / 2; i++)
        {
            ll count = 0, totcount = 0;
            for (ll j = 1; j <= n; j++)
                for (ll k = 1; k <= m; k++)
                    if ((j - 1 + k - 1 == i || n - j + m - k == i) && (n - j + m - k != j - 1 + k - 1))
                    {
                        totcount++;
                        if (a[j][k] == 1)
                            count++;
                    }
            ans += min(count, totcount - count);
        }
        cout << ans << "\n";
    }
}