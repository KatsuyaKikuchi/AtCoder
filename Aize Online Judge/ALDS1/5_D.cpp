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

ll A[200005];

int main()
{
    ll N;
    cin >> N;
    vector<ll> x;
    REP(i, N)
    {
        cin >> A[i];
        x.push_back(A[i]);
    }
    sort(x.begin(), x.end());
    REP(i, N)
    {
        A[i] = lower_bound(x.begin(), x.end(), A[i]) - x.begin();
        A[i]++;
    }

    BinaryIndexTree bit(N);
    ll ans = 0;
    REP(i, N)
    {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    cout << ans << endl;
    return 0;
}