#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[105];
bool T[105], H[105];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    vector<int> B;
    FOR(i, 2 * N + 1, 1)
    {
        bool e = false;
        REP(j, N)
        {
            if (A[j] == i)
            {
                e = true;
                break;
            }
        }
        if (!e)
            B.push_back(i);
    }

    int tn = 0, hn = 0;
    int c = 0;
    int count = 0;
    while (tn < N && hn < N)
    {
        if (count % 2 == 0)
        {
            //! taro
            REP(i, N)
            {
                if (c < A[i] && !T[i])
                {
                    c = A[i];
                    T[i] = true;
                    tn++;
                    break;
                }

                if (i == N - 1)
                    c = 0;
            }
        }
        else
        {
            //! hanako
            REP(i, N)
            {
                if (c < B[i] && !H[i])
                {
                    c = B[i];
                    H[i] = true;
                    hn++;
                    break;
                }

                if (i == N - 1)
                    c = 0;
            }
        }
        count++;
    }

    int tp = 0, hp = 0;
    REP(i, N)
    {
        if (!H[i])
            tp++;
        if (!T[i])
            hp++;
    }
    cout << tp << endl;
    cout << hp << endl;
    return 0;
}