struct Node{
    public:
        int key, val;
        Node* next;
        Node(int k, int v, Node* n)
        {
            key = k, val = v, next = n;
        }
};

class MyHashMap {
    
    //EXPLANATION: https://leetcode.com/problems/design-hashmap/discuss/1097755/JS-Python-Java-C%2B%2B-or-(Updated)-Hash-and-Array-Solutions-w-Explanation
    
public:

    //Reason for choice of size and mult: For the size, I wanted something that was larger than the number of possible operations (10^4), but as small as possible without risking too many collisions, and preferably prime. 
    //The mult is just a random large multiplier, also preferably a prime.
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size];
    
    
    int hash(int key) {
            return (int)((long)key * mult % size);
        }
    void put(int key, int val) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, val, data[h]);
        data[h] = node;
    }    
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key) return node->val;
        return -1;
    }    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) return;
        if (node->key == key) data[h] = node->next;
        else for (; node->next != NULL; node = node->next)
            if (node->next->key == key) {
                node->next = node->next->next;
                return;
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */