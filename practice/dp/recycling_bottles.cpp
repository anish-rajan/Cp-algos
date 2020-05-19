#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<pair<ll, ll>> co(N);
int main()
{
    ll ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    ll n;
    cin >> n;
    double sum = 0;
    double mina1 = INT64_MAX, mina2 = INT64_MAX, minb1 = INT64_MAX, minb2 = INT64_MAX;
    ll inda1 = -1, inda2 = -1, indb1 = -1, indb2 = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        sum += 2.0 * sqrt(pow((tx - x), 2) + pow(ty - y, 2));
        double temp1 = sqrt(pow((ax - x), 2) + pow(ay - y, 2)) - sqrt(pow((tx - x), 2) + pow(ty - y, 2));
        if (temp1 < mina1)
        {
            mina2 = mina1;
            inda2 = inda1;
            mina1 = temp1;
            inda1 = i;
        }
        else if (temp1 < mina2)
        {
            mina2 = temp1;
            inda2 = i;
        }

        double temp2 = sqrt(pow((bx - x), 2) + pow(by - y, 2)) - sqrt(pow((tx - x), 2) + pow(ty - y, 2));
        if (temp2 <= minb1)
        {
            minb2 = minb1;
            indb2 = indb1;
            minb1 = temp2;
            indb1 = i;
        }
        else if (temp2 <= minb2)
        {
            minb2 = temp2;
            indb2 = i;
        }
        // cout << mina1 << " " << mina2 << " " << minb1 << " " << minb2 << " " << inda1 << " " << inda2 << " " << indb1 << " " << indb2 << "\n";
    }
    double mini = INT64_MAX;
    mini = min(mini, mina1);
    mini = min(mini, minb1);
    if (inda1 == indb1)
    {
        mini = min(mini, mina1 + minb2);
        mini = min(mini, minb1 + mina2);
    }
    else
    {
        mini = min(mini, mina1 + minb1);
    }
    // cout << sum << "\n";
    printf("%0.8f\n", sum + mini);
}