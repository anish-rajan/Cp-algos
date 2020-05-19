#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<ll> ans;
    for (ll i = 0; i < 12; i++)
    {
        vector<vector<ll>> siz(n, vector<ll>(2));
        ll cnt0 = 0, cnt1 = 0, cnt01 = 0;
        for (ll j = 0; j < n; j++)
        {
            ll flag0 = 0, flag1 = 0;
            siz[j][0] = -1, siz[j][1] = -1;
            for (ll k = 0; k < m; k++)
            {
                if (arr[j][k] % 2 == 0)
                {
                    flag0 = 1;
                    siz[j][0] = k + 1;
                }
                else
                {
                    flag1 = 1;
                    siz[j][1] = k + 1;
                }
                arr[j][k] /= 2;
            }
            if (flag0 == 1 && flag1 == 1)
            {
                cnt01++;
            }
            else if (flag0 == 1)
            {
                cnt0++;
            }
            else
            {
                cnt1++;
            }
        }
        // cout << cnt0 << " " << cnt1 << " " << cnt01 << "\n";
        if (cnt1 % 2 == 1)
        {
            for (ll j = 0; j < n; j++)
            {
                if (siz[j][0] == -1 || siz[j][1] == -1)
                {
                    ans.push_back(1);
                }
                else
                {
                    ans.push_back(siz[j][0]);
                }
            }
            cout << "TAK\n";
            for (ll j = 0; j < n; j++)
            {
                cout << ans[j] << " ";
            }
            cout << "\n";
            return 0;
        }
        if (cnt01 >= 1)
        {
            ll flag = 0;
            for (ll j = 0; j < n; j++)
            {
                if (siz[j][0] == -1 || siz[j][1] == -1)
                {
                    ans.push_back(1);
                }
                else
                {
                    if (flag == 0)
                    {
                        ans.push_back(siz[j][1]);
                        flag = 1;
                    }
                    else
                        ans.push_back(siz[j][0]);
                }
            }
            cout << "TAK\n";
            for (ll j = 0; j < n; j++)
            {
                cout << ans[j] << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "NIE\n";
    return 0;
}