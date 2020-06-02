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
#define N 505
#define N1 12
#define N2 100005
#define mod 1000000007
#define INF INT_MAX

ll n, m, md;
v<string> s(N);

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

ll calc(ll x, ll nc2)
{
    ll temp = (nc2 * (nc2 - 1)) / 2;
    return (x * (temp % md)) % md;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> md;
    for (ll i = 0; i < m; i++)
        cin >> s[i];
    v<v<ll>> dp(n + 1, v<ll>(n + 1, 0));
    ll col1 = 0, col0 = 0;
    for (ll i = 0; i < n; i++)
    {
        ll ones = 0;
        for (ll j = 0; j < m; j++)
            if (s[j][i] == '1')
                ones++;
        if (ones == 0)
            col0++;
        else if (ones == 1)
            col1++;
    }
    dp[col0][col1] = 1;
    for (ll j = n; j >= 0; j--)
    {
        for (ll k = n; k >= 0; k--)
        {
            if (j + k <= n)
            {
                if (j + 2 <= n && k - 2 >= 0)
                    dp[j][k] = (dp[j][k] + calc(dp[j + 2][k - 2], j + 2)) % md;
                if (k + 2 <= n)
                    dp[j][k] = (dp[j][k] + calc(dp[j][k + 2], k + 2)) % md;
                if (j + 1 <= n)
                    dp[j][k] = (dp[j][k] + (((dp[j + 1][k] * (j + 1)) % md) * (k)) % md) % md;
            }
        }
    }
    ll ans = dp[0][0];
    cout << ans << "\n";
}