import time
import random

missing = None
answer = None
arr = [None] * 10000
cnt=int 
sum=int


# 배열에 랜덤하게 숫자를 할당시킨다. 중복된 숫자는 존재하지 않는다.
def set_arr():
    global missing
    missing = random.randint(0, 9999)
    for i in range(10000):
        if i != missing:
            arr[i] = i

    for _ in range(5000):
        front, back = random.randint(0, 9999), random.randint(0, 9999)
        arr[front], arr[back] = arr[back], arr[front]


# (2차 시간)에 빠진 숫자를 찾는다
def find_missing_number_double():
   
    for i in range(10000):
        cnt=0
        for j in range(10000):
            if arr[i]==j:
                cnt+=1
        if cnt==0:
            return arr[i]

   


# 선형 시간에 빠진 숫자를 찾는다
def find_missing_number_linear():
    sum=0
    for i in range(1,10001):
        sum+=i
        sum-=arr[i]
    return sum

    
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
