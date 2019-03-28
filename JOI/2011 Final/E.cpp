#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

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

pll X[300005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> X[i].first >> X[i].second;
    }
    sort(X, X + N, [](pll a, pll b) { return a.first < b.first; });
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    ll ans = 0;
    BinaryIndexTree bit(N);
    REP(i, N)
    {
        bit.add(i + 1, X[i].first);
        q.push(pll(X[i].second, i + 1));
        while (!q.empty() && q.top().first * q.size() < bit.sum(i + 1))
        {
            pll t = q.top();
            q.pop();
            bit.add(t.second, -X[t.second - 1].first);
        }
        ans = std::max(ans, (ll)q.size());
    }
    cout << ans << endl;
    return 0;
}