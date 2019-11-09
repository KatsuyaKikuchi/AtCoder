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
            node[i] = inf;
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
            return inf;
        if (left <= l && r <= right)
            return node[index];
        return std::min(get(left, right, l, (l + r) / 2, 2 * index + 1),
                        get(left, right, (l + r) / 2 + 1, r, 2 * index + 2));
    }

    //! 0-index set
    void set(int index, ll value)
    {
        node[mN + index] = value;
        //! update
        int par = (mN + index);
        while (par > 0)
        {
            par = (par - 1) / 2;
            node[par] = std::min(node[2 * par + 1], node[2 * par + 2]);
        }
    }

private:
    ll mN;
    vector<ll> node;
    const ll inf = (1LL << 31) - 1LL;
};

pll T[100005];
ll S[300005];

int main()
{
    ll N, M;
    cin >> N >> M;
    memset(S, 0, sizeof(S));
    REP(i, M)
    {
        cin >> T[i].first >> T[i].second;
        T[i].first--;
        T[i].second--;
        S[T[i].first]++;
        S[T[i].second + 1]--;
    }

    SegmentTree seg(N);
    REP(i, N)
    {
        S[i + 1] += S[i];
        seg.set(i, S[i]);
    }

    vector<ll> ans;
    REP(i, M)
    {
        if (seg.get(T[i].first, T[i].second) > 1)
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    REP(i, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}