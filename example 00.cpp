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
  for (int i = 0; i < 10000; i++) // Random Number Allocation
  {
    if (i == missing)
      continue;
    arr[i] = i;
  }
  for (int i = 0; i < 5000; i++) // Shuffle Random Number Index
  {
    int front = rand() % 10000;
    int back = rand() % 10000;
    int temp;
    temp = arr[front];
    arr[front] = arr[back];
    arr[back] = temp;
  }
}

/* 2차 시간에 빠진 숫자를 찾는다 == 중첩 반복문 반드시 사용*/
int findMissingNumberDouble()
{
  int res; // DO NOT REMOVE

  int mem[10000] = {0}; // bool로 사용
  int i;

  for (i = 0; i < 10000; i++)
    mem[arr[i]] = 1;

  for (i = 0; i < 10000; i++)
  {
    if (mem[arr[i]])
      continue;
    else
    {
      res = arr[i];
      break;
    }
  }

  return res; // DO NOT REMOVE
}

/* 선형 시간에 빠진 숫자를 찾는다 == 중첩 아닌 반복문 반드시 사용*/
int findMissingNumberLinear()
{
  int res;

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
  start = clock(); // Mac의 경우 컴파일 에러 가능성, 오류 뜨면 지워버려라!
  answer = findMissingNumberDouble();
  end = clock();
  duration = (double)(end - start) / CLOCKS_PER_SEC;
  cout << duration << " sec" << '\n';
  cout << (missing == answer ? "correct" : "wrong") << '\n';

  set();
  start = clock(); // Mac의 경우 컴파일 에러 가능성, 오류 뜨면 지워버려라!
  answer = findMissingNumberLinear();
  end = clock();
  duration = (double)(end - start) / CLOCKS_PER_SEC;
  cout << duration << " sec" << '\n';
  cout << missing << ' ' << answer << ' '
       << (missing == answer ? "correct" : "wrong") << '\n';

  return 0;
}