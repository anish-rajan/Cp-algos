#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
vector<ll> arr(N);
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll sum1 = 0, sum2 = 0;
        for (ll j = 0; j < n; j++)
        {
            sum1 += max(arr[i], arr[j]);
            sum2 += min(arr[i], arr[j]);
        }
        ans = max(ans, max(sum1, sum2));
    }
    cout << ans << "\n";
}