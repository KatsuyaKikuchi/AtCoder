#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> P;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

map<ll, vector<ll>> m[101010];
map<ll, ll> flg[101010];
ll ans[101010];

int main()
{
    for (int i = 0; i < 101010; i++)
        ans[i] = 101010;

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        ll p, q, c;
        cin >> p >> q >> c;
        m[p][c].push_back(q);
        m[q][c].push_back(p);
    }
    priority_queue<P, vector<P>, greater<P>> Q;
    ans[1] = 0;
    Q.push(P(1, 1));
    while (!Q.empty())
    {
        ll p = Q.top().second;
        Q.pop();
        for (auto it = m[p].begin(); it != m[p].end(); it++)
        {
            ll c = (*it).first;
            stack<ll> S;
            S.push(p);
            flg[p][c] = 1;
            while (!S.empty())
            {
                ll s = S.top();
                S.pop();
                if (ans[s] == 101010)
                {
                    ans[s] = ans[p] + 1;
                    Q.push(P(ans[s], s));
                }
                for (int i = 0; i < m[s][c].size(); i++)
                {
                    ll nxt = m[s][c][i];
                    if (flg[nxt][c] == 0)
                    {
                        S.push(nxt);
                        flg[nxt][c] = 1;
                    }
                }
            }
        }
    }
    if (ans[N] == 101010)
        cout << -1 << endl;
    else
        cout << K * ans[N] << endl;
    return 0;
}