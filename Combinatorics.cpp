#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
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

long long ncr(long long a, long long b)
{
	long long numer = fact(a);
	long long deno = fact(b) * fact(a - b) % mod;

	long long ans = numer * binpow(deno, mod - 2, mod) % mod;

	return ans;
}
