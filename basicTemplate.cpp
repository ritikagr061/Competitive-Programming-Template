#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pb push_back
ll mod =  1e9 + 7;
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rev(i,a,n) for(ll i=n-1;i>=a;i--)
#define pcout(p) cout<<p.first<<" "<<p.second<<endl
#define cout3(a,b,c) cout<<a<<' '<<b<<' '<<c<<endl
#define cout2(a,b) cout<<a<<' '<<b<<endl

template<typename T1, typename T2>void ans(bool x, T1 y, T2 z) {if (x)cout << y << endl; else cout << z << endl;}
template<typename T1, typename T2, typename T3>void anss(T1 x, T2 y, T3 z) {ans(x != y, x, z);};
template<typename T>void debug(const T &v, ll h, ll w, string sv = " ") {for (ll i = 0; i < h; i++) {cout << v[i][0]; for (ll j = 1; j < w; j++)cout << sv << v[i][j]; cout << endl;}};
template<typename T>void debug(const T &v, ll n, string sv = " ") {if (n != 0)cout << v[0]; for (ll i = 1; i < n; i++)cout << sv << v[i]; cout << endl;};
template<typename T>void debug(const vector<T>&v) {debug(v, v.size());}
template<typename T>void debug(const vector<vector<T>>&v) {for (auto &vv : v)debug(vv, vv.size());}
template<typename T, typename V>void debug(const vector<pair<T, V>>&v) {for (auto it : v)cout << it.first << " " << it.second << endl;};

template<typename T>void debug(stack<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
template<typename T>void debug(queue<T> st) {while (!st.empty()) {cout << st.front() << " "; st.pop();} cout << endl;}
template<typename T>void debug(deque<T> st) {while (!st.empty()) {cout << st.front() << " "; st.pop_front();} cout << endl;}
// template<typename T>void debug(PQ<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
// template<typename T>void debug(QP<T> st) {while (!st.empty()) {cout << st.top() << " "; st.pop();} cout << endl;}
template<typename T>void debug(const set<T>&v) {for (auto z : v)cout << z << " "; cout << endl;}
template<typename T>void debug(const multiset<T>&v) {for (auto z : v)cout << z << " "; cout << endl;}
template<typename T, size_t size>void debug(const array<T, size> &a) {for (auto z : a)cout << z << " "; cout << endl;}
template<typename T, typename V>void debug(const map<T, V>&v) {for (auto z : v)cout << "[" << z.first << "]=" << z.second << ","; cout << endl;}
// ios_base::sync_with_stdio(0);
// cin.tie(0); cout.tie(0);

int getNext(int x, vector<int> &next)
{
	if (next[x] == x)
		return x;
	return next[x] = getNext(next[x], next);
}

long long binpow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res % m;
}


long long fact(long long n)
{
	if (n == 1 || n == 0)
		return 1;
	return n * fact(n - 1) % mod;
}

long long ncr(int a, int b)
{
	int numer = fact(a);
	int deno = fact(b) * fact(a - b) % mod;

	int ans = numer * binpow(deno, mod - 2, mod) % mod;

	return ans;
}

#define MAX 10000006
int len, sp[MAX];

void Sieve() {
	vector<bool> v(MAX, false);
	for (int i = 2; i < MAX; i++)
	{
		if (!v[i])
		{
			for (int j = i; j < MAX; j += i)
			{
				v[j] = true;
				sp[j] = i;
			}

		}
	}
}

vector<long long> getFactor(long long n) {
	vector<long long> factorization;
	while (n > 1)
	{
		factorization.push_back(sp[n]);
		n /= sp[n];
	}

	return factorization;
}



ll pow(ll x )
{
	if (x == 1)
		return 1;
	else
		return x * pow(x - 1);
}

signed main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		
	}
	return 0;
}
