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
#define N 504
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

ll n;
v<ll> a(N);

struct Node
{
    ll st, end, len;
    Node(ll start, ll en, ll length) : st(start), end(en), len(length) {}
};
v<v<Node>> dp(N, v<Node>(N, Node(0, 0, 0)));

void chmin(Node &a, Node b)
{
    a = a.len < b.len ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    // auto a = Node(1, 1, 1);
    // cout << a.st << "\n";
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][i] = {a[i], a[i], 1};
        if (i >= 2)
            dp[i - 1][i] = (a[i - 1] == a[i] ? Node(a[i] + 1, a[i] + 1, 1) : Node(a[i - 1], a[i], 2));
    }
    for (ll i = 3; i <= n; i++)
    {
        for (ll j = 1; j + i - 1 <= n; j++)
        {
            dp[j][j + i - 1] = {dp[j][j + i - 2].st, a[j + i - 1], dp[j][j + i - 2].len + 1};
            for (ll k = j; k < j + i - 1; k++)
            {
                ll st1 = dp[j][k].st, en1 = dp[j][k].end, len1 = dp[j][k].len;
                ll st2 = dp[k + 1][j + i - 1].st, en2 = dp[k + 1][j + i - 1].end, len2 = dp[k + 1][j + i - 1].len;
                if (en1 == st2)
                {
                    ll mid = en1 + 1;
                    if ((mid == en2 && len2 <= 2) || len2 == 1)
                    {
                        if (len2 == 2)
                        {
                            mid++;
                            len2--;
                        }
                        if ((len1 <= 2 && mid == st1) || len1 == 1)
                        {
                            if (len1 == 2)
                            {
                                mid++;
                                len1--;
                            }
                            chmin(dp[j][j + i - 1], Node(mid, mid, 1));
                        }
                        else
                            chmin(dp[j][j + i - 1], Node(st1, mid, len1));
                    }
                    else if ((mid == st1 && len1 <= 2) || len1 == 1)
                    {
                        if (len1 == 2)
                        {
                            mid++;
                            len1--;
                        }
                        if ((len2 <= 2 && mid == en1) || len2 == 1)
                        {
                            if (len2 == 2)
                            {
                                mid++;
                                len2--;
                            }
                            chmin(dp[j][j + i - 1], Node(mid, mid, 1));
                        }
                        else
                            chmin(dp[j][j + i - 1], Node(mid, en2, len2));
                    }
                    else
                        chmin(dp[j][j + i - 1], Node(st1, en2, len1 + len2 - 1));
                }
                else
                    chmin(dp[j][j + i - 1], Node(st1, en2, len1 + len2));
            }
        }
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= n; j++)
    //         cout << dp[i][j].len << " ";
    //     cout << "\n";
    // }
    cout << dp[1][n].len << "\n";
}