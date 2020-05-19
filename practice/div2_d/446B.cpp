#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
vector<vector<ll>> arr(N, vector<ll>(N));
set<pair<ll, ll>, greater<pair<ll, ll>>> rows, cols;
vector<ll> dp(N *N), dp1(N *N);
ll n, m, k, p;
void suminsert()
{
    for (ll i = 0; i < n; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
        // cout << sum << "\n";
        rows.insert(make_pair(sum, i));
    }
    for (ll i = 0; i < m; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < n; j++)
        {
            sum += arr[j][i];
        }
        // cout << sum << "\n";
        cols.insert(make_pair(sum, i));
    }
}
int main()
{
    cin >> n >> m >> k >> p;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    suminsert();
    ll fr = 0, fc = 0, sat = INT64_MIN;
    ll i = 1;
    while (i <= k)
    {
        set<pair<ll, ll>>::iterator r = rows.begin(), c = cols.begin();
        pair<ll, ll> temp = *c;
        cols.erase(c);
        dp[i] = dp[i - 1] + temp.first;
        temp.first -= n * p;
        cols.insert(temp);

        temp = *r;
        rows.erase(r);
        dp1[i] = dp1[i - 1] + temp.first;
        temp.first -= m * p;
        rows.insert(temp);
        i++;
    }
    for (ll i = 0; i <= k; i++)
    {
        sat = max(sat, dp[i] + dp1[k - i] - (i) * (k - i) * p);
    }
    cout << sat << "\n";
}