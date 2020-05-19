#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll n, m, k;
v<ll> arr(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr.begin(), arr.begin() + n);
    ll ans = 0, nob = 1, cur = k;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] > cur)
        {
            nob++;
            if (nob > m)
                break;
            cur = k - arr[i];
        }
        else
            cur -= arr[i];
        ans++;
    }
    cout << ans << endl;
    return 0;
}