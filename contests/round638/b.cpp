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
        v<ll> a(n + 1);
        v<ll> c(n + 1);
        set<ll> nos;
        v<ll> check(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            c[a[i]]++;
            nos.insert(a[i]);
        }
        if (nos.size() > k)
        {
            cout << -1 << "\n";
            continue;
        }
        v<ll> basic, ans;
        ll p;
        for (ll i = 1; i <= n; i++)
        {
            if (!check[a[i]])
            {
                basic.pb(a[i]);
                c[a[i]]--;
                nos.erase(a[i]);
                check[a[i]] = 1;
            }
            else
            {
                p = i;
                break;
            }
        }
        for (auto itr = nos.begin(); itr != nos.end(); itr++)
        {
            basic.pb(*itr);
        }
        ll cnt = basic.size();
        for (ll i = p; cnt < k; i++)
        {
            basic.pb(a[i]);
            cnt++;
        }
        ans = basic;
        for (ll i = 1; i <= n; i++)
        {
            while (c[i])
            {
                for (ll i = 0; i < basic.size(); i++)
                    ans.pb(basic[i]);
                c[i]--;
            }
        }
        cout << ans.size() << "\n";
        for (ll i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}