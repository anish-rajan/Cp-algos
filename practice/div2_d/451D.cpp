#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
string s;
ll a1, a2, n;
int main()
{
    cin >> s;
    n = s.size();
    ll tempa1 = 0, tempa2 = 0, tempb1 = 0, tempb2 = 0, inda = -1, indb = -1;
    a1 = 1, a2 = 0;
    inda = s[0] == 'a' ? 0 : -1;
    indb = s[0] == 'b' ? 0 : -1;
    if (s[0] == 'a')
    {
        tempa1 = a1, tempa2 = a2;
    }
    else
    {
        tempb1 = a1, tempb2 = a2;
    }
    // cout << a1 << " " << a2 << "\n";
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == 'a')
        {
            if ((i - inda) % 2 == 0)
            {
                a1 += tempa1 + 1;
                a2 += tempa2;
                tempa1 = tempa1 + 1;
            }
            else
            {
                a1 += tempa2 + 1;
                a2 += tempa1;
                ll temp = tempa2;
                tempa2 = tempa1;
                tempa1 = temp + 1;
            }
        }
        else
        {
            if ((i - indb) % 2 == 0)
            {
                a1 += tempb1 + 1;
                a2 += tempb2;
                tempb1 = tempb1 + 1;
            }
            else
            {
                a1 += tempb2 + 1;
                a2 += tempb1;
                ll temp = tempb2;
                tempb2 = tempb1;
                tempb1 = temp + 1;
            }
        }
        inda = s[i] == 'a' ? i : inda;
        indb = s[i] == 'b' ? i : indb;
        // cout << a1 << " " << a2 << " " << tempa1 << " " << tempa2 << "\n";
    }
    cout << a2 << " " << a1 << "\n";
}