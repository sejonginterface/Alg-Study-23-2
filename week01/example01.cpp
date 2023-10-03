#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int N;
char S[1000];
char board[64][64];

void compressTree(int r, int c, int size, char board[64][64])
{
  int newSize;
  for (int i = r; i < r + size; i++)
  {
    for (int j = c; j < c + size; j++)
    {
      if (board[r][c] != board[i][j])
      {
        newSize = size / 2;
        strcat(S, "(");
        compressTree(r, c, newSize, board);
        compressTree(r, c + newSize, newSize, board);
        compressTree(r + newSize, c, newSize, board);
        compressTree(r + newSize, c + newSize, newSize, board);
        strcat(S, ")");
        return;
      }
    }
  }
  if (board[r][c] == '0')
  {
    strcat(S, "0");
  }
  else
  {
    strcat(S, "1");
  }
}
int main()
{
  scanf("%d", &N);
  getchar();
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      scanf("%c", &board[i][j]);
    getchar();
  }
  compressTree(0, 0, N, board);

  printf("%s", S);

  return 0;
}