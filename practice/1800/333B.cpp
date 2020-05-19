#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
#define N1 1003
vector<pair<ll, ll>> banned;
vector<ll> check(N1), check1(N1);
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        banned.push_back(make_pair(x, y));
        check[x] = 1, check1[y] = 1;
    }
    ll count = 0;
    for (ll i = 2; i <= n - 1; i++)
    {
        if (!check[i])
        {
            check[i] = 2;
            count++;
        }
    }
    for (ll i = 2; i <= n - 1; i++)
    {
        if (!check1[i])
        {
            if (!(n % 2 == 1 && i == n / 2 + 1 && check[i] == 2))
            {
                check1[i] = 2;
                count++;
            }
        }
    }
    cout << count << "\n";
}