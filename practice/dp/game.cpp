#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '0')
                x1++;
            else
                y1++;
        }
        else
        {
            if (s[i] == '0')
                x2++;
            else
                y2++;
        }
    }
    cout << min(x1 + y2, x2 + y1) << "\n";
}