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
#define N 1005
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

ll n, m, k, x1, x2, y2;
v<string> a(N);
v<v<ll>> used(N, v<ll>(N)), dp(N, v<ll>(N)), dp1(N, v<ll>(N)), dp2(N, v<ll>(N)), dp3(N, v<ll>(N));
v<set<ll>> row(N), col(N);
using S = ll;
void bfs(S r, S c)
{
    queue<pair<S, S>> q;
    q.push(mp(r, c));
    used[r][c] = true;
    row[r].erase(c), col[c].erase(r);
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        ll x = v.fi, y = v.se;
        // cout << x << " " << y << "\n";
        auto itr = row[x].lower_bound(y - min(dp1[x][y], k)), itr1 = itr;
        for (; itr != row[x].end() && *itr <= y + min(dp3[x][y], k);)
            q.push(mp(x, *itr)), used[x][*itr] = used[x][y] + 1, itr1 = itr, itr++, col[*itr1].erase(x), row[x].erase(itr1);
        itr = col[y].lower_bound(x - min(dp[x][y], k));
        for (; itr != col[y].end() && *itr <= x + min(dp2[x][y], k);)
            q.push(mp(*itr, y)), used[*itr][y] = used[x][y] + 1, itr1 = itr, itr++, row[*itr1].erase(y), col[y].erase(itr1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], a[i].insert(a[i].begin(), '0');
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (a[i][j] == '#')
                dp[i][j] = dp1[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + 1, dp1[i][j] = dp1[i][j - 1] + 1;
        }
    }
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = m; j >= 1; j--)
            if (a[i][j] == '#')
                dp2[i][j] = dp3[i][j] = 0;
            else
                dp2[i][j] = dp2[i + 1][j] + 1, dp3[i][j] = dp3[i][j + 1] + 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
            if (a[i][j] == '.')
                row[i].insert(j), col[j].insert(i);
    }
    ll y1;
    cin >> x1 >> y1 >> x2 >> y2;
    bfs(x1, y1);
    cout << used[x2][y2] - 1 << "\n";
}