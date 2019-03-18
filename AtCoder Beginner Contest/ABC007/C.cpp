#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[60];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
struct Node
{
    Node(int x, int y, int c) : x(x), y(y), c(c) {}
    int x;
    int y;
    int c;
};

int main()
{
    ll R, C;
    cin >> R >> C;
    pll S, G;
    cin >> S.first >> S.second;
    cin >> G.first >> G.second;
    S.first--;
    S.second--;
    G.first--;
    G.second--;
    REP(i, R)
    {
        cin >> M[i];
    }

    queue<Node> q;
    q.push(Node(S.second, S.first, 0));
    while (!q.empty())
    {
        Node n = q.front();
        q.pop();

        if (n.y == G.first && n.x == G.second)
        {
            cout << n.c << endl;
            break;
        }
        REP(i, 4)
        {
            int nx = n.x + x[i], ny = n.y + y[i];
            if (nx < 0 || nx >= C || ny < 0 || ny >= R)
                continue;
            if (M[ny][nx] == '#')
                continue;
            q.push(Node(nx, ny, n.c + 1));
            M[ny][nx] = '#';
        }
    }
    return 0;
}