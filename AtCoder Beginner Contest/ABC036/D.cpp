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
    int count = 0;
};

Vertex V[100005];
ll A[100005][2];
bool U[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    memset(A, 0, sizeof(A));
    memset(U, 0, sizeof(U));
    queue<int> q;
    REP(i, N)
    {
        if (V[i].node.size() == 1)
            q.push(i);
    }
    ll ans = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        U[t] = true;
        A[t][0] = A[t][1] = 1;
        REP(i, V[t].node.size())
        {
            int n = V[t].node[i];
            if (!U[n])
            {
                if (++V[n].count == V[n].node.size() - 1)
                    q.push(n);
                continue;
            }
            A[t][0] = (A[t][0] * (A[n][0] + A[n][1])) % MOD;
            A[t][1] = (A[t][1] * A[n][0]) % MOD;
        }
        ans = (A[t][0] + A[t][1]) % MOD;
    }
    cout << ans << endl;
    return 0;
}