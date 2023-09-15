import time
import random

missing = None
answer = None
arr = [0] * 10000


# 배열에 랜덤하게 숫자를 할당시킨다. 중복된 숫자는 존재하지 않는다.
def set_arr():
    global missing
    missing = random.randint(0, 9999)
    for i in range(10000):
        if i != missing:
            arr[i] = i + 1
        else :
            arr[i] = 0

    for _ in range(5000):
        front, back = random.randint(0, 9999), random.randint(0, 9999)
        arr[front], arr[back] = arr[back], arr[front]


# 2차 시간에 빠진 숫자를 찾는다
def find_missing_number_double():
    for i in range(1,10001):
        flag=0
        for j in range(0,10000):
            if i==arr[j]:
                flag=1
                break
        if flag==0:
            return i
    pass


# 선형 시간에 빠진 숫자를 찾는다
def find_missing_number_linear():
    s=50005000
    for i in range(10000):
        s-=arr[i]
    return s
    pass


def main():
    set_arr()
    start_time = time.time()
    answer = find_missing_number_double()
    end_time = time.time()
    duration = end_time - start_time
    print(f"{duration:.4f} sec")
    print(f"{missing} {answer} {'correct' if missing == answer else 'wrong'}")

    set_arr()
    start_time = time.time()
    answer = find_missing_number_linear()
    end_time = time.time()
    duration = end_time - start_time
    print(f"{duration:.4f} sec")
    print(f"{missing} {answer} {'correct' if missing == answer else 'wrong'}")


if __name__ == '__main__':
    main()
