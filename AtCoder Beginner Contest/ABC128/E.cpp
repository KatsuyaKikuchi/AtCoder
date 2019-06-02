#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

class SegmentTree
{
public:
    SegmentTree(int n)
    {
        int c = 1;
        while (c < n)
            c <<= 1;
        N = c;
        node.resize(2 * N - 1);
        REP(i, node.size())
        {
            node[i] = INF;
        }
    }

    void set(int l, int r, ll v, int k = 0, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = N - 1;
        if (tr < l || r < tl)
            return;

        if (l <= tl && tr <= r)
        {
            node[k] = std::min(v, node[k]);
            return;
        }
        set(l, r, v, 2 * k + 1, tl, (tl + tr) / 2);
        set(l, r, v, 2 * k + 2, (tl + tr) / 2 + 1, tr);
    }

    ll get(int n)
    {
        int k = N - 1 + n;
        ll min = node[0];
        while (k > 0)
        {
            min = std::min(min, node[k]);
            k = (k - 1) / 2;
        }
        return min;
    }

private:
    int N;
    vector<ll> node;
};

struct T
{
    ll d;
    int i;
};
T D[200005];

struct S
{
    ll s;
    ll t;
    ll x;
};

S C[200005];

int main()
{
    ll N, Q;
    cin >> N >> Q;
    REP(i, N)
    {
        cin >> C[i].s >> C[i].t >> C[i].x;
    }
    REP(i, Q)
    {
        cin >> D[i].d;
        D[i].i = i;
    }
    sort(D, D + Q, [](T a, T b) { return a.d < b.d; });

    SegmentTree seg(Q);

    REP(i, N)
    {
        if (C[i].t - C[i].x < 0)
            continue;

        ll min = std::max(C[i].s - C[i].x, 0LL);
        ll max = C[i].t - C[i].x;

        //! 出発時間がmin以上max以下の奴はダメ
        ll l = N;
        {
            ll ok = Q - 1;
            ll ng = -1;
            while (abs(ok - ng) > 1)
            {
                ll mid = (ok + ng) / 2;
                if (D[mid].d >= min)
                    ok = mid;
                else
                    ng = mid;
            }
            if (D[ok].d >= min)
                l = ok;
            else
                l = ok + 1;
        }
        ll r = -1;
        {
            ll ok = 0, ng = Q;
            while (abs(ok - ng) > 1)
            {
                ll mid = (ok + ng) / 2;
                if (D[mid].d < max)
                    ok = mid;
                else
                    ng = mid;
            }
            if (D[ok].d < max)
                r = ok;
            else
                r = ok - 1;
        }
        if (r < l)
            continue;
        seg.set(l, r, C[i].x);

        //cout << l << " " << r << endl;
    }
    REP(i, Q)
    {
        D[i].d = seg.get(i);
    }
    sort(D, D + Q, [](T a, T b) { return a.i < b.i; });
    REP(i, Q)
    {
        if (D[i].d == INF)
            cout << -1 << endl;
        else
            cout << D[i].d << endl;
    }
    return 0;
}