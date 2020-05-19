#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (m == k)
    {
        cout << "Controller " << m << "\n";
    }
    string s;
    cin >> s;
    cin >> s;
    string t;
    cin >> t;
    ll l = 0;
    if (s == "head")
        l = 1;
    ll met = 0, index = 0;
    for (ll i = 0; i < t.size(); i++)
    {
        if (t[i] == '0')
        {
            if (k > m)
            {
                if (m > 1)
                    m--;
            }
            else if (k < m)
            {
                if (m < n)
                    m++;
            }
            if (m == k)
            {
                met = 1;
                index = i;
                break;
            }
            if (l == 0)
            {
                if (k < n)
                {
                    k++;
                }
                else
                {
                    k--;
                    l = 1;
                }
            }
            else
            {
                if (k > 1)
                    k--;
                else
                {
                    k++;
                    l = 0;
                }
            }
            if (m == k)
            {
                met = 1;
                index = i;
                break;
            }
        }
        else
        {
            if (l == 0)
            {
                if (k < n)
                {
                    k++;
                }
                else
                {
                    k--;
                    l = 1;
                }
                if (l == 0)
                {
                    if (k > 1)
                    {
                        m = 1;
                    }
                    else
                    {
                        m = n;
                    }
                }
                else
                {
                    if (k < n)
                    {
                        m = n;
                    }
                    else
                    {
                        m = 1;
                    }
                }
            }
            else
            {
                if (k > 1)
                    k--;
                else
                {
                    k++;
                    l = 0;
                }
                if (l == 0)
                {
                    if (k > 1)
                    {
                        m = 1;
                    }
                    else
                    {
                        m = n;
                    }
                }
                else
                {
                    if (k < n)
                    {
                        m = n;
                    }
                    else
                    {
                        m = 1;
                    }
                }
            }
        }
        // cout << l << " " << k << " " << m << "\n";
    }
    if (met == 1)
    {
        cout << "Controller " << index + 1 << "\n";
    }
    else
    {
        cout << "Stowaway\n";
    }
}