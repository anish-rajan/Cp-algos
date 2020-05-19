#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> s(N), b(N);
ll a;
vector<pair<ll, ll>> diff;
ll possible(ll ans, ll &cost, ll a)
{
    for (ll i = 0; i < ans; i++)
    {
        if (s[ans - i - 1] < b[i])
        {
            if (a >= b[i] - s[ans - i - 1])
            {
                cost += s[ans - i - 1];
                a -= b[i] - s[ans - i - 1];
            }
            else
                return 0;
        }
        else
            cost += b[i];
    }
    if (a <= cost)
        cost -= a;
    else
        cost = 0;
    return 1;
}
int main()
{
    ll n, m, bikes = 0, cost = 0;
    cin >> n >> m >> a;
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(s.begin(), s.begin() + n, greater<ll>());
    sort(b.begin(), b.begin() + m);
    ll l = 0, r = min(n, m);
    while (l <= r)
    {
        ll cost1 = 0;
        ll mid = (l + r) / 2;
        if (!possible(mid, cost1, a))
        {
            r = mid - 1;
        }
        else
        {
            bikes = mid;
            cost = cost1;
            l = mid + 1;
        }
        // cout << l << " " << r << " " << bikes << " " << cost << "\n";
    }
    cout << bikes << " " << cost << "\n";
}