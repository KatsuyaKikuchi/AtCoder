#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e14;

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
        FOR(i, n + 1, 1)
        {
            add(i, INF);
        }
        node[0] = 0;
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

    // private:
    vector<ll> node;
    ll mN;
    ll mPow;
};

class Prev
{
  public:
    Prev(int N)
    {
        REP(i, N + 1)
        {
            node[i] = i;
        }
    }

    ll get(int i)
    {
        if (node[i] == i)
            return i;
        return node[i] = get(node[i]);
    }
    void set(int i)
    {
        if (i == 0)
            return;
        node[i] = get(i - 1);
    }

  private:
    int node[200005];
};
ll A[200005];

int main()
{
    ll N, M, H;
    cin >> N >> M >> H;
    BinaryIndexTree bit(N + M);
    REP(i, N)
    {
        cin >> A[i + 1];
        bit.add(i + 1, A[i + 1] - INF);
    }

    ll s = N;
    Prev P(N + M);
    REP(i, M)
    {
        string c;
        ll a;
        cin >> c >> a;
        if (c == "add")
        {
            bit.add(++s, a - INF);
            A[s] = a;
            continue;
        }

        int index = bit.lowerBound(a);
        if (index < s)
        {
            //! 上を調べる
            if (bit.sum(index) < a + H)
            {
                cout << "stop" << endl;
                continue;
            }
        }
        //! 下を調べる
        if (P.get(index - 1) > 0 && bit.sum(P.get(index - 1)) > a - H)
        {
            if (index == s + 1)
            {
                cout << "go" << endl;
                bit.add(P.get(index - 1), -A[P.get(index - 1)]);
                P.set(P.get(index - 1));
            }
            else
                cout << "stop" << endl;
            continue;
        }
        if (index == s + 1)
            cout << "miss" << endl;
        else
        {
            cout << "go" << endl;
            P.set(index);
            bit.add(index, -A[index]);
        }
    }
    return 0;
}