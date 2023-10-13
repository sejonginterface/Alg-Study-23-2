#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*

  0 1 2 3 : j
i
1: 0 7! 0!
2: 0 3! 8
3: 0 8 1 0


 */

int arr[501][501];
int dp[501][501];
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= N; i++) {
    ans = max(ans, dp[N][i]);
  }

  cout << ans;
  return 0;
}