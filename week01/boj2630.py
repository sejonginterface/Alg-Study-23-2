import sys
import heapq
from bisect import bisect_left, bisect_right
from collections import deque, Counter
from itertools import permutations, product, combinations, combinations_with_replacement
import math


B = 0
W = 0
n = int(input())
board = [list(map(int, sys.stdin.readline().split())) for i in range(n)]
print(board)


# 이 함수의 기능 길이를 받아서 그 길이만큼 종이가 한 색상으로 이루어졌는지 확인하는 함수
def check_color(r, c, size, board):
    global B, W
    for i in range(r, r + size):
        for j in range(c, c + size):
            if board[r][c] != board[i][j]:
                check_color(r, c, size//2, board)
                check_color(r, c + size//2, size//2, board)
                check_color(r + size//2, c, size//2, board)
                check_color(r + size//2, c + size//2, size//2, board)
                return
    # 여기 오려면 반복문에 return 을 안 만나야 하고
    # 결국 종이가 하나로 이루어져있다
    if board[r][c] == 0:
        W += 1
    else:
        B += 1


check_color(0, 0, n, board)
print(B)
print(W)
