#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
string s;
ll x, y, t, n;
void move(char t)
{
    if (t == 'L')
    {
        x--;
    }
    else if (t == 'R')
        x++;
    else if (t == 'U')
        y++;
    else
        y--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        x = 0, y = 0;
        cin >> n;
        cin >> s;
        move(s[0]);
        for (ll i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                continue;
            else if (s[i] == 'R' || s[i] == 'L')
            {
                if (s[i - 1] == 'R' || s[i - 1] == 'L')
                    continue;
                else
                    move(s[i]);
            }
            else if (s[i] == 'D' || s[i] == 'U')
            {
                if (s[i - 1] == 'U' || s[i - 1] == 'D')
                    continue;
                else
                    move(s[i]);
            }
            else
                move(s[i]);
        }
        cout << x << " " << y << "\n";
    }
}