#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N;

void dfs(int n, int m, vector<int> v, int s = 0)
{
    if (n == 0 || s == N)
    {
        REP(i, v.size())
        {
            cout << v[i];
            if (i != v.size() - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }

    for (int i = m; i >= 1; --i)
    {
        if (i > n)
            continue;
        v.push_back(i);
        dfs((N - s) - i, std::min(i, (N - s) - i), v, s + i);
        v.pop_back();
    }
}

int main()
{
    cin >> N;
    vector<int> v;
    dfs(N, N, v);
    return 0;
}