#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char C[3] = {'a', 'b', 'c'};
vector<string> S;

void dfs(string s, int n)
{
    if (n == 0)
    {
        S.push_back(s);
        return;
    }
    REP(i, 3)
    {
        dfs(s + C[i], n - 1);
    }
    return;
}

int main()
{
    int N;
    cin >> N;
    dfs("", N);
    REP(i, S.size())
    {
        cout << S[i] << endl;
    }
    return 0;
}