#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    ll point = n - 1;
    ll insert = 0;
    ll ind;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '.')
            ind = i;
    }
    if (t >= n - ind - 1)
    {
        for (ll i = n - 2; i >= ind - 1;)
        {
            if (s[i + 1] >= '5' && s[i] != '.' && s[i + 1] != '.')
            {
                while (s[i] == '9' && i >= 0)
                {
                    s[i] = '0';
                    i--;
                    if (i >= 0)
                        if (s[i] == '.')
                            i--;
                }
                if (i <= -1)
                {
                    insert = 1;
                    point = ind - 1;
                }
                else
                {
                    s[i]++;
                    if (i > ind)
                        point = i;
                    else
                        point = ind - 1;
                    i--;
                }
            }
            else if (s[i + 1] == '.' && s[i + 2] >= '5')
            {
                while (s[i] == '9' && i >= 0)
                {
                    s[i] = '0';
                    i--;
                    if (i >= 0)
                        if (s[i] == '.')
                            i--;
                }
                if (i <= -1)
                {
                    insert = 1;
                    point = ind - 1;
                }
                else
                {
                    s[i]++;
                    if (i > ind)
                        point = i;
                    else
                        point = ind - 1;
                    i--;
                }
                break;
            }
            else
                i--;
        }
        if (insert == 1)
        {
            cout << '1';
        }
        for (ll i = 0; i <= point; i++)
        {
            cout << s[i];
        }
        cout << "\n";
    }
    else
    {
        for (ll i = ind - 1; i < n - 1; i++)
        {
            if (s[i + 1] != '.' && s[i + 1] >= '5')
            {
                while (s[i] == '9' && i >= 0)
                {
                    s[i] = '0';
                    i--;
                    if (i >= 0)
                        if (s[i] == '.')
                            i--;
                }
                if (i <= -1)
                {
                    insert = 1;
                    point = ind - 1;
                }
                else
                {
                    s[i]++;
                    if (i > ind)
                        point = i;
                    else
                        point = ind - 1;
                }
                t--;
                break;
            }
            else if (s[i + 1] == '.' && s[i + 2] >= '5')
            {
                while (s[i] == '9' && i >= 0)
                {
                    s[i] = '0';
                    i--;
                    if (i >= 0)
                        if (s[i] == '.')
                            i--;
                }
                if (i <= -1)
                {
                    insert = 1;
                    point = ind - 1;
                }
                else
                {
                    s[i]++;
                    if (i > ind)
                        point = i;
                    else
                        point = ind - 1;
                }
                t--;
                break;
            }
        }
        ll i = point;
        while (s[i] >= '5' && i - 1 >= 0 && t > 0)
        {
            if (i <= ind - 1)
                break;
            t--;
            if (s[i - 1] != '.')
            {
                i--;
                ll j = i;
                while (s[j] == '9' && j >= 0)
                {
                    s[j] = '0';
                    j--;
                    if (j >= 0)
                        if (s[j] == '.')
                            j--;
                }
                if (j <= -1)
                {
                    insert = 1;
                    point = ind - 1;
                }
                else
                {
                    s[j]++;
                    if (j > ind)
                        point = j;
                    else
                        point = ind - 1;
                }
                i = j;
            }
            else if ((point - 2) >= 0 && s[point - 1] == '.')
            {
                i -= 2;
                ll j = i;
                while (s[j] == '9' && j >= 0)
                {
                    s[j] = '0';
                    j--;
                    if (j >= 0)
                        if (s[j] == '.')
                            j--;
                }
                if (j <= -1)
                {
                    insert = 1;
                    point = ind - 1;
                }
                else
                {
                    s[j]++;
                    if (j > ind)
                        point = j;
                    else
                        point = ind - 1;
                }
                i = j;
            }
        }
        if (insert == 1)
            cout << 1;
        for (ll i = 0; i <= point; i++)
        {
            cout << s[i];
        }
        cout << "\n";
    }
}