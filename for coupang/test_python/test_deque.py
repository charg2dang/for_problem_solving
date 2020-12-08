from collections import deque;

q = deque();

q.append(5)
q.append(4)
q.append(3)
q.append(2)
q.append(1)

for n in range(len(q)):
    print(q.popleft());


s = deque();

s.append(5)
s.append(4)
s.append(3)
s.append(2)
s.append(1)



for n in range(len(s)):
    print(s.pop());
