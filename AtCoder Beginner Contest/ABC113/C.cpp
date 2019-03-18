#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Data
{
    int y;
    int p;
    int i;
};
Data D[100005];
string A[100005];

string create(int p, int n)
{
    string a = "", b = "";
    REP(i, 6)
    {
        a = (char)('0' + p % 10) + a;
        b = (char)('0' + n % 10) + b;
        p /= 10;
        n /= 10;
    }
    return a + b;
}

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> D[i].p >> D[i].y;
        D[i].i = i;
    }
    sort(D, D + M, [](Data a, Data b) { return a.p == b.p ? a.y < b.y : a.p < b.p; });
    int pi = 0;
    REP(i, M)
    {
        if (D[pi].p != D[i].p)
        {
            pi = i;
        }
        A[D[i].i] = create(D[i].p, i - pi + 1);
    }
    REP(i, M)
    {
        cout << A[i] << endl;
    }
    return 0;
}