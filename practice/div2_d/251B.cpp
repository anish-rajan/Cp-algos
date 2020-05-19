#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 102
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, k;
v<ll> q(N), s(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    ll k1 = 0, k2 = 0;
    v<ll> p(N);
    for (ll i = 1; i <= n; i++)
    {
        cin >> q[i];
        p[i] = i;
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    v<ll> temp = p;
    ll i = 0;
    do
    {
        if (p == s)
            break;
        v<ll> temp1 = p;
        for (ll i = 1; i <= n; i++)
        {
            p[i] = temp1[q[i]];
        }
        k1++;
        i++;
    } while (i <= 105);
    p = temp, i = 0;
    do
    {
        if (p == s)
            break;
        v<ll> temp1 = p;
        for (ll i = 1; i <= n; i++)
        {
            p[q[i]] = temp1[i];
        }
        k2++;
        i++;
    } while (i <= 105);

    // cout << k1 << " " << k2 << "\n";
    if (k < min(k1, k2) || k1 == 0 || k2 == 0 || (k > 1 && k1 == 1 && k2 == 1))
    {
        cout << "NO\n";
        return 0;
    }
    if ((k >= k1 && k1 % 2 == k % 2) || (k >= k2 && k2 % 2 == k % 2))
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}