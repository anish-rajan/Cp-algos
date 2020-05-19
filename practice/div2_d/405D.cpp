#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 500005
#define N1 1000006
ll n;
vector<ll> arr(N), arr1(N1);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr1[arr[i]] = 1;
    }
    cout << n << "\n";
    vector<ll> possib, ans;
    for (ll i = 1; i <= 500000; i++)
    {
        if (arr1[i] == 0 && arr1[1000000 - i + 1] == 0)
            possib.push_back(i);
    }
    ll p = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr1[arr[i]] && arr1[1000000 - arr[i] + 1])
        {
            if (arr[i] < 1000000 - arr[i] + 1)
            {
                ans.push_back(possib[p]);
                ans.push_back(1000000 - possib[p++] + 1);
            }
        }
        else
        {
            ans.push_back(1000000 - arr[i] + 1);
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}