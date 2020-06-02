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
#define N 55
#define mod 1000000007
#define INF INT_MAX
v<ll> fact(N);

ll n, k, a0, a1;
v<v<v<pair<ll, ll>>>> dp(N, v<v<pair<ll, ll>>>(N, v<pair<ll, ll>>(2)));

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

struct state
{
    ll x, y, moves, pl;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init_fact();
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        (val == 50 ? a0++ : a1++);
    }
    queue<state> q;
    q.push({a0, a1, 0, 0});
    dp[a0][a1][0].fi = 1, dp[a0][a1][0].se = 0;
    while (!q.empty())
    {
        auto p = q.front();
        if (p.x == a0 && p.y == a1 && p.pl == 1)
        {
            cout << dp[a0][a1][1].se << "\n"
                 << dp[a0][a1][1].fi << "\n";
            return 0;
        }
        q.pop();
        ll sh = 1 ^ p.pl;
        ll x2 = a0 - p.x;
        ll y2 = a1 - p.y;
        for (ll i = 0; i <= p.x; i++)
        {
            for (ll j = 0; j <= p.y; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                ll f1 = i + x2, f2 = j + y2;
                ll ways = C(p.x, i) * C(p.y, j) % mod;
                if (i * 50 + j * 100 <= k)
                {
                    if (dp[f1][f2][sh].fi == 0)
                    {
                        dp[f1][f2][sh].fi = ways * dp[p.x][p.y][p.pl].fi % mod;
                        dp[f1][f2][sh].se = p.moves + 1;
                        q.push({f1, f2, p.moves + 1, sh});
                    }
                    else if (dp[f1][f2][sh].se = p.moves + 1)
                    {
                        dp[f1][f2][sh].fi += ways * dp[p.x][p.y][p.pl].fi % mod;
                        dp[f1][f2][sh].fi %= mod;
                    }
                }
            }
        }
    }
    cout << -1 << "\n"
         << 0 << "\n";
    return 0;
}