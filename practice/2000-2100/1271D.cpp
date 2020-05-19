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
#define N 5005
#define mod 998244353
ll n, m, k;
vector<ll> a(N), b(N), c(N), last(N);
v<v<ll>> dp(N, v<ll>(N, INT_MIN));

ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll f = 1;
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        last[i] = i;
    }
    ll sol = k;
    for (ll i = 1; i <= n; i++)
    {
        if (sol < a[i])
            f = 0;
        sol += b[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        last[y] = max(last[y], x);
    }
    dp[1][k] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = a[i]; j <= 5000; j++)
        {
            if (dp[i][j] >= 0)
                dp[i + 1][j + b[i]] = max(dp[i][j], dp[i + 1][j + b[i]]);
        }
        for (ll j = 1; j <= i; j++)
        {
            if (last[j] == i)
            {
                for (ll k = 1; k <= 5000; k++)
                {
                    dp[i + 1][k - 1] = max(dp[i + 1][k - 1], dp[i + 1][k] + c[j]);
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= 5000; i++)
    {
        ans = max(ans, dp[n + 1][i]);
    }
    if (f == 1)
        cout << ans << "\n";
    else
        cout << -1 << "\n";
}