#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
ll n;
vector<pair<ll, ll>> values(N);
vector<ll> used(N);
void updateused(ll val, ll ind)
{
    for (ll i = 1; i <= sqrt(val); i++)
    {
        if (val % i == 0)
        {
            used[i] = ind;
            ll temp = val / i;
            used[temp] = ind;
        }
    }
}
ll query_ans(ll val1, ll y, ll ind)
{
    ll ans = 0;
    ll temp1 = sqrt(val1);
    for (ll i = 1; i <= sqrt(val1); i++)
    {
        if (val1 % i == 0)
        {
            ll temp = val1 / i;
            if (used[i] < ind - y && y != 0)
                ans++;
            if (used[temp] < ind - y && y != 0)
                ans++;
            if (y == 0)
                ans += 2;
            // if (val1 == 18)
            //     cout << i << " " << ans << " " << used[i] << "\n";
        }
    }
    if (temp1 * temp1 == val1 && used[temp1] < ind - y && y != 0)
        ans--;
    if (y == 0 && temp1 * temp1 == val1)
        ans--;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    fill(used.begin(), used.end(), -1);
    for (ll i = 0; i < n; i++)
    {
        cin >> values[i].first >> values[i].second;
    }
    for (ll i = 0; i < n; i++)
    {
        if (values[i].second == 0)
        {
            cout << query_ans(values[i].first, values[i].second, i) << "\n";
            updateused(values[i].first, i);
        }
        else
        {
            cout << query_ans(values[i].first, values[i].second, i) << "\n";
            updateused(values[i].first, i);
        }
    }
}