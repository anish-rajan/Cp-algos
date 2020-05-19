#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 200005
#define mod 998244353
ll t;
v<ll> pow2(32);
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
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (s[k - 1] != s[0])
        {
            cout << s[k - 1] << "\n";
            continue;
        }
        v<string> ans(k);
        for (ll i = 0; i < k; i++)
        {
            for (ll j = i; j < n; j += k)
            {
                ans[i] += s[j];
            }
        }
        sort(ans.begin(), ans.end());
        char temp = ans[k - 1].back();
        string temp1 = s.substr(k - 1, n - k + 1);
        ll f = 0;
        for (ll i = 0; i < k - 1; i++)
        {
            for (ll j = 1; j < ans[i].size(); j++)
                if (ans[i][j] != temp)
                {
                    f = 1;
                    break;
                }
        }
        if (f == 0)
        {
            cout << ans[k - 1] << "\n";
        }
        else
            cout << temp1 << "\n";
    }
}