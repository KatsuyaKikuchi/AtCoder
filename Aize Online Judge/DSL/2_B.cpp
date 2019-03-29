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
        return get(left, right, l, (l + r) / 2, 2 * index + 1) + get(left, right, (l + r) / 2 + 1, r, 2 * index + 2);
    }

    //! 0-index add
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

int main()
{
    ll N, Q;
    cin >> N >> Q;
    SegmentTree seg(N);
    REP(i, Q)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        if (n == 0)
        {
            seg.add(a - 1, b);
        }
        else if (n == 1)
        {
            cout << seg.get(a - 1, b - 1) << endl;
        }
    }
    return 0;
}