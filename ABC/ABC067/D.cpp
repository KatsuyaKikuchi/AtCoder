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
};

Vertex V[100005];
bool U[100005];
int S[2];

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
    S[0] = S[1] = 0;
    queue<pll> q;
    q.push(pll(0, 0));
    q.push(pll(1, N - 1));
    U[0] = U[N - 1] = true;
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        REP(i, V[t.second].node.size())
        {
            int n = V[t.second].node[i];
            if (U[n])
                continue;
            U[n] = true;
            S[t.first]++;
            q.push(pll(t.first, n));
        }
    }
    if (S[0] > S[1])
        cout << "Fennec" << endl;
    else
        cout << "Snuke" << endl;
    return 0;
}