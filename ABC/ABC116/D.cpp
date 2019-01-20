#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[100005];
bool V[100005];
bool U[100005];
bool E[100005];

int main()
{
    ll N, K;
    cin >> N >> K;

    ll mv = 0;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
        if (!V[A[i].first])
        {
            mv++;
            V[A[i].first] = true;
        }
    }

    //! 食べられる最大の種類数
    mv = std::min(K, mv);
    ll sum = 0;
    int k = 0; //! 食べた数
    int v = 0; //! 被っているものを食べた数
    sort(A, A + N, [](pll a, pll b) { return a.second > b.second; });
    int l = 0;
    int i = 0;
    while (i < N)
    {
        if (k == K)
            break;
        if (E[i])
        {
            ++i;
            continue;
        }
        if (!U[A[i].first])
        {
            sum += A[i].second;
            U[A[i].first] = true;
            E[i] = true;
            i++;
        }
        else
        {
            if (v + mv + 1 <= K)
            {
                v++;
                sum += A[i].second;
                U[A[i].first] = true;
                E[i] = true;
                i++;
            }
            else
            {
                //! 既に食べた種類の中で一番大きなものを食べるか、食べていない種類の中で一番大きなものを食べるか選ぶ
                bool e = false;
                FOR(j, N, l)
                {
                    if (E[j])
                        continue;
                    if (U[A[j].first])
                        continue;
                    l = j;
                    e = true;
                    break;
                }
                if (!e)
                    l = N;
                //! 種類が減ることによって種類ボーナスは2mv-1減る。
                if (!e || 2 * mv - 1 + A[l].second < A[i].second)
                {
                    //! 被ってるものを食べたほうがいい
                    v++;
                    mv--;
                    sum += A[i].second;
                    U[A[i].first] = true;
                    E[i] = true;
                    i++;
                }
                else
                {
                    //! 被っていないものを食べた方がいい
                    sum += A[l].second;
                    U[A[l].first] = true;
                    E[l] = true;
                }
            }
        }
        ++k;
    }
    cout << sum + mv * mv << endl;
    return 0;
}