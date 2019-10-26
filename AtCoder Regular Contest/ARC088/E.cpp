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

bool U[200005];
queue<ll> P[30];
ll Q[30];

int main()
{
    string S;
    cin >> S;
    ll N = S.length();
    memset(Q, 0, sizeof(Q));
    REP(i, N)
    {
        Q[S[i] - 'a']++;
    }
    ll odd = 0;
    int oddChar = -1;
    REP(i, 30)
    {
        if (Q[i] % 2 == 1)
        {
            odd++;
            oddChar = i;
        }
        Q[i] /= 2;
    }
    if (odd > N % 2)
    {
        cout << -1 << endl;
        return 0;
    }
    memset(U, 0, sizeof(U));
    string A = "", B = "";
    ll ans = 0;
    REP(i, N)
    {
        if (Q[S[i] - 'a'] > 0)
        {
            A.push_back(S[i]);
            Q[S[i] - 'a']--;
            ans += B.length();
        }
        else
        {
            B.push_back(S[i]);
        }
    }
    if (oddChar >= 0)
        A.push_back('a' + oddChar);
    REP(i, A.length())
    {
        P[A[i] - 'a'].push(i + 1);
    }
    BinaryIndexTree bit(N);
    REP(i, B.length())
    {
        ll t = P[B[B.length() - 1 - i] - 'a'].front();
        P[B[B.length() - 1 - i] - 'a'].pop();
        ans += i - bit.sum(t);
        bit.add(t, 1);
    }
    cout << ans << endl;
    return 0;
}