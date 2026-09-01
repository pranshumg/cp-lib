// TC - O(n log n), SC - O(n log n)
vector<vector<int>> div_sieve(int n) {
  vector<vector<int>> divisors(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      divisors[j].push_back(i);
    }
  }
  return divisors;
}