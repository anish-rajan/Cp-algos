#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (x >= y)
        {
            cout << "YES\n";
            continue;
        }
        else
        {

            if (x % 2 == 1)
                x--;
            if (x == 2 && y == 3)
            {
                cout << "YES\n";
                continue;
            }
            if (x == 0)
            {
                cout << "NO\n";
                continue;
            }
            ll f = 0;
            while (x != 2 && x != 0)
            {
                if (x % 2 == 0)
                    x = (x * 3) / 2;
                else
                    x--;
                if (x >= y)
                {
                    f = 1;
                    cout << "YES\n";
                    break;
                }
            }
            if (f == 0)
                cout << "NO\n";
        }
    }
}