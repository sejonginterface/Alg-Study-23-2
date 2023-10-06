import sys
import heapq
from bisect import bisect_left, bisect_right
from collections import deque, Counter
from itertools import permutations, product, combinations, combinations_with_replacement
import math


def main():
    # 궁금하신 분들은 찾아 보셔도 좋습니다
    # sys.stdin.readline() -> 입력줄 전체를 입력받기
    # strip() -> 문자열 줄바꿈 문자 제거
    # map(int, iter) -> iter의 각각 모든 원소에 int() 적용
    # [ ~ for i in range(n)] -> 리스트 컴프리헨션, 리스트 내부에서 반복문
    n = int(input())
    board = [list(map(int, sys.stdin.readline().strip())) for _ in range(n)]
    print(board)


if __name__ == '__main__':
    main()
