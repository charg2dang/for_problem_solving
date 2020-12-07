
class node:
    def __init__(self, data = None):
        self.data = data;
        self.prev = None;
        self.next = None;


class list:
    def __init__(self):
        self.head = node();
        self.tail = self.head;
        self.size = 0;


    def push_back(self, src) -> None :
        new_node = node(src);

        self.tail.next = new_node;
        new_node.prev = self.tail;

        self.tail = new_node;
        self.size += 1;

    def pop_back(self) -> object :
        if self.size == 0:
            return None;

        poped_node = self.tail;
        self.tail = poped_node.prev;

        self.size -= 1;

        return poped_node.data;


    def get_size(self):
        return self.size;


l = list()
l.push_back(1);
l.push_back(2);

print( l.get_size() );

print( l.pop_back() );
print( l.pop_back() );
print( l.pop_back() );

l.push_back(4);
l.push_back(7);

print( l.pop_back() );
print( l.pop_back() );
print( l.pop_back() );
