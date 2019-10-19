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
    vector<pll> node;
};
struct Cost
{
    ll to;
    ll num = 0;
    ll l = 0;
};

ll N, M, L;
Vertex V[305];
pll B[305][305];

int main()
{
    cin >> N >> M >> L;
    REP(i, M)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (c > L)
            continue;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
        V[b].node.push_back(pll(a, c));
    }

    REP(i, N)
    {
        REP(j, N)
        {
            B[i][j] = pll(INF, INF);
        }
    }

    REP(i, N)
    {
        //! iからスタートした時の各町店への最短距離を求める
        priority_queue<Cost, vector<Cost>, function<bool(Cost, Cost)>> q([](Cost a, Cost b) { return a.num == b.num ? a.l < b.l : a.num > b.num; });
        q.push(Cost{i, 0, L});
        B[i][i] = pll(0, L);
        while (!q.empty())
        {
            Cost t = q.top();
            int index = t.to;
            ll num = t.num;
            ll li = t.l;
            q.pop();
            if (B[i][index].first < num)
                continue;
            if (B[i][index].first == num && B[i][index].second > li)
                continue;
            REP(j, V[index].node.size())
            {
                ll n = V[index].node[j].first;
                ll cost = V[index].node[j].second;

                ll nxtN = num;
                ll nxtL = li - cost;
                if (nxtL < 0)
                {
                    nxtL = L - cost;
                    nxtN++;
                }
                if (B[i][n].first < nxtN)
                    continue;
                if (B[i][n].first == nxtN && B[i][n].second >= nxtL)
                    continue;
                B[i][n] = pll(nxtN, nxtL);
                q.push(Cost{n, nxtN, nxtL});
            }
        }
    }

    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll s, t;
        cin >> s >> t;

        ll n = B[s - 1][t - 1].first;
        if (n == INF)
            cout << -1 << endl;
        else
            cout << n << endl;
    }
    return 0;
}