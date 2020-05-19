#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define mp make_pair
#define pii pair<ll, ll>
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 2002
#define mod 998244353

int n, k;
v<string> a(N);
v<v<pair<ll, ll>>> c(N);
v<map<ll, pair<ll, ll>>> c1(N);
v<ll> c2;
v<string> nos = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

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
ll comp(ll i, ll j)
{
    ll cnt = 0;
    for (ll k = 0; k < 7; k++)
    {
        if (a[i][k] == '1' && nos[j][k] == '0')
            return -1;
        if (a[i][k] == '0' && nos[j][k] == '1')
            cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 9; j >= 0; j--)
        {
            ll temp = comp(i, j);
            if (temp != -1)
            {
                c[i].pb(mp(temp, j));
            }
        }
    }
    for (ll i = 0; i < c[0].size(); i++)
    {
        if (c1[0].find(c[0][i].fi) == c1[0].end())
        {
            c2.pb(c[0][i].fi);
            c1[0][c[0][i].fi].fi = c[0][i].se;
            c1[0][c[0][i].fi].se = c[0][i].fi;
        }
    }
    // for (ll i = 0; i < c2.size(); i++)
    // {
    //     cout << c2[i] << " " << c1[0][c2[i]].fi << " ";
    // }
    // cout << "\n";
    for (ll i = 1; i < n; i++)
    {
        v<ll> c3;
        for (auto itr = c2.begin(); itr != c2.end(); itr++)
        {
            for (ll j = 0; j < c[i].size(); j++)
            {
                ll temp = *itr + c[i][j].fi;
                if (temp <= k && c1[i].find(temp) == c1[i].end())
                {
                    c3.pb(temp);
                    c1[i][temp].fi = c[i][j].se;
                    c1[i][temp].se = c[i][j].fi;
                }
            }
        }
        // for (ll j = 0; j < c3.size(); j++)
        //     cout << c3[j] << " " << c1[i][c3[j]].fi << " ";
        c2 = c3;
        // cout << "\n";
    }
    if (c1[n - 1].find(k) == c1[n - 1].end())
    {
        cout << -1 << "\n";
        return 0;
    }
    else
    {
        string ans;
        ll id = k - c1[n - 1][k].se;
        ans += (c1[n - 1][k].fi + 48);
        for (ll i = n - 2; i >= 0; i--)
        {
            ans += (c1[i][id].fi + 48);
            id -= c1[i][id].se;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}