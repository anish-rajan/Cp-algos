#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 505
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
v<v<ll>> ans(N, v<ll>(N));
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << -1 << "\n";
        return 0;
    }
    ll no = n * n;
    ans[0][0] = no;
    ans[1][2] = --no;
    ans[1][0] = --no;
    ans[0][2] = --no;
    ans[0][1] = --no;
    ans[2][2] = --no;
    ans[2][1] = --no;
    ans[1][1] = --no;
    ans[2][0] = --no;
    ll counter = 0;
    for (ll i = n - 1; i >= 3; i--)
    {
        if ((i + 1) % 2 == 0)
        {
            for (ll j = 0; j <= i; j++)
            {
                ans[j][i] = ++counter;
            }
            for (ll j = i - 1; j >= 0; j--)
            {
                ans[i][j] = ++counter;
            }
        }
        else
        {
            for (ll j = 0; j <= i; j++)
            {
                ans[i][j] = ++counter;
            }
            for (ll j = i - 1; j >= 0; j--)
            {
                ans[j][i] = ++counter;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}