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
#define mod 1000000007
ll t;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        v<ll> a(n + 1), dp(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        dp[1] = 1;
        for (ll i = 2; i <= n; i++)
        {
            dp[i] = 1;
            for (ll j = 1; j <= (ll)sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    if (a[j] < a[i])
                        dp[i] = max(dp[j] + 1, dp[i]);
                    if (a[i / j] < a[i])
                        dp[i] = max(dp[i / j] + 1, dp[i]);
                }
            }
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
            ans = max(ans, dp[i]);
        cout << ans << "\n";
    }
}