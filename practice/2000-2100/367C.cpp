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
#define N 2000006
#define mod 1000000007
ll n, m;
v<pair<ll, ll>> cost(N);
v<ll> dp(N);
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
    for (ll i = 1; i <= 100005; i++)
    {
        dp[i] = i * (i - 1) / 2;
        if (i % 2 == 0)
            dp[i] += i / 2 - 1;
    }
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
        cin >> cost[i].se >> cost[i].fi;
    sort(cost.begin() + 1, cost.begin() + m + 1, greater<pair<ll, ll>>());
    ll ans = 0;
    for (ll i = 1; i <= m; i++)
    {
        if (dp[i] < n)
            ans += cost[i].fi;
        else
            break;
        // cout << cost[i].fi << " " << dp[i] << "\n";
    }
    cout << ans << "\n";
}