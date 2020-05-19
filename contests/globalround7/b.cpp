#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200005
ll n;
vector<ll> arr(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    ll maximum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += maximum;
        maximum = max(arr[i], maximum);
    }
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}