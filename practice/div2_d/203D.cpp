#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
double a, b, m;
double vx, vy, vz;
double calc_x(double vx, double a, double time)
{
    if (vx == 0)
    {
        return a / 2;
    }
    else
    {
        double st = abs((a / 2) / vx);
        if (st > time)
        {
            return a / 2 + vx * time;
        }
        else
        {
            double k1 = (abs(2 * vx * time) / a - 1) / 2;
            ll k = (ll)k1;
            double tim = a / 2 + k * a;
            tim /= abs(vx);
            double dist = abs((time - tim) * vx);
            if (vx > 0)
            {
                if (k % 2 == 0)
                {
                    return a - dist;
                }
                else
                    return dist;
            }
            else
            {
                if (k % 2 == 0)
                {
                    return dist;
                }
                else
                    return a - dist;
            }
        }
    }
}
double calc_z(double vz, double b, double time)
{
    if (vz == 0)
    {
        return 0;
    }
    else
    {

        double k1 = abs(vz * time) / b;
        ll k = (ll)k1;
        double tim = k * b;
        tim /= abs(vz);
        double dist = abs((time - tim) * vz);
        if (k % 2 == 0)
        {
            return dist;
        }
        else
            return b - dist;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> m;
    cin >> vx >> vy >> vz;
    double xcoord, zcoord;
    double time = m / abs(vy);
    xcoord = calc_x(vx, a, time);
    zcoord = calc_z(vz, b, time);
    printf("%0.8lf %0.8lf\n", xcoord, zcoord);
}