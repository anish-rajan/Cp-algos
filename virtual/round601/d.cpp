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
#define N 300005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(1e6 + 2);
// v<ll> primes;

// long long powmod(long long x, long long y, long long m)
// {
//     long long res = 1LL;
//     while (y)
//     {
//         if (y & 1)
//             res = (res * x) % m;
//         x = (x * x) % m;
//         y /= 2;
//     }
//     return res;
// }

// void init_fact()
// {
//     fact[0] = 1;
//     for (ll i = 1; i < N; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
// }

// ll C(ll n, ll r)
// {
//     if (n < r)
//         return 0;
//     ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
//     temp *= powmod(fact[n - r], mod - 2, mod);
//     temp %= mod;
//     return temp;
// }

// void Sieve()
// {
//     for (ll i = 2; i <= 1e6 + 1; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j <= 1e6 + 2; j += i)
//             prime_check[j] = i;
//     }
// }
// ll phi(ll n)
// {
//     ll i, res = n;
//     for (i = 2; i * i <= n; i++)
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//                 n /= i;
//             res -= res / i;
//         }
//     if (n > 1)
//         res -= res / n;
//     return res;
// }

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll t, n, m, k;
v<v<ll>> used(102, v<ll>(102));
v<string> a(102);
using S = ll;

void bfs(S r, S c, ll no, ll ind)
{
    queue<pair<S, S>> q;
    ll tot = 0;
    q.push(mp(r, c));
    while (!q.empty())
    {
        auto v = q.front();
        used[v.fi][v.se] = true;
        if (a[v.fi][v.se] == 'R')
            tot++;
        a[v.fi][v.se] = ind;
        if (tot == no)
            return;
        q.pop();
        if (v.fi + 1 <= n && !used[v.fi + 1][v.se])
            q.push({v.fi + 1, v.se});
        if (v.fi - 1 >= 1 && !used[v.fi - 1][v.se])
            q.push({v.fi - 1, v.se});

        if (v.se + 1 <= m && !used[v.fi][v.se + 1])
            q.push({v.fi, v.se + 1});

        if (v.se - 1 >= 1 && !used[v.fi][v.se - 1])
            q.push({v.fi, v.se - 1});
    }
}

void dfs(ll r, ll c, ll no)
{
    if (r > n || r <= 0 || c > m || c <= 0 || a[r][c] != '.')
        return;
    a[r][c] = no;
    dfs(r - 1, c, no), dfs(r + 1, c, no), dfs(r, c - 1, no), dfs(r, c + 1, no);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    v<char> arr;
    for (ll i = 0; i <= 9; i++)
        arr.pb(i + 48);
    for (ll i = 'A'; i <= 'Z'; i++)
        arr.pb(i);
    for (ll i = 'a'; i <= 'z'; i++)
        arr.pb(i);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        ll r = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i].insert(a[i].begin(), '0');
            for (ll j = 1; j <= m; j++)
                if (a[i][j] == 'R')
                    r++;
        }
        ll no = r / k, no1 = r % k, ind = 0;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (!used[i][j] && a[i][j] == 'R')
                {
                    if (no1 > 0)
                        bfs(i, j, no + 1, arr[ind++]), no1--;
                    else
                        bfs(i, j, no, arr[ind++]);
                }
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
                if (a[i][j] != '.')
                    dfs(i - 1, j, a[i][j]), dfs(i + 1, j, a[i][j]), dfs(i, j - 1, a[i][j]), dfs(i, j + 1, a[i][j]);
        }
        set<char> reg;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                reg.insert(a[i][j]);
            }
        }
        if (reg.size() != ind)
        {
            cout << reg.size() << "\n";
            continue;
        }
        for (ll i = 1; i <= n; i++)
        {
            cout << a[i].substr(1, m) << "\n";
        }
        for (ll i = 1; i <= 100; i++)
        {
            a[i].clear();
            for (ll j = 1; j <= 100; j++)
                used[i][j] = false;
        }
    }
}