#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll k;
    cin >> k;
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> ind;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ind.push_back(i);
    }
    ll n1 = ind.size();
    ll ans = 0;
    if (n1 == 0 && k == 0)
    {
        ans += (n * (n + 1)) / 2;
    }
    else if (k == 0 && n1 > 0)
    {
        ans += (ind[0] * (ind[0] + 1)) / 2;
        for (ll i = 1; i < n1; i++)
        {
            ll nos = ind[i] - ind[i - 1] - 1;
            ans += (nos * (nos + 1)) / 2;
        }
        ll nos = n - ind[n1 - 1] - 1;
        ans += (nos * (nos + 1)) / 2;
    }
    else
        for (ll i = 0; i + k - 1 < n1; i++)
        {
            ll be = 0, af = 0;
            if (i > 0)
                be = ind[i] - ind[i - 1] - 1;
            else
                be = ind[i];
            if (i + k < n1)
                af = ind[i + k] - ind[i + k - 1] - 1;
            else
                af = n - ind[i + k - 1] - 1;
            // cout << be << " " << af << "\n";
            ans += (af + 1) * (be + 1);
        }
    cout << ans << "\n";
}