n = 1260; #int(input());

list = [500, 100, 50, 10];

coin_count = 0;
for coin in list:
    coin_count += ( n // coin );
    n %= coin;

print(coin_count);
