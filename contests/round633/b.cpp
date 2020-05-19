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
#define N 31622779
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        v<ll> a(n);
        multiset<ll> nos;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            nos.insert(a[i]);
        }
        v<ll> ans;
        // cout << nos.size();
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans.pb(*nos.begin());
                nos.erase(nos.begin());
            }
            else
            {
                auto itr = nos.end();
                itr--;
                ans.pb(*itr);
                nos.erase(itr);
            }
        }
        reverse(ans.begin(), ans.end());
        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}