#include <ctime>
#include <iostream>
using namespace std;

int missing;
int answer;
int arr[10000];

/* 배열에 랜덤하게 숫자를 할당시킨다. 중복된 숫자는 존재하지 않는다.*/
void set() {
  srand((unsigned int)time(NULL));
  missing = rand() % 10000;
  for (int i = 0; i < 10000; i++) {
    if (i == missing) continue;
    arr[i] = i + 1;
  }
  for (int i = 0; i < 5000; i++) {
    int front = rand() % 10000;
    int back = rand() % 10000;
    int temp;
    temp = arr[front];
    arr[front] = arr[back];
    arr[back] = temp;
  }
}

/* 2차 시간에 빠진 숫자를 찾는다 */
int findMissingNumberDouble() {
  int res;

  return res;
}

/* 선형 시간에 빠진 숫자를 찾는다 */
int findMissingNumberLinear() {
  int res;

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  clock_t start, end;
  double duration;

  set();
  start = clock();
  answer = findMissingNumberDouble();
  end = clock();
  duration = (double)(end - start) / CLOCKS_PER_SEC;
  cout << duration << " sec" << '\n';
  cout << missing << ' ' << answer << ' '
       << (missing == answer ? "correct" : "wrong") << '\n';

  set();
  start = clock();
  answer = findMissingNumberLinear();
  end = clock();
  duration = (double)(end - start) / CLOCKS_PER_SEC;
  cout << duration << " sec" << '\n';
  cout << missing << ' ' << answer << ' '
       << (missing == answer ? "correct" : "wrong") << '\n';

  return 0;
}
