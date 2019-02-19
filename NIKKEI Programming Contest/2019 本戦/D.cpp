#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[200005];

class SegmentTree
{
  public:
    SegmentTree(int n)
    {
        N = 1;
        while (N < n)
            N *= 2;
        node.resize(2 * N - 1, 0);
        cout << N << endl;
    }

    void set(int left, int right, ll v, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = N - 1;

        cout << v << " " << l << " " << r << endl;
        if (right <= l || r <= left)
            return;
        if (left <= l && r <= right)
        {
            node[k] = std::max(node[k], v);
            return;
        }
        set(left, right, v, 2 * k + 1, l, (l + r) / 2);
        set(left, right, v, 2 * k + 2, (l + r) / 2 + 1, r);
    }

    void calc(int n = 0, ll v = 0)
    {
        if (n >= node.size())
            return;
        node[n] = std::max(node[n], v);
        calc(2 * n + 1, node[n]);
        calc(2 * n + 2, node[n]);
    }

    ll sum()
    {
        REP(i, node.size())
        {
            cout << node[i] << endl;
        }
        ll sum = 0;
        ll c = 1;
        while (c < N)
            c *= 2;
        REP(i, N)
        {
            sum += node[c - 1 + i];
        }
        return sum;
    }

  private:
    vector<ll> node;
    int N;
};

int main()
{
    ll N, M;
    cin >> N >> M;
    SegmentTree seg(N);

    REP(i, M)
    {
        ll t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        seg.set(l, r, t);
    }
    //seg.calc();
    cout << seg.sum() << endl;
    return 0;
}