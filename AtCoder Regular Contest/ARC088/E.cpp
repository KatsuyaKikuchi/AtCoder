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

ll C[30];
stack<ll> T[30];
ll N[200005];

int main()
{
    string S;
    cin >> S;
    memset(C, 0, sizeof(C));
    REP(i, S.length())
    {
        C[S[i] - 'a']++;
        T[S[i] - 'a'].push(i);
    }
    int odd = 0, even = 0;
    REP(i, 26)
    {
        if (C[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    if (odd > 1 || (odd == 1 && S.length() % 2 == 0))
    {
        cout << -1 << endl;
        return 0;
    }
    memset(N, 0, sizeof(N));
    int cnt = 0;
    REP(i, S.length())
    {
        if (N[i] > 0)
            continue;
        FOR(j, S.length(), i)
        {
            if (C[S[j] - 'a'] >= 2)
            {
                N[j] = cnt + 1;
                ll last = T[S[j] - 'a'].top();
                T[S[j] - 'a'].pop();
                N[last] = S.length() - cnt;
                C[S[j] - 'a'] -= 2;
                cnt++;
                break;
            }
        }
    }
    REP(i, 26)
    {
        if (C[i] == 0)
            continue;
        ll j = T[i].top();
        N[j] = S.length() / 2 + 1;
        break;
    }

    BinaryIndexTree bit(S.length());

    ll sum = 0;
    REP(i, S.length())
    {
        sum += i - bit.sum(N[i]);
        bit.add(N[i], 1);
    }
    cout << sum << endl;
    return 0;
}