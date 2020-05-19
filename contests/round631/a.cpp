#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 102
ll t;
vector<ll> arr(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll ans = 1;
        for (ll i = 1; i <= 202; i++)
        {
            v<ll> temp(i + 1);
            temp = {0};
            ll counter = 0;
            for (ll j = 0; j < n; j++)
            {
                if (arr[j] <= i)
                {
                    temp[arr[j]] = 1;
                }
            }
            for (ll j = 1; j <= i; j++)
            {
                counter += temp[j];
            }
            if (counter + x >= i)
                ans = max(ans, i);
        }
        cout << ans << endl;
    }
}