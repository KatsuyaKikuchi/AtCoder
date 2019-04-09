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
    bool f = false;
    int m = -1;
};

Vertex V[1000005];
ll A[1005][1005];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main()
{
    ll H, W;
    cin >> H >> W;
    REP(i, H)
    {
        REP(j, W)
        {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    REP(i, H)
    {
        REP(j, W)
        {
            REP(k, 4)
            {
                int nx = i + x[k];
                int ny = j + y[k];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;
                V[A[i][j]].node.push_back(A[nx][ny]);
                V[A[nx][ny]].node.push_back(A[i][j]);
                if (A[nx][ny] < A[i][j])
                    V[A[i][j]].count++;
                else
                    V[A[nx][ny]].count++;
            }
        }
    }
    ll N = H * W;
    queue<int> q;
    REP(i, N)
    {
        V[i].m = i;
        if (V[i].count == 0)
            q.push(i);
    }
    int ans = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        REP(i, V[t].node.size())
        {
            int n = V[t].node[i];
            V[t].m = std::min(V[t].m, V[n].m);
        }
        REP(i, V[t].node.size())
        {
            int n = V[t].node[i];
            if (n > t)
            {
                V[n].count--;
                if (V[n].count == 0)
                    q.push(n);
                continue;
            }
            if (V[n].f || V[n].m > V[t].m)
                V[t].f = true;
        }
        if (V[t].f)
            ans++;
    }
    cout << ans << endl;
    return 0;
}