#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
vector<ll> arr(N);
ll n, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll maxvalue = -1, maxindex = -1, minindex = INT_MAX, ans = 0, minindex1 = INT_MAX, f = 0;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxvalue = max(maxvalue, arr[i]);
        }
        for (ll i = 0; i < n; i++)
        {
            if (maxvalue == arr[i] && f == 0)
            {
                maxindex = max(maxindex, i);
                minindex = min(minindex, i);
                f = 1;
            }
            else if (maxvalue == arr[i])
            {
                maxindex = max(maxindex, i);
                minindex1 = min(minindex1, i);
            }
        }
        // cout << minindex << " " << maxindex << "\n";
        if (minindex >= n / 2 || maxindex < n / 2)
        {
            ll temp = maxindex - minindex;
            ans = n / 2 - temp;
        }
        else if (minindex + n - minindex1 < n / 2)
        {
            ll temp = minindex + n - maxindex;
            ans = n / 2 - temp;
        }
        else
        {
            ans = 0;
        }
        cout << ans << "\n";
    }
}