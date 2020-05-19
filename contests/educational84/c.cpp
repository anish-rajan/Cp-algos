#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
ll t;
vector<pair<ll, ll>> s(N), f(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0, r = 0, d = 0, u = 0;
    for (ll i = 0; i < k; i++)
    {
        cin >> s[i].first >> s[i].second;
    }
    for (ll i = 0; i < k; i++)
    {
        cin >> f[i].first >> f[i].second;
    }
    string temp;
    ll counter = n + m + n * m - 3;
    for (ll i = 1; i <= m - 1; i++)
        temp += 'L';
    for (ll i = 1; i <= n - 1; i++)
        temp += 'U';
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m - 1; j++)
        {
            if (i % 2)
                temp += 'R';
            else
                temp += 'L';
        }
        if (i < n)
            temp += 'D';
    }
    cout << counter << "\n";
    cout << temp << "\n";
}