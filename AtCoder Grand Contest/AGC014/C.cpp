#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[1000];

struct Node
{
    ll x;
    ll y;
    ll cost;
    Node(ll x, ll y, ll c) : x(x), y(y), cost(c)
    {
    }
};

ll H, W, K;
ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};
ll M[805][805];

ll length(ll h, ll w)
{
    return std::min(std::min(h, H - 1 - h), std::min(w, W - 1 - w));
}

int main()
{
    cin >> H >> W >> K;
    REP(i, H)
    {
        cin >> S[i];
    }
    pll s;
    REP(i, H)
    {
        REP(j, W)
        {
            if (S[i][j] == 'S')
                s = pll(i, j);
            M[i][j] = INF;
        }
    }

    queue<Node> q;
    q.push(Node(s.first, s.second, 0));
    M[s.first][s.second] = 0;
    ll min = length(s.first, s.second);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        if (t.cost >= K)
            continue;
        REP(i, 4)
        {
            ll nx = t.x + x[i];
            ll ny = t.y + y[i];
            ll cost = t.cost + 1;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (M[nx][ny] <= cost || S[nx][ny] == '#')
                continue;
            M[nx][ny] = cost;
            min = std::min(min, length(nx, ny));
            q.push(Node(nx, ny, cost));
        }
    }
    cout << (min + K - 1) / K + 1 << endl;
    return 0;
}