#include <ctime>
#include <iostream>
using namespace std;

int missing;
int answer;
int arr[10000];

/* 배열에 랜덤하게 숫자를 할당시킨다. 중복된 숫자는 존재하지 않는다.*/
void set()
{
  srand((unsigned int)time(NULL));
  missing = rand() % 10000;
  for (int i = 0; i < 10000; i++)
  {
    if (i == missing)
    {
      arr[i] = 0;
    }
    else
    {
      arr[i] = i + 1;
    }
  }
  for (int i = 0; i < 5000; i++)
  {
    int front = rand() % 10000;
    int back = rand() % 10000;
    int temp;
    temp = arr[front];
    arr[front] = arr[back];
    arr[back] = temp;
  }
}

/* 2차 시간에 빠진 숫자를 찾는다 */
int findMissingNumberDouble()
{
  int res;
  int num;
  int flag;

  for (int i = 0; i < 10000; i++)
  {
    num = i + 1;
    flag = 0;
    for (int j = 0; j < 10000; j++)
    {
      if (arr[j] == num)
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      res = num;
      break;
    }
  }
  return res;
}

/* 선형 시간에 빠진 숫자를 찾는다 */
int findMissingNumberLinear()
{
  int res;
  int arrsum = 0;
  int realsum = 0;

  for (int i = 0; i < 10000; i++)
  {
    arrsum += arr[i];
    realsum = realsum + (i + 1);
  }
  res = realsum - arrsum;
  return res;
}

int main()
{
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