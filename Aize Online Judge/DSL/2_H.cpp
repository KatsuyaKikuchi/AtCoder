#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! Starry Sky Tree
class LazySegmentTree
{
  public:
    LazySegmentTree(ll n)
    {
        ll c = 1;
        while (c < n)
            c <<= 1;
        REP(i, 2 * c - 1)
        {
            node.push_back(0);
            lazy.push_back(0);
        }
        mN = c - 1;
    }

    //! 0-index 区間加算
    void add(ll value, int left, int right, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = mN;
        LazyProgation(k);
        if (r < left || right < l)
            return;
        if (left <= l && r <= right)
        {
            //! 区間を完全被覆しているのでlazyに区間和を入れる
            lazy[k] += value;
            LazyProgation(k);
        }
        else
        {
            add(value, left, right, 2 * k + 1, l, (l + r) / 2);
            add(value, left, right, 2 * k + 2, (l + r) / 2 + 1, r);
            node[k] = std::min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    //! 0-index 最小値
    ll min(ll left, ll right, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = mN;
        if (r < left || right < l)
            return INF;

        LazyProgation(k);
        if (left <= l && r <= right)
            return node[k];
        return std::min(min(left, right, 2 * k + 1, l, (l + r) / 2), min(left, right, 2 * k + 2, (l + r) / 2 + 1, r));
    }

    void dev()
    {
        FOR(i, node.size(), 0)
        {
            cout << node[i] << ":" << lazy[i] << " ";
        }
        cout << endl;
    }

  private:
    //! index番目のnodeの遅延評価
    void LazyProgation(int index)
    {
        if (lazy[index] == 0)
            return;
        node[index] += lazy[index];
        if (2 * index + 1 < node.size())
        {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }

        lazy[index] = 0;
    }

    ll mN;
    vector<ll> node;
    //! 遅延評価配列
    vector<ll> lazy;
};

int main()
{
    ll N, Q;
    cin >> N >> Q;
    LazySegmentTree seg(N);
    REP(i, Q)
    {
        ll c, s, t;
        cin >> c >> s >> t;
        if (c == 0)
        {
            ll x;
            cin >> x;
            seg.add(x, s, t);
        }
        else if (c == 1)
        {
            cout << seg.min(s, t) << endl;
        }
    }
    return 0;
}