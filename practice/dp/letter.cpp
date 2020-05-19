#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> backu(n + 1);
    backu[n] = 0;
    ll ans = INT64_MAX;
    for (ll i = n - 1; i >= 0; i--)
    {
        backu[i] = backu[i + 1] + (s[i] >= 'A' && s[i] <= 'Z');
    }
    ll lower = 0;
    for (ll i = 0; i < n; i++)
    {
        ans = min(ans, lower + backu[i + 1]);
        lower = lower + (s[i] >= 'a' && s[i] <= 'z');
    }
    cout << ans << "\n";
}