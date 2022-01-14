
class MyHashMap
{

    // EXPLANATION: https://leetcode.com/problems/design-hashmap/discuss/1097755/JS-Python-Java-C%2B%2B-or-(Updated)-Hash-and-Array-Solutions-w-Explanation

public:
    // We are using a linked list based approach to reduce collisions that might happen in an array
    struct Node
    {
    public:
        int key, val;
        Node *next;
        Node(int k, int v, Node *n)
        {
            key = k, val = v, next = n;
        }
    };
    // Reason for choice of size and mult: For the size, I wanted something that was larger than the number of possible operations (10^4), but as small as possible without risking too many collisions, and preferably prime.
    // The mult is just a random large multiplier, also preferably a prime.
    const static int size = 19997;
    const static int mult = 12582917;
    Node *data[size];

    int hash(int key) // hashing function
    {
        return (int)((long)key * mult % size);
    }

    void put(int key, int value)
    {
        remove(key);
        int h = hash(key);
        Node *node = new Node(key, value, data[h]);
        data[h] = node;
    }

    int get(int key)
    {
        int h = hash(key);
        Node *node = data[h];
        while (node)
        {
            if (node->key == key) // moving till desired key is found
                return node->val;
            node = node->next;
        }
        return -1;
    }

    void remove(int key)
    {
        int h = hash(key);
        Node *node = data[h];
        if (!node)
            return;

        if (node->key == key)
            data[h] = node->next;

        else
        {
            while (node->next)
            {
                if (node->next->key == key) // moving till desired key is found
                {
                    node->next = node->next->next;
                    return;
                }
                node = node->next;
            }
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