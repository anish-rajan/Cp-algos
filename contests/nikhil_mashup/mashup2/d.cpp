#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 102
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll n, m;
v<ll> arr(N), cum(N);
v<v<ll>> dp(N, v<ll>(N));
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + n);
    for (ll i = 1; i <= n; i++)
    {
        cum[i] = arr[i] + cum[i - 1];
    }
    ll ans = -1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (ll k = 0; k < j; k++)
            {
                ll sum = 0;
                for (ll p = k + 1; p <= j; p++)
                {
                    sum += max((ll)0, arr[p] - (p - k - 1));
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum);
                if (dp[i][j] >= m)
                {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}