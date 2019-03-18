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
    vector<int> e;
};

Vertex V[100005];
bool U[100005];

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
        V[a].e.push_back(b);
        V[b].e.push_back(a);
    }

    stack<int> s;
    s.push(0);
    vector<int> ans;
    ans.push_back(1);
    auto collect = [&](stack<int> s) {
        while (!s.empty())
        {
            int t = s.top();
            s.pop();
            U[t] = true;
            REP(i, V[t].e.size())
            {
                int n = V[t].e[i];
                if (U[n])
                    continue;
                s.push(n);
                ans.push_back(n + 1);
                break;
            }
        }
    };
    collect(s);

    std::reverse(ans.begin(), ans.end());
    collect(s);

    cout << ans.size() << endl;
    REP(i, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}