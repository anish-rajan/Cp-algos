#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
ll a1, a2, a3, a4;
void func(string &s, string t, ll no)
{
    for (ll i = 0; i < no; i++)
    {
        s += t;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a1 >> a2 >> a3 >> a4;
    ll temp = min(a3, a4);
    ll temp1 = max(a3, a4);
    string t;
    if (temp + 2 <= temp1)
    {
        cout << -1 << "\n";
    }
    else
    {
        if (a3 == a4)
        {
            if (a1 - temp - 1 >= 0 && a2 - temp >= 0)
            {
                string s;
                func(t, "47", a3);
                a1 -= temp + 1;
                a2 -= temp;
                for (ll i = 0; i < a1; i++)
                {
                    s += '4';
                }
                s += t;
                for (ll i = 0; i < a2; i++)
                {
                    s += '7';
                }
                s += '4';
                cout << s << "\n";
            }
            else if (a2 - temp - 1 >= 0 && a1 - temp >= 0)
            {
                string s;
                func(t, "74", a4);
                a1 -= temp;
                a2 -= temp + 1;
                for (ll i = 0; i < a1; i++)
                {
                    s += '4';
                }
                t = t.substr(1, t.size() - 1);
                s = "7" + s + t;
                for (ll i = 0; i < a2; i++)
                {
                    s += '7';
                }
                s += '7';
                cout << s << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else if (a3 > a4)
        {
            if (a1 - a3 >= 0 && a2 - a3 >= 0)
            {
                string s;
                func(t, "47", a3);
                a1 -= a3;
                a2 -= a3;
                for (ll i = 0; i < a1; i++)
                {
                    s += '4';
                }
                s += t;
                for (ll i = 0; i < a2; i++)
                {
                    s += '7';
                }
                cout << s << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else
        {
            if (a1 - a4 >= 0 && a2 - a4 >= 0)
            {
                string s;
                func(t, "74", a4);
                a1 -= a4;
                a2 -= a4;
                // cout << a1 << "\n";
                for (ll i = 0; i < a1; i++)
                {
                    s += '4';
                }
                t = t.substr(1, t.size() - 1);
                // cout << s << " " << t << "\n";
                s = "7" + s + t;
                // cout << s << "\n";
                s.pop_back();
                for (ll i = 0; i < a2; i++)
                {
                    s += '7';
                }
                s += '4';
                cout << s << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
}