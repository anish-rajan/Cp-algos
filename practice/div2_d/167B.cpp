#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 202
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, l, k;
ld p1, p2, p3, p4;
v<pair<ll, ld>> b, pr;
v<ld> p(N);
v<v<ld>> dp(N, v<ld>(N));
v<ld> dp1(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        p[i] /= 100;
    }
    p1 = 1, p2 = 1, p3 = 1, p4 = 1;
    ll offset = 0, offset1 = 0, c1 = 0, c2 = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll te;
        cin >> te;
        if (p[i] != 1)
            if (te == -1)
            {
                p4 *= (1 - p[i]);
                p2 *= (1 - p[i]);
                pr.pb(mp(1, p[i]));
            }
            else
            {
                p3 *= (1 - p[i]);
                p1 *= (1 - p[i]);
                // cout << p1 << " " << i << " ";
                b.pb(mp(te, p[i]));
            }
        else
        {
            if (te == -1)
            {
                p2 *= (1 - p[i]);
                offset1++;
                c2++;
            }
            else
            {
                p1 *= (1 - p[i]);
                c1++;
                offset += te;
            }
        }
    }
    b.insert(b.begin(), mp(0, 0));
    pr.insert(pr.begin(), mp(0, 0));
    // cout << "\n";
    for (ll s = 0; s <= min(offset, n); s++)
        dp[c1][s] = p3;
    for (ll i = 0; i < b.size(); i++)
    {
        for (ll j = n; j >= 0; j--)
        {
            for (ll s = n; s >= 0; s--)
            {
                if (j == 0 && s == 0)
                    dp[j][s] = p1;
                else if (s - b[i].fi >= 0 && j - 1 >= 0)
                    dp[j][s] += dp[j - 1][s - b[i].fi] * b[i].se / (1 - b[i].se);
                else if (j - 1 >= 0)
                    dp[j][s] += dp[j - 1][0] * b[i].se / (1 - b[i].se);
            }
        }
    }
    dp1[c2] = p4;
    for (ll i = 0; i < pr.size(); i++)
    {
        for (ll j = n; j >= 0; j--)
        {
            if (j == 0)
                dp1[j] = p2;
            else if (j - 1 >= 0)
                dp1[j] += dp1[j - 1] * pr[i].se / (1 - pr[i].se);
        }
    }
    // cout << p1 << " " << p2 << "\n";
    // for (ll i = 0; i <= n; i++)
    // {
    //     for (ll j = 0; j <= n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // for (ll i = 0; i <= n; i++)
    // {
    //     cout << dp1[i] << " ";
    // }
    // cout << "\n";
    ld ans = 0;
    for (ll i = l; i <= n; i++)
    {
        for (ll j = 0; j <= i; j++)
        {
            if (j - k >= 0)
            {
                ans += dp1[j] * (dp[i - j][j - k]);
            }
            else
            {
                ans += dp1[j] * (dp[i - j][0]);
            }
            // cout << ans << " ";
        }
    }
    // ans = min(ans, (ld)1);
    // cout << ans << "\n";
    printf("%0.10Lf\n", ans);
}