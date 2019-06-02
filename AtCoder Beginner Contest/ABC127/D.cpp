#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
pll B[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        cin >> B[i].first >> B[i].second;
    }
    sort(A, A + N);
    sort(B, B + M, [](pll a, pll b) { return a.second > b.second; });

    int index = 0;
    REP(i, M)
    {
        bool f = false;
        REP(j, B[i].first)
        {
            if (A[index] < B[i].second)
            {
                A[index++] = B[i].second;
            }
            else
            {
                f = true;
            }
            if (index == N)
                f = true;
            if (f)
                break;
        }
        if (f)
            break;
    }

    ll sum = 0;
    REP(i, N)
    {
        sum += A[i];
    }
    cout << sum << endl;
    return 0;
}