#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

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
            node[i] = pdd(1, 0);
        }
        mN = cnt - 1;
    }
    ~SegmentTree()
    {
        node.resize(0);
    }

    //! 0-index get
    pdd get()
    {
        return node[0];
    }

    //! 0-index set
    void set(int index, pdd value)
    {
        node[mN + index] = value;
        //! update
        int par = (mN + index);
        while (par > 0)
        {
            par = (par - 1) / 2;
            pdd l = node[2 * par + 1];
            pdd r = node[2 * par + 2];
            node[par] = pdd(l.first * r.first, l.second * r.first + r.second);
        }
    }

  private:
    ll mN;
    vector<pdd> node;
};

struct Query
{
    ll index;
    pdd v;
};

Query Q[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    SegmentTree seg(M);
    vector<ll> x;
    REP(i, M)
    {
        cin >> Q[i].index >> Q[i].v.first >> Q[i].v.second;
        x.push_back(Q[i].index);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    double max = 1, min = 1;
    REP(i, M)
    {
        Q[i].index = find(x.begin(), x.end(), Q[i].index) - x.begin();
        seg.set(Q[i].index, Q[i].v);
        double value = seg.get().first + seg.get().second;
        max = std::max(max, value);
        min = std::min(min, value);
    }
    cout << OF64 << min << endl;
    cout << OF64 << max << endl;
    return 0;
}