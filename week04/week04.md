## 스택(Stack)과 큐(Queue), 그리고 덱(Dequeue)

값을 저장해둘 수 있는 자료구조이다.

1. 스택 Stack
   뒤에 계속 추가 하는 구조이다.  
   `Push`: 값을 가장 뒤에 채워 넣는다.  
   `Pop`: 가장 뒤의 값을 삭제한다.

2. 큐 Queue
   값을 앞에서 부터 뒤로 추가하는 구조이다.  
   `Push`: 값을 가장 뒤에 채워 넣는다.  
   `Pop`: 가장 앞의 값을 삭제한다.

3. 덱 Dequeue  
   값을 양 방향에서 저부 추가/삭제 할 수 있는 구조이다.
   `Push_front`: 값을 가장 앞에 추가한다.  
   `Pop_front`: 가장 앞의 값을 제거하다.  
   `Push_back`: 값을 가장 뒤에 추가한다.  
   `Pop_back`: 가장 뒤의 값을 제거하다.

    `Push_back`, `pop_back`을 합치면 `stack`으로 사용가능하다.  
     `Push_back`, `pop_front`를 합치면 `queue`로 사용가능하다.

cpp

```cpp
#include <stack>
#include <queue>
#include <deque>
```

python

```python
from collections import deque
```

## 풀어볼 문제
