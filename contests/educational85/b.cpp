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
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 505
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n;
        ld x;
        cin >> n >> x;
        v<ld> a(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        ll ans = 0, count = 0;
        ld sum = 0;
        for (ll i = n; i >= 1; i--)
        {
            count++;
            sum += a[i];
            ld temp = (sum) / count;
            // cout << temp << " ";
            if (temp >= x)
            {
                ans++;
            }
            else
                break;
        }
        cout << ans << "\n";
    }
}