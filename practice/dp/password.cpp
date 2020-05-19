#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> prefix_function(string s)
{
    ll n = s.size();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> pre = prefix_function(s);
    string t = s;
    reverse(t.begin(), t.end());
    vector<ll> suf = prefix_function(t);
    ll y = pre[n - 1], x, z;
    ll ans = 0;
    string an;
    for (ll i = 1; i < n - 1; i++)
    {
        x = pre[i];
        if (x == y)
        {
            ans = max(ans, x);
        }
        else if (x > y)
        {
            ans = max(ans, y);
        }
        else if (x < y)
        {
            z = suf[n - i - 1 + x - 1];
            if (z == x)
            {
                ans = max(ans, z);
            }
        }
    }
    if (ans == 0)
    {
        cout << "Just a legend\n";
    }
    else
    {
        cout << s.substr(0, ans) << "\n";
    }
}