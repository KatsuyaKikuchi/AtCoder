#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[205];
pll B[1005];
map<pll, bool> Map;

int main()
{
    int M;
    cin >> M;
    REP(i, M)
    {
        cin >> A[i].first >> A[i].second;
    }
    int N;
    cin >> N;
    REP(i, N)
    {
        pll b;
        cin >> b.first >> b.second;
        Map[b] = true;
        B[i] = b;
    }

    REP(i, N)
    {
        bool e = true;
        pll t(B[i].first - A[0].first, B[i].second - A[0].second);

        REP(j, M)
        {
            pll p(A[j].first + t.first, A[j].second + t.second);
            if (!Map[p])
            {
                e = false;
                break;
            }
        }
        if (e)
        {
            cout << t.first << " " << t.second << endl;
            break;
        }
    }
    return 0;
}