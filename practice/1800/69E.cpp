#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> arr(N);
map<int, int> check;
set<int> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        if (check.find(arr[i]) == check.end())
        {
            check.insert(make_pair(arr[i], 1));
            ans.insert(arr[i]);
        }
        else
        {
            int temp = ++check[arr[i]];
            if (temp > 1)
            {
                ans.erase(arr[i]);
            }
            else
            {
                ans.insert(arr[i]);
            }
        }
    }
    if (!ans.empty())
        cout << *ans.rbegin() << "\n";
    else
        cout << "Nothing\n";
    for (int i = k; i < n; i++)
    {
        int temp = --check[arr[i - k]];
        if (temp == 1)
            ans.insert(arr[i - k]);
        else if (temp == 0)
        {
            ans.erase(arr[i - k]);
        }

        if (check.find(arr[i]) == check.end())
        {
            check.insert(make_pair(arr[i], 1));
            ans.insert(arr[i]);
        }
        else
        {
            int temp = ++check[arr[i]];
            if (temp > 1)
            {
                ans.erase(arr[i]);
            }
            else
            {
                ans.insert(arr[i]);
            }
        }
        if (!ans.empty())
            cout << *ans.rbegin() << "\n";
        else
            cout << "Nothing\n";
    }
}