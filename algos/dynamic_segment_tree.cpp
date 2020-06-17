#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 100005
#define INF S_MAX

/// Dynamic segment tree... range updates and range queries//////////
/////////for sum///////////////
struct DST
{
    using S = ll;

    struct Vertex
    {
        ll Sum;
        Vertex *left, *right;
        Vertex(ll _Sum, Vertex *_left, Vertex *_right)
        {
            Sum = _Sum;
            left = _left;
            right = _right;
        }
    };

    void update(Vertex *root, S l, S r, S s, S e, S value)
    {
        if (s > r || l > e)
            return;
        if (l >= s && r <= e)
        {
            root->Sum += value;
            return;
        }
        if (root->left == NULL)
            root->left = new Vertex(0, NULL, NULL);
        if (root->right == NULL)
            root->right = new Vertex(0, NULL, NULL);
        update(root->left, l, (l + r) / 2, s, e, value);
        update(root->right, (l + r) / 2 + 1, r, s, e, value);
        root->Sum = root->left->Sum + root->right->Sum;
    }

    S query(Vertex *root, S tl, S tr, S l, S r)
    {
        if (root == NULL || tl > r || l > tr)
            return 0;
        if (l <= tl && tr <= r)
            return root->Sum;
        ll mid = (tl + tr) / 2;
        return query(root->left, tl, mid, l, r) + query(root->right, mid + 1, tr, l, r);
    }
};