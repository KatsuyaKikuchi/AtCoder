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
    int T;
};
struct Node
{
    Node(int t, int time, ll cost, int n)
        : T(t), time(time), cost(cost), next(n)
    {
    }
    int T;    //! 前に出た部屋
    ll time;  //! 出てからの時間
    ll cost;  //! 総コスト
    int next; //! 次の部屋
};

Vertex V[10005];
ll C[10005][3][205];

int main()
{
    ll N, M, X;
    cin >> N >> M >> X;
    REP(i, N)
    {
        cin >> V[i].T;
        REP(j, X + 1)
        {
            REP(k, 3)
            {
                C[i][k][j] = INF;
            }
        }
    }
    REP(i, M)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        V[a].node.push_back(pll(b, d));
        V[b].node.push_back(pll(a, d));
    }
    C[0][0][0] = 0;
    priority_queue<Node, vector<Node>, function<bool(Node, Node)>> q([](Node a, Node b) { return a.cost > b.cost; });
    q.push(Node(0, 0, 0, 0));
    while (!q.empty())
    {
        Node next = q.top();
        // cout << next.next<<" "<<next.cost<<" "<<next.time<<" "<<next.T << endl;
        q.pop();
        //! 現在の部屋のタイプ
        int type = V[next.next].T;
        if (type == 1)
        {
            // for (int i = next.time; i >= 0; --i)
            // {
            //     if (C[next.next][next.T][i] < next.cost)
            //         continue;
            // }
        }
        else
        {
            if (C[next.next][type][0] < next.cost)
                continue;
        }

        REP(i, V[next.next].node.size())
        {
            pll e = V[next.next].node[i];
            int time = X;
            ll cost = next.cost + e.second;
            type = V[next.next].T;
            if (type == 1)
            {
                time = next.time;
                type = next.T;
                // cout<<e.first<<":"<<type<<endl;
                if (V[e.first].T + type == 2)
                {
                    //! 異なる
                    if (time > e.second)
                        continue;
                    if (C[e.first][V[e.first].T][0] <= cost)
                        continue;
                    C[e.first][V[e.first].T][0] = cost;
                    q.push(Node(type, 0, cost, e.first));
                }
                else if (V[e.first].T == type)
                {
                    //! 同じ
                    if (C[e.first][V[e.first].T][0] <= cost)
                        continue;
                    C[e.first][V[e.first].T][0] = cost;
                    q.push(Node(type, 0, cost, e.first));
                }
                else
                {
                    //! 快適な部屋
                    time = std::max(0LL, time - e.second);
                    // cout<<e.first<<":"<<time<<endl;
                    bool f = true;
                    for (int j = time; j >= 0; --j)
                    {
                        if (C[e.first][type][j] <= cost)
                        {
                            f = false;
                            break;
                        }
                    }
                    if (!f)
                        continue;
                    C[e.first][type][time] = cost;
                    q.push(Node(type, time, cost, e.first));
                    //cout<<e.first<<endl;
                }
            }
            else
            {
                if (V[e.first].T + type == 2)
                {
                    //! 異なる
                    if (time > e.second)
                        continue;
                    if (C[e.first][V[e.first].T][0] <= cost)
                        continue;
                    C[e.first][V[e.first].T][0] = cost;
                    q.push(Node(type, 0, cost, e.first));
                }
                else if (V[e.first].T == type)
                {
                    //! 同じ
                    if (C[e.first][V[e.first].T][0] <= cost)
                        continue;
                    C[e.first][V[e.first].T][0] = cost;
                    q.push(Node(type, 0, cost, e.first));
                }
                else
                {
                    //! 快適な部屋
                    time = std::max(0LL, time - e.second);
                    bool f = true;
                    for (int j = time; j >= 0; --j)
                    {
                        if (C[e.first][type][j] <= cost)
                        {
                            f = false;
                            break;
                        }
                    }
                    if (!f)
                        continue;
                    C[e.first][type][time] = cost;
                    q.push(Node(type, time, cost, e.first));
                    // cout<<e.first<<endl;
                }
            }
        }
    }

    ll min = INF;
    REP(i, X + 1)
    {
        REP(j, 3)
        {
            min = std::min(min, C[N - 1][j][i]);
        }
    }
    cout << min << endl;
    return 0;
}