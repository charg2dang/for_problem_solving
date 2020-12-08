from collections import defaultdict

class disjoint_set:
    def __init__(self, size):
        self.size = size;
        self.dic = defaultdict(lambda: 1);
        self.ns = [];

        for i in range(size + 1):
            self.ns.append(0);

    def get_parent( self, x ) -> None:
        if self.ns[x] == x:
            return x;
        else:
            self.ns[x] = self.get_parent(self.ns[x]);

            return self.ns[x];


    def has_same_parent(l, r) -> bool :
        return get_parent(l) == get_parent(r);


    def union_child(l, r) -> None :
        ll = get_parent(l);
        rr = get_parent(r);

        if l > r :
            self.ns[l] = r;
            self.dic[r] += self.dic[l];
            del self.dic[l];
        else :
            self.ns[r] = l;
            self.dic[l] += self.dic[r];
            del self.dic[r];





