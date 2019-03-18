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
Vertex V[15];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    REP(i, N)
    {
        vector<int> n;
        vector<bool> v(N, false);
        REP(j, V[i].node.size())
        {
            int m = V[i].node[j];
            n.push_back(m);
            v[m] = true;
        }
        v[i] = true;

        int sum = 0;
        REP(j, n.size())
        {
            REP(k, V[n[j]].node.size())
            {
                int x = V[n[j]].node[k];
                if (v[x])
                    continue;
                v[x] = true;
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}