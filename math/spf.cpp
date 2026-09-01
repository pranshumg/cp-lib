// Smallest Prime Factor (SPF)
// TC - O(n log log n), SC - O(n)
vector<int> Spf(int n) {
  vector<int> spf(n + 1);
  for (int i = 0; i <= n; i++) spf[i] = i;
  for (int i = 2; int64_t(i) * i <= n; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
  return spf;
}

// Prime Factors using precomputed SPF table
// TC - O(log n) per query (SPF precomputed once, reused across calls)
// SC - O(log n) for the output vector (excludes the O(n) SPF table itself)
vector<int> prime_factors(int n, const vector<int>& spf) {
  vector<int> ans;
  while (n > 1) {
    ans.push_back(spf[n]);
    n /= spf[n];
  }
  return ans;
}

// usage:
// vector<int> spf = Spf(MAXN);       // build once — O(n log log n)
// auto pf = prime_factors(n, spf);   // per query — O(log n)