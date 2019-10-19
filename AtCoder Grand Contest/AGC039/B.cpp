#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Vertex
{
    vector<ll> node;
};
Vertex V[205];
ll U[205];
bool T[205];
string S[205];
int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> S[i];
        FOR(j, N, i + 1)
        {
            if (S[i][j] == '1')
            {
                V[i].node.push_back(j);
                V[j].node.push_back(i);
            }
        }
    }

    ll max = -1;
    REP(i, N)
    {
        memset(U, 0, sizeof(U));
        memset(T, 0, sizeof(T));
        //! 頂点iをV0に入れる
        queue<pll> q;
        q.push(pll(i, 1));
        U[i] = 1;
        T[i] = true;
        ll m = 0;
        while (!q.empty())
        {
            pll t = q.front();
            ll v = t.second + 1;
            q.pop();
            REP(j, V[t.first].node.size())
            {
                ll n = V[t.first].node[j];
                if (U[n] > 0 && U[n] == v - 1)
                {
                    m = -1;
                    break;
                }
                if (U[n] > 0 && U[n] < v - 1)
                    continue;
                if (T[n])
                    continue;
                T[n] = true;
                U[n] = v;
                q.push(pll(n, v));
            }
            if (m == -1)
                break;
            m = std::max(m, v);
        }
        max = std::max(m, max);
    }

    if (max != -1)
        max--;
    cout << max << endl;
    return 0;
}