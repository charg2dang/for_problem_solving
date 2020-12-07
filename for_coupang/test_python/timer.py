import time;

class timer:
    def __init__(self) -> None :
        self.current_time = time.time();
        self.prev_time = self.current_time;
        self.elapsed_time = self.current_time - self.prev_time;

    def update(self) -> None :
        self.prev_time = self.current_time;
        self.current_time = time.time();
        self.elapsed_time = self.current_time - self.prev_time;


    def get_delta_time(self) -> float:
        return self.elapsed_time;

t = timer(); 
time.sleep(1);
t.update();
print( t.get_delta_time() );