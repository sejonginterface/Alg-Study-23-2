
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**

 * 1 ->1        1개
 * 2 -> 1+1,2   2개
 * 3 -> 3, 2+1  3개
 * 4 -> 3+1,2+2,1+3 7개
 * 5 -> 1+4,2+3,3+2,4+1 
 * 6 -> 1+5,2+4,3+3,4+2,5+1
 */

int dp[11];  

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,M;
  cin >> M;
  for(int i=0;i<M;i++)
  {  
    cin >> N;
    for (int i = 0; i <= N; i++) {  
                                    
      dp[i] = 1700; 
    }
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 1; i <= N; i++) {
      // 완성 못시키는 배열 같은 경우에는 dp배열값이 0으로 되어있것
      dp[i] = ((dp[i - 1] + 1)+( dp[i - 2] + 1)+(dp[i-3]+1));
      // dp배열에 값을 기록, 저장, 메모이제이션
    }
  }
  if (dp[N] >= 2000) {  // 절대 제대로 포장될수 없는 값 위에 초기화한값이랑
                        // 같아도 됨 대력 1700쯤
    cout << -1;
  } else {
    cout << dp[N];
  }

  return 0;
}