// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// typedef long double ld;
// #define mp make_pair
// #define v vector
// #define pb push_back
// #define fi first
// #define se second
// #define ALL(v) v.begin(), v.end()
// #define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
// #define N 3003
// ll t;
// #define mod 1000000000
// ll powmod(ll x, ll y, ll p)
// {
//     ll res = 1; // Initialize result

//     x = x % p; // Update x if it is more than or
//                // equal to p

//     if (x == 0)
//         return 0; // In case x is divisible by p;

//     while (y > 0)
//     {
//         // If y is odd, multiply x with result
//         if (y & 1)
//             res = (res * x) % p;

//         // y must be even now
//         y = y >> 1; // y = y/2
//         x = (x * x) % p;
//     }
//     return res;
// }
// void fix(ll &val)
// {
//     if (val <= 0)
//     {
//         val = mod + val;
//     }
//     else if (val > mod)
//     {
//         val = val - mod;
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> t;
//     for (ll i = 1; i <= t; i++)
//     {
//         ll w, h, l, u, r, d;
//         cin >> w >> h >> l >> u >> r >> d;
//         v<v<ld>> p(w + 1, v<ld>(h + 1));
//         for (ll i = w; i >= 1; i--)
//         {
//             for (ll j = h; j >= 1; j--)
//             {
//                 if (i == w && j == h)
//                 {
//                     p[i][j] = 1.0;
//                     continue;
//                 }
//                 if (i >= l && i <= r && j >= u && j <= d)
//                 {
//                     p[i][j] = 0.0;
//                     continue;
//                 }
//                 if (i == w)
//                 {
//                     p[i][j] = p[i][j + 1];
//                     // cout << p[i][j + 1] << " " << i << " " << j + 1 << "\n";
//                 }
//                 else if (j == h)
//                     p[i][j] = p[i + 1][j];
//                 else
//                     p[i][j] = 0.5 * p[i + 1][j] + 0.5 * p[i][j + 1];
//                 // cout << i << " " << j << " " << p[i][j] << "\n";
//             }
//             // cout << "\n";
//         }
//         // for (ll i = 1; i <= w; i++)
//         // {
//         //     for (ll j = 1; j <= h; j++)
//         //         cout << p[i][j] << " ";
//         //     cout << "\n";
//         // }
//         // cout << "Case #" << i << ": ";
//         printf("Case #%lld: %0.8Lf\n", i, p[1][1]);
//     }
// }
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> a(N), cum(N);
int main()
{
    ll n, s, f;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        cum[i] = cum[i - 1] + a[i];
    }
    cin >> s >> f;
    ll temp = f - s;
    ll maxans = cum[temp], ans = INT_MAX;
    for (ll i = temp; i <= n; i++)
    {
        ll temp1 = cum[i] - cum[i - temp];
        if (maxans <= temp1)
        {
            ll temp2 = (s - i + temp + 5 * n) % n;
            temp2 = temp2 == 0 ? n : temp2;
            if (maxans == temp1)
                ans = min(ans, temp2);
            else
                ans = temp2;
        }
        maxans = max(maxans, temp1);
        // cout << ans << " " << maxans << "\n";
    }
    for (ll i = 1; i < temp; i++)
    {
        ll temp1 = cum[i] + cum[n] - cum[n - temp + i];
        if (maxans <= temp1)
        {
            ll temp2 = (s - n + temp - i + 5 * n) % n;
            temp2 = temp2 == 0 ? n : temp2;
            if (maxans == temp1)
                ans = min(ans, temp2);
            else
                ans = temp2;
        }

        maxans = max(maxans, temp1);
        // cout << ind << " " << maxans << "\n";
    }
    cout << ans << "\n";
}