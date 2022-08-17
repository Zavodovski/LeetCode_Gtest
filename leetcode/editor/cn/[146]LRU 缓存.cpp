//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 2339 👎 0
class Node {
public:
    int k, v;
    Node *prev, *nxt;

    Node (int k_, int v_) {
        k = k_; v = v_;
        prev = nxt = nullptr;
    }
};

class LRUCache {
public:
    int c, tot;
    Node *head, *tail;
    unordered_map<int, Node*> dic;

    LRUCache(int capacity) {
        tot = 0;
        c = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->nxt = tail;
        tail->prev = head;
    }

    void remove(Node *node) {
        node->prev->nxt = node->nxt;
        node->nxt->prev = node->prev;
    }

    void insert_to_tail(Node *node) {
        node->nxt = tail;
        node->prev = tail->prev;

        tail->prev->nxt = node;
        tail->prev = node;
    }

    int get(int key) {
        if (dic.find(key) == dic.end())
            return -1;

        Node *node = dic[key];
        remove(node);
        insert_to_tail(node);

        return node->v;
    }

    void put(int key, int value) {
        if (dic.find(key) != dic.end()) {
            Node *node = dic[key];

            node->v = value;

            remove(node);
            insert_to_tail(node);
        } else {
            if (tot == c) {
                Node *node = head->nxt;
                dic.erase(node->k);

                remove(node);

                delete node;
                tot--;
            }

            Node *node = new Node(key, value);

            dic[key] = node;
            insert_to_tail(node);

            tot++;
        }
    }
};


//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
public:

    struct Node
    {
        int val, key;
        Node *left, *right;
        Node() : key(0), val(0), left(nullptr), right(nullptr) {}
    };
    Node *hu, *tu;
    Node *hr, *tr;
    std::unordered_map<int, Node*> hash;
    int n;

    void delete_node(Node* p)
    {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    void insert_node(Node* h, Node* p)
    {
        p->right = h->right; h->right = p;
        p->left = h; p->right->left = p;
    }


    LRUCache(int capacity)
    {
        n = capacity;
        hu = new Node(), tu = new Node();
        hr = new Node(), tr = new Node();

        hu->right = tu, tu->left = hu;
        hr->right = tr, tr->left = hr;

        for(int i = 0; i < n; i ++)
        {
            Node* p = new Node();
            insert_node(hr, p);
        }
    }
    
    int get(int key)
    {
        if(hash[key])
        {
            Node* p = hash[key];
            delete_node(p);
            insert_node(hu, p);
            return p->val;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(hash[key])
        {
            Node* p = hash[key];
            delete_node(p);
            insert_node(hu, p);
            p->val = value;
            return;
        }

        if(!n)
        {
            n ++;
            Node* p = tu->left;
            hash[p->key] = 0;
            delete_node(p);
            insert_node(hr, p);
        }

        n --;
        Node* p = hr->right;
        p->key = key, p->val = value, hash[key] = p;
        delete_node(p);
        insert_node(hu, p);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
