#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int         int64_t
#define mod         1000000007
#define PI          3.141592653589793238462
#define __gcd(a,b)  gcd(abs(a),abs(b));
#define INF         1e18
#define ff          first
#define ss          second
#define pb          push_back
#define pii         pair<ll,ll>
#define mii         map<ll,ll>
#define max_heap    priority_queue<ll>
#define min_heap    priority_queue<ll,vector<ll>,greater<ll>>
#define vi          vector<ll>
#define setbits(x)  __builtin_popcountll(x)
#define ps(x,y)     fixed<<setprecision(y)<<x
#define bs          binary_search
#define lbnd        lower_bound
#define ubnd        upper_bound
#define endl        '\n'
#define all(a)      (a).begin(),(a).end()
#define ini(a, i)   memset(a, i, sizeof(a))
#define sz(x)       (ll)x.size()
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))

/*
//Find GCD (logN)
int findGCD(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > 0) {
            a = a % b;
        }
        if (b > 0) {
            b = b % a;
        }
    }
    if (a == 0)return b;
    else return a;
}
*/
/*
//Find a^b (logN)
int power(int a, int b, int m) {
    if (b == 0) {
        return 1;
    }

    int half_ans = power(a, b / 2, m);
    int ans;

    if (b % 2 == 0) {
        ans = 1LL * half_ans * half_ans % m;
    }
    else {
        ans = 1LL * half_ans * half_ans % m;
        ans = 1LL * ans * a % m;
    }
    return ans;
}
*/
/*
//Find number is PRIME or NOT (Sqrt(N))
bool isPrime(int N) {
    for (int i = 2; (i * i <= num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
*/

void c_r_g() {
	//Write code here
	int x; cin >> x;
	vector<int>arr(x);

	for (int i = 0; i < x; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < x; i++) {
		cout << arr[i] << endl;
	}
}
signed main() {
	ios
#ifndef ONLINE_JUDGE
#endif
	int test = 1;
	// cin >> test;
	while (test--) {
		c_r_g();
	}
}