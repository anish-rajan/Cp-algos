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
#define N 200005
#define mod 998244353
set<pair<ll, ll>> len, segements;
ll n;
v<ll> a(N);
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
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n;)
    {
        ll j = i;
        while (j <= n)
        {
            if (a[j] != a[i])
                break;
            j++;
        }
        len.insert(mp(i - j, i));
        segements.insert(mp(i, j - i));
        i = j;
    }
    ll ans = 0;
    while (!len.empty())
    {
        auto temp = *len.begin();
        auto itr = segements.lower_bound(mp(temp.se, -temp.fi));
        auto itr1 = segements.end();
        itr1--;
        if (itr != segements.begin() && itr != itr1)
        {
            auto itr2 = itr, itr3 = itr;
            itr2--, itr3++;
            auto t2 = *itr2, t3 = *itr3;
            if (a[t2.fi] == a[t3.fi])
            {
                auto t4 = mp(t2.fi, t2.se + t3.se);
                segements.erase(t2);
                segements.erase(t3);
                len.erase(mp(-t2.se, t2.fi));
                len.erase(mp(-t3.se, t3.fi));
                segements.insert(t4);
                len.insert(mp(-t4.se, t4.fi));
            }
        }
        len.erase(temp);
        segements.erase(mp(temp.se, -temp.fi));
        // cout << temp.fi << " " << temp.se << " " << len.size() << " " << segements.size() << "\n";
        ans++;
    }
    cout << ans << "\n";
}