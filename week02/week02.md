## DP (동적 계획법)

핵심은 메모이제이션과 최적 부분 구조

1. 메모이제이션

    단어는 어색할 수 있지만 사실 우리에게 아주 익숙한 방식이고 내용이다. 가장 간단한 예시로 구구단이 있다.  
    우리는 $3 \times 7$ 을 구하려면 원래는 $3$을 $7$번 더해야만 했다. 하지만 $3 \times 7$이 21이라는 사실을 알면 문제를 듣자마자 즉시 $21$이라는 것을 말할 수 있다.  
    제곱도 마찬가지이다. $2^{10} = 1024$라는 것은 $2$를 $10$번 곱하거나 또는 $2$의 $10$승이 $1024$라는 것을 외우면 바로 말 할 수 있다. 이렇게 특정 입력값에 대하여 결과값을 미리 저장하여 사용하는 것이 메모리제이션이다.  
    문제를 푸는 중에 같은 결과를 여러번 사용해야한다면 저장해두는 것이 유리할 것이다.

2. 최적 부분구조

    먼저 비슷한 예시로 곱셈과 제곱으로 이해하여보자. $3 \times 7 = 21$이라는 것을 우리는 외워서 사용하기로 했다.  
    이 때 $3 \times 8$을 구하라는 문제가 주어진 경우 우리는 $3 \times 7 + 3$으로 정답을 도출할 수 있다. 이제 우리는 $3\times8$을 알게 되었다. $3\times9$가 주어진경우 $3\times8 + 3$으로 역시 구할 수 있을 것이다.  
    이처럼 어떤 특정 문제가 부분문제가 포함된 상태로 나눌 수 있으며 해당 문제의 답이 반드시 부분문제의 답에서 파생된다면 최적 부분 구조를 만족한다. $3\times8$은 반드시 $3\times7$에서 파생되며 $3\times9$는 반드시 $3\times8$에서 파생된다.  
    비슷한 예시로는 가장 짧은 길찾기 등이 있다.

## 알고리즘 예상하기

1. 규칙성

    위 설명을 잘 이해했다면 dp문제는 반드시 어떠한 규칙성이 존재할 때의 해결법이라는 것을 예상할 수 있다. 따라서 규칙성이 주어진 문제는 dp로 해결 가능하다.해당 규칙성을 점화식으로 작성 할 수 있다면 그 자체로 dp법을 적용한 것이 된다.

2. 합의 최대 또는 최소

    매순간 최적의 선택을 해야하기 때문에 최대 또는 최소와 같이 양 끝에 있는 선택이 주로 같이 등장하게 된다.

## 풀어볼 문제

[boj 2839 설탕배달](https://www.acmicpc.net/problem/2839)

[boj 1003 피보나치](https://www.acmicpc.net/problem/1003)

[boj 9055 1,2,3 더하기](https://www.acmicpc.net/problem/9095)