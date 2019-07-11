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
    vector<int> node;
    vector<int> two;
    vector<int> three;
};

Vertex V[100005];
//bool U[100005];
ll A[100005];
ll B[100005];
bool U[100005][3];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b;
        cin >> a >> b;
        V[--a].node.push_back(--b);
    }
    ll S, T;
    cin >> S >> T;
    S--;
    T--;
    REP(i, N)
    {
        A[i] = INF;
    }

    memset(U, 0, sizeof(U));
    queue<pll> q;
    q.push(pll(S, 0LL));
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        if (A[t.first] <= t.second)
            continue;
        A[t.first] = t.second;
        if (t.first == T)
            break;

        queue<pll> p;
        p.push(pll(t.first, 0LL));
        while (!p.empty())
        {
            pll s = p.front();
            p.pop();
            if (U[s.first][s.second])
                continue;
            U[s.first][s.second] = true;
            REP(i, V[s.first].node.size())
            {
                int n = V[s.first].node[i];
                ll cost = s.second + 1;
                if (cost == 3)
                {
                    if (A[n] > t.second + 1)
                        q.push(pll(n, t.second + 1));
                    continue;
                }
                p.push(pll(n, cost));
            }
        }
    }

    if (A[T] == INF)
        cout << -1 << endl;
    else
        cout << A[T] << endl;
    return 0;
}