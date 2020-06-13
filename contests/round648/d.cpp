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
v<v<char>> a(N, v<char>(N));
v<v<ll>> visited(N, v<ll>(N));
ll n, m;

void dfs(ll i, ll j, ll &g1)
{
    visited[i][j] = 1;
    if (a[i][j] == 'G')
        g1++;
    if (a[i][j] == 'B')
        g1--;
    if (i >= 2 && !visited[i - 1][j] && a[i - 1][j] != '#')
        dfs(i - 1, j, g1);
    if (i <= n - 1 && !visited[i + 1][j] && a[i + 1][j] != '#')
        dfs(i + 1, j, g1);
    if (j >= 2 && !visited[i][j - 1] && a[i][j - 1] != '#')
        dfs(i, j - 1, g1);
    if (j <= m - 1 && !visited[i][j + 1] && a[i][j + 1] != '#')
        dfs(i, j + 1, g1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll g = 0;
        ll g1 = 0;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'G')
                    g++;
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
                if (a[i][j] == 'B')
                {
                    if (a[i - 1][j] != 'B' && a[i - 1][j] != 'G')
                        a[i - 1][j] = '#';
                    if (a[i + 1][j] != 'B' && a[i + 1][j] != 'G')
                        a[i + 1][j] = '#';
                    if (a[i][j - 1] != 'B' && a[i][j - 1] != 'G')
                        a[i][j - 1] = '#';
                    if (a[i][j + 1] != 'B' && a[i][j + 1] != 'G')
                        a[i][j + 1] = '#';
                }
        }
        if (a[n][m] != '#')
            dfs(n, m, g1);
        if (g1 == g)
            cout << "Yes\n";
        else
            cout << "No\n";
        for (ll i = 0; i <= n; i++)
            fill(visited[i].begin(), visited[i].end(), 0);
    }
}