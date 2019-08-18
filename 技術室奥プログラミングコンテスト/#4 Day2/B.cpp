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
    int rank = 0;
    int par = 0;
    ;
};

Vertex V[100005];
Vertex A[100005];
bool C[100005];
bool U[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    {
        //! 0をrootとする根付き木として再定義
        memset(U, 0, sizeof(U));
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            if (U[t])
                continue;
            U[t] = true;
            REP(i, V[t].node.size())
            {
                int n = V[t].node[i];
                if (U[n])
                    continue;
                A[n].par = t;
                A[t].node.push_back(n);
                q.push(n);
            }
        }
    }
    memset(C, 0, sizeof(C));
    REP(i, M)
    {
        ll c;
        cin >> c;
        C[--c] = true;
    }
    bool f = true;
    {
        memset(U, 0, sizeof(U));
        queue<int> q;
        REP(i, N)
        {
            if (A[i].node.size() == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            if (U[t])
                continue;
            U[t] = true;
            int rank = 0;
            REP(i, A[t].node.size())
            {
                int n = A[t].node[i];
                rank += A[n].rank;
                if (A[n].rank >= 2 && C[t])
                    f = false;
            }
            if (rank > 2)
                f = false;
            A[t].rank = rank;
            if (C[t])
                A[t].rank = std::max(1, rank);
            if (A[A[t].par].node.size() == ++A[A[t].par].count)
                q.push(A[t].par);
        }
    }

    if (f)
        cout << "Yes" << endl;
    else
        cout << "trumpet" << endl;
    return 0;
}