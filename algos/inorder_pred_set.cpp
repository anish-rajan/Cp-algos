#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
set<pair<ll, ll>> elem;

set<pair<ll, ll>>::iterator inorder_pred(ll element)
{
    pair<ll, ll> temp(element, INT64_MIN);
    set<pair<ll, ll>>::iterator itr = elem.lower_bound(temp);
    if (itr == elem.end())
        itr--;
    else if ((*itr).first != element)
    {
        if (itr == elem.begin())
            itr = elem.end();
        else
            itr--;
    }
    return itr;
}

/// returns iterator for element less than equal to given element
/// if no element exists like this then points to the end.
