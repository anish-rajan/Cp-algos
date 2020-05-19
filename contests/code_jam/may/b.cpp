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
v<ll> inv(300);
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
ll decode(string s)
{
    ll p = 1, no = 0;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        no += p * inv[s[i]];
        p *= 10;
    }
    return no;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    ll fac = 1;
    for (ll i = 2; i <= 10; i++)
        fac *= i;
    for (ll i = 1; i <= t; i++)
    {
        ll u;
        cin >> u;
        set<char> chars;
        set<char> bchar;
        v<pair<ll, string>> q;
        for (ll i = 1; i <= 10000; i++)
        {
            ll m;
            string s;
            cin >> m >> s;
            q.pb(mp(m, s));
            for (ll i = 0; i < s.size(); i++)
                chars.insert(s[i]);
            bchar.insert(s[0]);
        }
        sort(q.begin(), q.end());
        v<char> ans;
        while (chars.size() < 10)
        {
            for (ll i = 'A'; i <= 'Z'; i++)
                if (chars.find(i) == chars.end())
                {
                    chars.insert(i);
                    break;
                }
        }
        for (auto itr = chars.begin(); itr != chars.end(); itr++)
            ans.pb(*itr);
        if (q[0].fi != -1)
            for (ll i = 1; i <= fac; i++)
            {
                ll f = 1;
                for (ll i = 0; i < ans.size(); i++)
                    inv[ans[i]] = i;
                for (ll i = 0; i < q.size(); i++)
                {
                    ll no = decode(q[i].se);
                    ll temp = log10(no) + 1;
                    if (no > q[i].fi || no == 0 || temp != q[i].se.size())
                    {
                        f = 0;
                        break;
                    }
                }
                if (f == 1)
                    break;
                next_permutation(ans.begin(), ans.end());
            }
        else
        {
            char beg = 'A';
            for (auto itr = chars.begin(); itr != chars.end(); itr++)
            {
                if (bchar.find(*itr) == bchar.end())
                    beg = *itr;
            }
            ans.clear();
            ans.pb(beg);
            for (auto itr = chars.begin(); itr != chars.end(); itr++)
            {
                if (ans[0] != *itr)
                    ans.pb(*itr);
            }
        }
        string s;
        for (ll i = 0; i < ans.size(); i++)
            s += ans[i];
        cout << "Case #" << i << ": " << s << "\n";
    }
}