#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define N 3005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
string s;
ll n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    cin >> s;
    ll temp1 = k;
    ll counter = 0, c1 = 0;
    ll maxmoves = 0, minmoves = 0, lastind = 0, moves = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            counter++;
            maxmoves += i - counter + 1;
            if (i != counter - 1)
            {
                minmoves = max(minmoves + 1, i - counter + 1);
                lastind = i;
            }
        }
    }
    // cout << maxmoves << " " << minmoves << "\n";

    if (k < minmoves || k > maxmoves)
    {
        cout << -1 << "\n";
        return 0;
    }
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == 'L' && s[i - 1] == 'R')
        {
            c1++;
        }
    }
    while (maxmoves != k)
    {
        k--;
        string s1 = s;
        if (maxmoves - c1 > k)
        {
            cout << c1 << " ";
            for (ll i = 1; i < n; i++)
            {
                if (s1[i] == 'L' && s1[i - 1] == 'R')
                {
                    cout << i << " ";
                    s[i] = 'R';
                    s[i - 1] = 'L';
                }
            }
            cout << "\n";
            maxmoves -= c1;
        }
        else
        {
            cout << maxmoves - k << " ";
            ll c2 = 0;
            for (ll i = 1; i < n && (c2 < maxmoves - k); i++)
            {
                if (s1[i] == 'L' && s1[i - 1] == 'R')
                {
                    cout << i << " ";
                    s[i] = 'R';
                    s[i - 1] = 'L';
                    c2++;
                }
            }
            cout << "\n";
            maxmoves = k;
            break;
        }
        c1 = 0;
        for (ll i = 1; i < n; i++)
        {
            if (s[i] == 'L' && s[i - 1] == 'R')
            {
                c1++;
            }
        }
        // cout << s << "\n";
    }
    counter = s[0] == 'L' ? 1 : 0;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == 'L')
            counter++;
        if (s[i] == 'L' && s[i - 1] == 'R')
        {
            ll temp = counter;
            s[i] = 'R';
            s[temp - 1] = 'L';
            for (ll j = i - 1; j >= temp - 1; j--)
            {
                cout << 1 << " ";
                cout << j + 1 << "\n";
            }
        }
    }
}