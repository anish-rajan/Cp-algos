#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 100005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
bool is_right(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a = (ll)pow(x1 - x2, 2) + (ll)pow(y1 - y2, 2);
    ll b = (ll)pow(x2 - x3, 2) + (ll)pow(y2 - y3, 2);
    ll c = (ll)pow(x1 - x3, 2) + (ll)pow(y1 - y3, 2);
    if (a + b == c || b + c == a || c + a == b)
        return true;
    return false;
}
ld calc(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ld area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    area = abs(area);
    area /= 2;
    return area;
}
bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll f = 0;
    if (calc(x1 + 1, y1, x2, y2, x3, y3) > 0 && is_right(x1 + 1, y1, x2, y2, x3, y3))
    {
        f = 1;
    }
    if (calc(x1 - 1, y1, x2, y2, x3, y3) > 0 && is_right(x1 - 1, y1, x2, y2, x3, y3))
    {
        f = 1;
    }
    if (calc(x1, y1 + 1, x2, y2, x3, y3) > 0 && is_right(x1, y1 + 1, x2, y2, x3, y3))
    {
        f = 1;
    }
    if (calc(x1, y1 - 1, x2, y2, x3, y3) > 0 && is_right(x1, y1 - 1, x2, y2, x3, y3))
    {
        f = 1;
    }
    if (f == 1)
        return true;
    return false;
}
bool is_almost(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll f = 0;
    if (check(x1, y1, x2, y2, x3, y3) || check(x2, y2, x1, y1, x3, y3) || check(x3, y3, x1, y1, x2, y2))
    {
        f = 1;
    }
    if (f == 1)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (is_right(x1, y1, x2, y2, x3, y3))
    {
        cout << "RIGHT" << endl;
        return 0;
    }
    if (is_almost(x1, y1, x2, y2, x3, y3))
    {
        cout << "ALMOST" << endl;
        return 0;
    }
    cout << "NEITHER" << endl;
}