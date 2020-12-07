
#import random;


#for i  in range(10):
#    print(random.randint(1, 10));

from random import randint;

print(randint(1, 100));


# 모듈(Module) 사용하기
import datetime
import math
import math as m
from math import pi
from math import *

# import datetime
now = datetime.datetime.now()
print(now)

# import math
print("The value of pi is", math.pi)

# import math as m
print("The value of pi is", m.pi)

# from math import pi
print("The value of pi is", pi)

# from math import *
print("The value of e is", e)
