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

Vertex V[2005];
bool U[2005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll min = N;
    REP(i, N)
    {
        //! iから距離K/2となる頂点の数を調べる
        ll k = K / 2;
        ll n = 0;
        {
            memset(U, 0, sizeof(U));
            U[i] = true;
            queue<pll> q;
            q.push(pll(i, 0));
            while (!q.empty())
            {
                pll t = q.front();
                q.pop();
                n++;
                if (t.second >= k)
                    continue;
                REP(j, V[t.first].node.size())
                {
                    int next = V[t.first].node[j];
                    if (U[next])
                        continue;
                    U[next] = true;
                    q.push(pll(next, t.second + 1));
                }
            }
        }

        if (K % 2 == 0)
        {
            min = std::min(min, N - n);
            continue;
        }
        //! 奇数の場合には、隣のノードからk個目の数を調べる
        memset(U, 0, sizeof(U));
        U[i] = true;
        REP(j, V[i].node.size())
        {
            int p = V[i].node[j];
            U[p] = true;
            queue<pll> q;
            q.push(pll(p, 0));
            int m = 0;
            while (!q.empty())
            {
                pll t = q.front();
                q.pop();
                if (t.second == k)
                {
                    m++;
                    continue;
                }
                REP(x, V[t.first].node.size())
                {
                    int next = V[t.first].node[x];
                    if (U[next])
                        continue;
                    U[next] = true;
                    q.push(pll(next, t.second + 1));
                }
            }
            min = std::min(min, N - (n + m));
        }
    }
    cout << min << endl;
    return 0;
}