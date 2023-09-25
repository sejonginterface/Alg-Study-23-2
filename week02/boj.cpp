#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int dp[12];
void sum(int N)
{

  dp[0] = dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  if (N <= 4)
  {
    printf("%d\n", dp[N]);
  }
  else
  {
    for (int j = 4; j < N; j++)
    {
      dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
    }
    printf("%d\n", dp[N]);
  }
}

int main()
{

  int T;
  scanf("%d", &T);
  int N;
  for (int i = 0; i < T; i++)
  {
    scanf("%d", &N);
    sum(N);
  }

  return 0;
}