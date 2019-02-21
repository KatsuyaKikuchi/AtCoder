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
            node[i] = n;
        }
    }

    void set(int l, int r, int v, int k = 0, int tl = 0, int tr = -1)
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

    int get(int n)
    {
        int k = N - 1 + n;
        int min = node[0];
        while (k > 0)
        {
            min = std::min(min, node[k]);
            k = (k - 1) / 2;
        }
        return min;
    }

  private:
    int N;
    vector<int> node;
};

ll A[200005];
//! index i以降の和
ll S[200005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    S[N] = 0;
    SegmentTree seg(N);
    ll sum = 0;
    for (ll i = N - 1; i >= 0; --i)
    {
        ll a = A[i];
        ll index = seg.get(a - 1);
        S[i] = S[index] + a * (index - i);
        sum += S[i];
        seg.set(a - 1, N - 1, i);
    }
    cout << sum << endl;
    return 0;
}