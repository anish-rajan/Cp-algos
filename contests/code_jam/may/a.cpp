#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 3003
#define mod 998244353
ll t;
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
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll x, y, m;
        string s;
        cin >> x >> y >> s;
        ll ans = -1;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == 'N')
                y++;
            else if (s[i] == 'S')
                y--;
            else if (s[i] == 'E')
                x++;
            else
                x--;
            if (abs(x) + abs(y) <= i + 1)
            {
                ans = i + 1;
                break;
            }
        }
        if (ans == -1)
            cout << "Case #" << i << ": IMPOSSIBLE\n";
        else
            cout << "Case #" << i << ": " << ans << "\n";
    }
}