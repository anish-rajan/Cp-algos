#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<pair<ll, ll>> points;
int main()
{
    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    ll x = x0, y = y0;
    ll n = 0;
    while (x + y <= 1000000000000000000)
    {
        points.push_back(make_pair(x, y));
        n++;
        if (ax * x + bx > 0 && ax * x + bx <= INT64_MAX)
            x = ax * x + bx;
        else
            break;
        if (ay * y + by > 0 && ay * y + by <= INT64_MAX)
            y = ay * y + by;
        else
            break;
        if (x < 0 || y < 0)
            break;
    }
    ll ans = 0;
    for (ll i = 0; i < points.size(); i++)
    {
        for (ll j = 0; j < points.size(); j++)
        {
            ll temp = t;
            if (abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second) >= 0 && abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second) <= INT64_MAX)
                temp = temp - abs(points[i].first - points[j].first) - abs(points[i].second - points[j].second);
            else
                temp = -1;
            if (temp < 0)
                temp = -1;
            for (ll k = min(i, j); k <= max(i, j); k++)
            {
                ll temp1 = temp;
                // if (k == 3)
                // cout << abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second) << " " << temp1 << " " << i << " " << j << " ";
                if (abs(xs - points[k].first) + abs(ys - points[k].second) >= 0 && abs(xs - points[k].first) + abs(ys - points[k].second) <= INT64_MAX)
                    temp1 = temp1 - abs(xs - points[k].first) - abs(ys - points[k].second);
                else
                    temp1 = -1;
                if (temp1 < 0)
                    temp1 = -1;
                if (abs(points[i].first - points[k].first) + abs(points[i].second - points[k].second) >= 0 && abs(points[i].first - points[k].first) + abs(points[i].second - points[k].second) <= INT64_MAX)
                    temp1 = temp1 - abs(points[i].first - points[k].first) - abs(points[i].second - points[k].second);
                else
                    temp1 = -1;
                if (temp1 < 0)
                    temp1 = -1;
                // if (k == 3)
                // cout << temp1 << "\n";
                if (temp1 >= 0)
                {
                    ans = max(ans, abs(j - i) + 1);
                }
            }
        }
    }
    cout << ans << "\n";
}
