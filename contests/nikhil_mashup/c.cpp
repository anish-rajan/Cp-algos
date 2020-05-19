#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 1502
#define N1 8000001
#define N2 4000000
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, m;
v<ll> nos(N);
ll getInvCount(v<ll> arr, ll n)
{
    ll inv_count = 0;
    for (ll i = 0; i < n - 1; i++)
        for (ll j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> nos[i];
    ll t = getInvCount(nos, n);
    cin >> m;
    string s = t % 2 == 0 ? "even" : "odd";
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        ll temp = r - l + 1;
        temp = ((temp) * (temp - 1)) / 2;
        if (temp % 2 == 0)
        {
            if (s == "even")
                cout << "even\n";
            else
            {
                cout << "odd\n";
            }
        }
        else
        {
            if (s == "even")
            {
                cout << "odd\n";
                s = "odd";
            }
            else
            {
                cout << "even\n";
                s = "even";
            }
        }
    }
}