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

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    int f = 1, e = N - 1;
    ll sum = 0;
    ll left = A[0], right = A[0];
    while (f <= e)
    {
        ll mf = std::max(abs(left - A[f]), abs(right - A[f]));
        ll me = std::max(abs(left - A[e]), abs(right - A[e]));
        if (mf > me)
        {
            if (abs(left - A[f]) > abs(right - A[f]))
                left = A[f];
            else
                right = A[f];
            f++;
        }
        else
        {
            if (abs(left - A[e]) > abs(right - A[e]))
                left = A[e];
            else
                right = A[e];
            e--;
        }
        sum += std::max(mf, me);
    }
    cout << sum << endl;
    return 0;
}