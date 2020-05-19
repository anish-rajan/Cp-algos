#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 140000
vector<ll> a(N), t(4 * N);
void build(ll v, ll tl, ll tr, ll n)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(v * 2, tl, tm, n - 1);
        build(v * 2 + 1, tm + 1, tr, n - 1);
        if (n % 2 == 1)
            t[v] = t[v * 2] | t[v * 2 + 1];
        else
            t[v] = t[2 * v] ^ t[2 * v + 1];
    }
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val, ll n)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val, n - 1);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val, n - 1);

        if (n % 2 == 1)
            t[v] = t[v * 2] | t[v * 2 + 1];
        else
            t[v] = t[2 * v] ^ t[2 * v + 1];
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < (ll)pow(2, n); i++)
        cin >> a[i];
    build(1, 0, (ll)pow(2, n) - 1, n);
    // for (ll i = 1; i < 4 * (ll)pow(2, n); i++)
    // {
    //     cout << t[i] << " ";
    // }
    while (m--)
    {
        ll ind, val;
        cin >> ind >> val;
        update(1, 0, (ll)pow(2, n) - 1, ind - 1, val, n);
        // for (ll i = 1; i < 4 * (ll)pow(2, n); i++)
        // {
        //     cout << t[i] << " ";
        // }
        cout << t[1] << "\n";
    }
}
