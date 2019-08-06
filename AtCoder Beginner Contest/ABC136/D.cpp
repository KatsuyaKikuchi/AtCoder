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
ll B[100005];

int main()
{
    string S;
    cin >> S;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    ll r = 0, l = 0;
    ll N = S.length();
    REP(i, N)
    {
        if (S[i] == 'R')
            r++;
        if (S[N - 1 - i] == 'L')
            l++;
        if (i == N - 1)
            continue;
        if (S[i + 1] == 'L')
        {
            A[i] += r;
            r = 0;
        }
        if (S[N - 2 - i] == 'R')
        {
            A[N - 1 - i] += l;
            l = 0;
        }
    }

    REP(i, N)
    {
        if (A[i] == 0)
            continue;
        if (S[i] == 'R')
        {
            B[i] += A[i] / 2 + A[i] % 2;
            B[i + 1] += A[i] / 2;
        }
        if (S[i] == 'L')
        {
            B[i] += A[i] / 2 + A[i] % 2;
            B[i - 1] += A[i] / 2;
        }
    }

    REP(i, N)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}