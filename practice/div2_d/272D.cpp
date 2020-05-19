#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 200005
vector<pair<ll, ll>> arr;
vector<ll> dp(N);
ll n, m;
ll compute_factmod(ll no, ll k)
{
    ll fact = 1;
    for (ll i = 1; i <= no; i++)
    {
        if (k > 0 && i % 2 == 0)
        {
            fact = (fact * (i / 2)) % m;
            k--;
        }
        else
        {
            fact = (fact * i) % m;
        }
    }
    return fact;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        arr.push_back(make_pair(val, i));
    }
    for (ll i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        arr.push_back(make_pair(val, i));
    }
    cin >> m;
    sort(arr.begin(), arr.end());
    arr.push_back(make_pair(0, 0));
    ll no = 1, k = 0;
    ll ans = 1;
    for (ll i = 0; i < arr.size(); i++)
    {
        // cout << arr[i].first << " " << arr[i + 1].first << "\n";
        if (arr[i].first == arr[i + 1].first)
        {
            no++;
            if (arr[i].second == arr[i + 1].second)
                k++;
        }
        else
        {
            ll temp = compute_factmod(no, k);
            // cout << i << " " << no << " " << temp << "\n";
            ans = (ans * temp) % m;
            no = 1, k = 0;
        }
    }
    cout << ans << "\n";
}