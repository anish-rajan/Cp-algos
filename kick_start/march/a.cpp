#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 200005
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll n, b;
        cin >> n >> b;
        vector<ll> arr(N);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.begin() + n);
        ll j = 0;
        ll counter = 0;
        while (b > 0 && j < n)
        {
            if (b - arr[j] >= 0)
            {
                b -= arr[j];
                counter++;
            }
            j++;
        }
        cout << "Case #" << i << ": " << counter << "\n";
    }
}