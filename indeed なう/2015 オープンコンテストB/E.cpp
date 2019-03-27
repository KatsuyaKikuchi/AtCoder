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

  private:
    vector<ll> node;
    ll mN;
};

ll H[100005];
ll Z[100005];

int main()
{
    ll N;
    cin >> N;
    vector<ll> x;
    REP(i, N)
    {
        cin >> H[i];
        x.push_back(H[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    if (x.size() < N)
    {
        cout << -1 << endl;
        return 0;
    }
    REP(i, N)
    {
        Z[i] = lower_bound(x.begin(), x.end(), H[i]) - x.begin();
        Z[i]++;
    }

    BinaryIndexTree bit(N);
    ll sum = 0;
    REP(i, N)
    {
        ll n = i - bit.sum(Z[i]);
        sum += n * H[i];
        bit.add(Z[i], 1);
    }
    cout << sum << endl;
    return 0;
}