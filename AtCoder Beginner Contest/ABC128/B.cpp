#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

typedef pair<string, ll> psl;

struct T
{
    string s;
    int p;
    int i;
};
T S[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> S[i].s >> S[i].p;
        S[i].i = i;
    }
    sort(S, S + N, [](T a, T b) { return a.s == b.s ? a.p > b.p : a.s < b.s; });
    REP(i, N)
    {
        cout << S[i].i + 1 << endl;
    }

    return 0;
}