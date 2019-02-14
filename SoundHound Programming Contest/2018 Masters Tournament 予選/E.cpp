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
    vector<pll> n;
};
struct VertexInfo
{
    //! 0番目のvertexが1の時の値
    ll n;
    //! 0番目のvertexが1増えた時、値が上がるノードか
    bool up = false;
};

Vertex V[100005];
VertexInfo Info[100005];
bool U[100005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        ll a, b, s;
        cin >> a >> b >> s;
        a--;
        b--;
        V[a].n.push_back(pll(b, s));
        V[b].n.push_back(pll(a, s));
    }

    Info[0].n = 1;
    Info[0].up = true;
    queue<int> q;
    q.push(0);
    U[0] = true;
    ll upmin = 1, downmin = INF;
    bool one = false;
    ll k = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        REP(i, V[t].n.size())
        {
            pll n = V[t].n[i];
            if (U[n.first])
            {
                ll sum = (Info[n.first].n + Info[t].n);
                //! 既に数が書き込まれている場合
                if (Info[n.first].up == Info[t].up)
                {
                    if (Info[n.first].up)
                    {
                        if (n.second < sum || (n.second - sum) % 2 == 1)
                        {
                            cout << 0 << endl;
                            return 0;
                        }

                        ll t = (n.second - sum) / 2;
                        if (one)
                        {
                            if (t != k)
                            {
                                cout << 0 << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            one = true;
                            k = t;
                        }
                    }
                    else
                    {
                        if (n.second > sum || (sum - n.second) % 2 == 1)
                        {
                            cout << 0 << endl;
                            return 0;
                        }
                        ll t = (sum - n.second) / 2;
                        if (one)
                        {
                            if (t != k)
                            {
                                cout << 0 << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            one = true;
                            k = t;
                        }
                    }
                }
                else if (Info[n.first].n + Info[t].n != n.second)
                {
                    cout << 0 << endl;
                    return 0;
                }
                continue;
            }
            q.push(n.first);
            U[n.first] = true;

            Info[n.first].n = n.second - Info[t].n;
            Info[n.first].up = !Info[t].up;
            if (Info[n.first].up)
                upmin = std::min(upmin, Info[n.first].n);
            else
                downmin = std::min(downmin, Info[n.first].n);
        }
    }

    //! node 0にかける数字の最大値
    ll max = downmin;
    REP(i, V[0].n.size())
    {
        max = std::min(max, V[0].n[i].second - 1);
    }
    //! node 0に書ける数字の最小値
    ll min = std::max((ll)1, 1 + (1 - upmin));

    ll ans = std::max(max - min + 1, (ll)0);
    if (one)
    {
        if ((1 + k <= max && 1 + k >= min) && ans > 0)
            ans = 1;
        else
            ans = 0;
    }
    cout << ans << endl;
    return 0;
}