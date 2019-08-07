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
    vector<int> child;
    int par;
    ll cost;
    int cnt = 0;
    ll an = 0;
};

Vertex V[1005];
bool dp[5005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N - 1)
    {
        ll p;
        cin >> p;
        p--;
        V[i + 1].par = p;
        V[p].child.push_back(i + 1);
    }
    REP(i, N)
    {
        cin >> V[i].cost;
    }
    queue<int> q;
    REP(i, N)
    {
        if (V[i].child.size() == 0)
        {
            V[V[i].par].cnt++;
            if (V[V[i].par].cnt == V[V[i].par].child.size())
                q.push(V[i].par);
        }
    }

    bool ans = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ll minSum = 0;
        ll sum = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        REP(i, V[t].child.size())
        {
            int n = V[t].child[i];
            for (int j = V[t].cost; j >= 0; --j)
            {
                if (j - V[n].cost >= 0 && dp[j - V[n].cost])
                    dp[j] = true;
                if (j - V[n].an >= 0 && dp[j - V[n].an])
                    dp[j] = true;
            }
            sum += V[n].cost + V[n].an;
            minSum += std::min(V[n].cost, V[n].an);
        }
        for (int i = V[t].cost; i >= 0; --i)
        {
            if (!dp[i])
                continue;
            V[t].an = sum - i;
            if (V[t].cost < minSum)
                ans = false;
            break;
        }
        V[V[t].par].cnt++;
        if (V[V[t].par].cnt == V[V[t].par].child.size())
            q.push(V[t].par);
    }

    if (ans)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}