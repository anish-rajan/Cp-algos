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
#define N 22
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
v<ll> primes;

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

void Sieve()
{
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll n, m, k;
v<v<ll>> a(N, v<ll>(N));
v<v<map<ll, ll>>> pos(N, v<map<ll, ll>>(N)), pos1(N, v<map<ll, ll>>(N));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            cin >> a[i][j];
    pos[1][1][a[1][1]] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (i - 1 + j - 1 <= n - i + 1 + m - j + 1)
            {
                if (i == 1 && j == 1)
                    continue;
                if (i == 1)
                {
                    for (auto x : pos[i][j - 1])
                    {
                        ll t = x.fi ^ a[i][j];
                        pos[i][j][t] += pos[i][j - 1][x.fi];
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
                else if (j == 1)
                {
                    for (auto x : pos[i - 1][j])
                    {
                        ll t = x.fi ^ a[i][j];
                        pos[i][j][t] += pos[i - 1][j][x.fi];
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
                else
                {
                    for (auto x : pos[i][j - 1])
                    {
                        ll t = x.fi ^ a[i][j];
                        pos[i][j][t] += pos[i][j - 1][x.fi];
                    }
                    for (auto x : pos[i - 1][j])
                    {
                        ll t = x.fi ^ a[i][j];
                        pos[i][j][t] += pos[i - 1][j][x.fi];
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
            }
        }
    }
    pos1[n][m][k]++;
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = m; j >= 1; j--)
        {
            if (i - 1 + j - 1 > n - i + 1 + m - j + 1)
            {
                if (i == 1 && j == 1)
                    continue;
                if (i == n)
                {
                    for (auto x : pos1[i][j + 1])
                    {
                        ll t = x.fi ^ a[i][j + 1];
                        pos1[i][j][t]++;
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos1[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
                else if (j == m)
                {
                    for (auto x : pos1[i + 1][j])
                    {
                        ll t = x.fi ^ a[i + 1][j];
                        pos1[i][j][t]++;
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos1[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
                else
                {
                    for (auto x : pos1[i][j + 1])
                    {
                        ll t = x.fi ^ a[i][j + 1];
                        pos1[i][j][t]++;
                    }
                    for (auto x : pos1[i + 1][j])
                    {
                        ll t = x.fi ^ a[i + 1][j];
                        pos1[i][j][t]++;
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos1[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (i - 1 + j - 1 > n - i + 1 + m - j + 1)
            {
                if (i == 1 && j == 1)
                    continue;
                if (i == 1)
                {
                    for (auto x : pos[i][j - 1])
                    {
                        ll t = x.fi ^ a[i][j];
                        if (pos1[i][j].find(t) != pos1[i][j].end())
                            pos[i][j][t] += pos[i][j - 1][x.fi];
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
                else if (j == 1)
                {
                    for (auto x : pos[i - 1][j])
                    {
                        ll t = x.fi ^ a[i][j];
                        if (pos1[i][j].find(t) != pos1[i][j].end())
                            pos[i][j][t] += pos[i - 1][j][x.fi];
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
                else
                {
                    for (auto x : pos[i][j - 1])
                    {
                        ll t = x.fi ^ a[i][j];
                        if (pos1[i][j].find(t) != pos1[i][j].end())
                            pos[i][j][t] += pos[i][j - 1][x.fi];
                    }
                    for (auto x : pos[i - 1][j])
                    {
                        ll t = x.fi ^ a[i][j];
                        if (pos1[i][j].find(t) != pos1[i][j].end())
                            pos[i][j][t] += pos[i - 1][j][x.fi];
                    }
                    // cout << i << " " << j << " ";
                    // for (auto x : pos[i][j])
                    //     cout << x.fi << " " << x.se << " ";
                    // cout << "\n";
                }
            }
        }
    }
    cout << pos[n][m][k] << "\n";
}