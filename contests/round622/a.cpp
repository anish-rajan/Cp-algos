#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> arr(3);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr.begin(), arr.end());
        ll sum = arr[0] + arr[1] + arr[2];
        ll ans = 0;
        for (ll i = 1; i <= sum; i++)
        {
            for (ll j = 0; j <= i; j++)
            {
                for (ll k = 0; k <= i; k++)
                {
                    ll l = i - j - k;
                    if (l <= 1 && j <= 1 && k <= 1 && l >= 0)
                    {
                        if (arr[0] - j >= 0 && arr[1] - k >= 0 && arr[2] - l >= 0)
                        {
                            ans++;
                            arr[0] -= j;
                            arr[1] -= k;
                            arr[2] -= l;
                            // cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}