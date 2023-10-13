import sys
import heapq
from bisect import bisect_left, bisect_right
from collections import deque, Counter
from itertools import permutations, product, combinations, combinations_with_replacement
import math


N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))

dp = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

"""
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }
"""

for i in range(1, N + 1):
    for j in range(1, i + 1):  # i까지 N 까지보내서 오류
        dp[i][j] = arr[i - 1][j - 1] + \
            max(dp[i - 1][j], dp[i - 1][j - 1])  # 감사합니다

print(max(dp[N]))
