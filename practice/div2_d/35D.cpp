#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 102
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, X;
vector<ll> arr(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> X;
    multiset<ll> vals;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] *= (n - i);
        vals.insert(arr[i]);
    }
    ll ans = 0;
    // cout << vals.size();
    while (X > 0 && !vals.empty())
    {
        ll temp = *vals.begin();
        // cout << temp << "\n";
        if (X >= temp)
        {
            ans++;
        }
        X -= temp;
        vals.erase(vals.begin());
        // for (auto itr = vals.begin(); itr != vals.end(); itr++)
        //     cout << *itr << " ";
        // cout << "\n";
    }
    cout << ans << "\n";
}