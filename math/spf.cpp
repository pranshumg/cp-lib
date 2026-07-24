// Smallest Prime Factor (SPF)
// TC - O(n log log n), SC - O(n)
vector<int> Spf(int n) {
  vector<int> v(n + 1);
  for (int i = 0; i <= n; i++) v[i] = i;
  for (int i = 2; (long long)i * i <= n; i++) {
    if (v[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (v[j] == j) v[j] = i;
      }
    }
  }
  return v;
}

// Prime Factors using precomputed SPF table
// TC - O(log n) per query (SPF precomputed once, reused across calls)
// SC - O(log n) for the output vector (excludes the O(n) SPF table itself)
vector<int> prime_factors(int n, const vector<int>& v) {
  vector<int> ans;
  while (n > 1) {
    ans.push_back(v[n]);
    n /= v[n];
  }
  return ans;
}

// usage:
// vector<int> v = Spf(MAXN);       // build once — O(n log log n)
// auto pf = prime_factors(n, v);   // per query — O(log n)