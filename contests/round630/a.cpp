#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define N1 62 * 62
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll t;
bool check(ll a, ll b, ll x, ll x1, ll x2)
{
    bool p1 = true;
    if (a > b)
    {
        ll temp = a - b;
        if (temp > x - x1)
            p1 = false;
        if (x == x1 && x == x2 && (a > 0 || b > 0))
            p1 = false;
    }
    else
    {

        ll temp = b - a;
        if (temp > x2 - x)
            p1 = false;
        if (x == x1 && x == x2 && (a > 0 || b > 0))
            p1 = false;
    }
    return p1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll a, b, c, d, x, y, x1, x2, y1, y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        bool p1 = check(a, b, x, x1, x2);
        bool p2 = check(c, d, y, y1, y2);
        if (p1 && p2)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}