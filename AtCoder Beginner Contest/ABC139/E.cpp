#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[1005][1005];
struct Vertex
{
    ll count = 0;
    ll max = 0;
    vector<ll> node;
};

Vertex V[1100005];
bool U[1100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        REP(j, N - 1)
        {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    REP(i, N)
    {
        FOR(j, N - 1, 1)
        {
            ll n = std::min(i, A[i][j]) + std::max(i, A[i][j]) * N;
            ll p = std::min(i, A[i][j - 1]) + std::max(i, A[i][j - 1]) * N;
            V[p].node.push_back(n);
            V[n].count++;
        }
    }
    memset(U, 0, sizeof(U));
    queue<pll> q;
    REP(i, N)
    {
        ll index = std::min(i, A[i][0]) + std::max(i, A[i][0]) * N;
        if (V[index].count == 0)
        {
            q.push(pll(index, 1));
        }
    }

    ll max = 0;
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        if (U[t.first])
            continue;
        U[t.first] = true;
        max = std::max(max, t.second);
        REP(i, V[t.first].node.size())
        {
            ll n = V[t.first].node[i];
            V[n].count--;
            V[n].max = std::max(V[n].max, t.second + 1);
            if (V[n].count <= 0)
                q.push(pll(n, V[n].max));
        }
    }

    REP(i, N)
    {
        REP(j, N - 1)
        {
            ll index = std::min(i, A[i][j]) + std::max(i, A[i][j]) * N;
            if (U[index])
                continue;
            cout << -1 << endl;
            return 0;
        }
    }

    cout << max << endl;
    return 0;
}