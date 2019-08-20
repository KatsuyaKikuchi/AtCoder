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
    ll P;
    ll Y;
    ll i;
};
Data D[100005];
pll A[100005];
int B[100005];
string S[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> D[i].P >> D[i].Y;
        D[i].i = i;
    }
    sort(D, D + M, [](Data a, Data b) { return a.Y < b.Y; });
    REP(i, M)
    {
        A[D[i].i].second = ++B[D[i].P];
        A[D[i].i].first = D[i].P;
    }

    S[0] = "000000";
    REP(i, 100000)
    {
        S[i + 1] = S[i];
        S[i + 1][5]++;
        for (int j = 5; j >= 0; --j)
        {
            if (S[i + 1][j] - '0' <= 9)
                break;
            S[i + 1][j] = '0';
            S[i + 1][j - 1]++;
        }
    }

    REP(i, M)
    {
        cout << S[A[i].first] << S[A[i].second] << endl;
    }
    return 0;
}
