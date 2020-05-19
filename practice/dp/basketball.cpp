#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1004
vector<ll> s(N);
int main()
{
    ll n, m, h;
    cin >> n >> m >> h;
    ll t = 0;
    for (ll i = 0; i < m; i++)
    {
        cin >> s[i];
        t += s[i];
    }
    double ans = 1;
    if (t < n)
    {
        cout << "-1\n";
    }
    else
    {
        double ans = 1;
        for (ll i = t - n + 1; i <= t - 1; i++)
        {
            ans *= i;
        }
        for (ll i = t - s[h - 1] - n + 2; i <= t - s[h - 1]; i++)
        {
            ans /= i;
        }
        ans = 1 / ans;
        ans = 1 - ans;
        cout << ans << "\n";
    }
}