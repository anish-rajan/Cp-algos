#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (n--)
    {
        ll length;
        cin >> length;
        if (length == 1)
            cout << -1 << "\n";
        else
        {
            if ((length - 1) % 3 != 0)
            {
                for (ll i = 0; i < length - 1; i++)
                {
                    cout << "7";
                }
                cout << 3 << "\n";
            }
            else
            {
                for (ll i = 0; i < length - 2; i++)
                {
                    cout << "7";
                }
                cout << "33\n";
            }
        }
    }
}