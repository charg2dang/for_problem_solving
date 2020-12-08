n = int(input());
cmds = list(map(str, input().split()));


start_x, start_y = 1, 1;

table = {"R" : (1, 0), "U" : (0, -1), "L" : (-1, 0), "D" : (0, 1)};

for cmd in cmds:
    print(start_x, start_y);
    start_x += table[cmd][0];
    start_y += table[cmd][1];

    if 1 > start_x : 
        start_x = 1;
    if start_x > n: 
        start_x = n;
    
    if 1 > start_y : 
        start_y = 1;
    if start_y > n: 
        start_y = n;
    
print(start_x, start_y); 
