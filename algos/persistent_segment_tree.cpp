#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 100005
#define INF S_MAX

// qry function and get_sum needs to be updated for different types of queries..
using S = ll;
vector<S> a(N);

struct PST
{
    S n;
    struct Vertex
    {
        Vertex *l, *r;
        S sum;

        Vertex(S val) : l(nullptr), r(nullptr), sum(val) {}
        Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
        {
            if (l)
                sum += l->sum;
            if (r)
                sum += r->sum;
        }
        Vertex(Vertex l, Vertex r)
        {
            sum = l.sum + r.sum;
        }
    };
    vector<Vertex *> roots;
    S last_upd;

    PST(S n, S m)
    {
        n = n;
        roots.resize(m + 1);
        roots[0] = build(1, n);
        last_upd = 0;
    }
    Vertex qry(S time, S l, S r)
    {
        return get_sum(roots[time], 1, n, l, r);
    }
    void update(S time, S pos, S new_val)
    {
        roots[time] = upd(roots[last_upd], 1, n, pos, new_val);
        last_upd = time;
    }

    Vertex *build(S tl, S tr)
    {
        if (tl == tr)
            return new Vertex(a[tl]);
        S tm = (tl + tr) / 2;
        return new Vertex(build(tl, tm), build(tm + 1, tr));
    }

    Vertex get_sum(Vertex *v, S tl, S tr, S l, S r)
    {
        if (l > r)
            return Vertex(0);
        if (l == tl && tr == r)
            return *v;
        S tm = (tl + tr) / 2;
        Vertex temp = Vertex(get_sum(v->l, tl, tm, l, min(r, tm)), get_sum(v->r, tm + 1, tr, max(l, tm + 1), r));
        return temp;
    }

    Vertex *upd(Vertex *v, S tl, S tr, S pos, S new_val)
    {
        if (tl == tr)
            return new Vertex(new_val);
        S tm = (tl + tr) / 2;
        if (pos <= tm)
            return new Vertex(upd(v->l, tl, tm, pos, new_val), v->r);
        else
            return new Vertex(v->l, upd(v->r, tm + 1, tr, pos, new_val));
    }
};