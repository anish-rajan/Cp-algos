#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 102
vector<double> arr(N);
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
    sort(arr.begin(), arr.begin() + n, greater<double>());
    double ans = 0;
    if (arr[0] == 1)
    {
        ans = 1;
    }
    else
    {
        double p = 1 - arr[0], s = arr[0] / (1 - arr[0]);
        ans = max(ans, p * s);
        for (ll i = 1; i < n; i++)
        {
            p *= 1 - arr[i];
            s += arr[i] / (1 - arr[i]);
            ans = max(ans, p * s);
        }
    }
    printf("%0.9f\n", ans);
}