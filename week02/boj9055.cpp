#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int dp[12];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  dp[1]=1;
  dp[2]=2; 
  dp[3]=4; 
  dp[4]=7;
  
  for (int i = 5; i < 11; i++)
  {
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
  }
  
  for (int i = 0; i < N; i++)
  {
    int n;
    cin >> n;
    cout << dp[n] <<endl;
  }
  
  return 0;
}