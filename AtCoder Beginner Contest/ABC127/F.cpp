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
        ll cnt = 1;
        while (cnt < n)
            cnt <<= 1;
        node.resize(2 * cnt - 1);
        REP(i, 2 * cnt - 1)
        {
            node[i] = 0;
        }
        mN = cnt - 1;
    }
    ~SegmentTree()
    {
        node.resize(0);
    }

    //! 0-index get
    ll get(int left, int right, int l = 0, int r = -1, int index = 0)
    {
        if (r == -1)
            r = mN;

        if (r < left || right < l)
            return 0;
        if (left <= l && r <= right)
            return node[index];
        return get(left, right, l, (l + r) / 2, 2 * index + 1) +
               get(left, right, (l + r) / 2 + 1, r, 2 * index + 2);
    }

    //! 0-index set
    void add(int index, ll value)
    {
        node[mN + index] += value;
        //! update
        int par = (mN + index);
        while (par > 0)
        {
            par = (par - 1) / 2;
            node[par] = node[2 * par + 1] + node[2 * par + 2];
        }
    }

private:
    ll mN;
    vector<ll> node;
};

class BinaryIndexTree
{
public:
    BinaryIndexTree(int n)
        : mN(n)
    {
        mPow = 1;
        while (mPow < n)
            mPow <<= 1;
        node.resize(n + 1);
        REP(i, n + 1)
        {
            node[i] = 0;
        }
    }
    ~BinaryIndexTree()
    {
        node.resize(0);
    }

    //! 1-index get
    ll sum(int index)
    {
        ll sum = 0;
        for (int i = index; i > 0; i -= i & (-i))
            sum += node[i];
        return sum;
    }

    //! 1-index add
    void add(int index, ll value)
    {
        for (int i = index; i <= mN; i += i & (-i))
            node[i] += value;
    }

    int lowerBound(ll value)
    {
        if (value <= 0)
            return 0;
        int x = 0;
        for (int k = mPow; k > 0; k >>= 1)
        {
            if (x + k <= mN && node[x + k] < value)
            {
                value -= node[x + k];
                x += k;
            }
        }
        return x + 1;
    }

private:
    vector<ll> node;
    ll mN;
    ll mPow;
};

struct Query
{
    ll q;
    ll a;
    ll b;
};

Query Que[200005];

int main()
{
    ll Q;
    cin >> Q;

    vector<ll> v;
    REP(i, Q)
    {
        cin >> Que[i].q;
        if (Que[i].q == 1)
        {
            cin >> Que[i].a >> Que[i].b;
            v.push_back(Que[i].a);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    BinaryIndexTree bit(v.size() + 5);
    SegmentTree seg(v.size() + 5);
    ll B = 0;

    ll num = 0;
    REP(i, Q)
    {
        if (Que[i].q == 1)
        {
            //! 更新
            ll index = lower_bound(v.begin(), v.end(), Que[i].a) - v.begin();
            seg.add(index, Que[i].a);
            bit.add(index + 1, 1);
            B += Que[i].b;
            num++;
        }
        else
        {
            //! 出力
            ll index = bit.lowerBound((num + 1) / 2);
            ll ln = bit.sum(index - 1);
            ll rn = bit.sum(v.size()) - bit.sum(index);
            index--;
            ll x = v[index];
            ll l = seg.get(0, index - 1), r = seg.get(index + 1, v.size());
            ll sum = ln * x - l + r - rn * x + B;
            cout << x << " " << sum << endl;
        }
    }
    return 0;
}