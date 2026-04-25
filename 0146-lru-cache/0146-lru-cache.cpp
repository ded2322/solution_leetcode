struct ListNodeLRuCache {
    int p_key;
    int p_value;
    ListNodeLRuCache* p_next;
    ListNodeLRuCache* p_previous;

    ListNodeLRuCache()
        : p_key(0), p_value(0), p_next(nullptr), p_previous(nullptr) {}

    ListNodeLRuCache(int key, int value, ListNodeLRuCache* next, ListNodeLRuCache* previous)
        : p_key(key), p_value(value), 
        p_next(next), p_previous(previous)
    {}

};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity_cache = capacity;
        m_dummy_head = new ListNodeLRuCache();
        m_dummy_tail = new ListNodeLRuCache();
        m_dummy_tail->p_next = m_dummy_head;
        m_dummy_head->p_previous = m_dummy_tail;
    }

    int get(int key) {
        auto find_data = m_map_list_node.find(key);

        if (find_data == m_map_list_node.end()) return -1;
        ListNodeLRuCache* current_list_noda = find_data->second;

        reset_head_cache(current_list_noda);

        return current_list_noda->p_value;
    }

    void put(int key, int value) {
        auto find_key = m_map_list_node.find(key);
        if (find_key != m_map_list_node.end()) {
            auto list_node = find_key->second;
            list_node->p_value = value;
            reset_head_cache(list_node);
        }
        else {
            auto new_noda = new ListNodeLRuCache(key, value, nullptr, nullptr);

            if (m_map_list_node.size() == m_capacity_cache) {
                auto delete_elemet = m_dummy_tail->p_next;
                auto current_elemet = delete_elemet->p_next;

                current_elemet->p_previous = m_dummy_tail;
                m_dummy_tail->p_next = current_elemet;

                m_map_list_node.erase(delete_elemet->p_key);
            }
            auto previos_head_noda = m_dummy_head->p_previous;
            previos_head_noda->p_next = new_noda;
            new_noda->p_previous = previos_head_noda;
            new_noda->p_next = m_dummy_head;
            m_dummy_head->p_previous = new_noda;

            m_map_list_node[key] = new_noda;
        }
    }

private:
    void reset_head_cache(ListNodeLRuCache* current_list_noda) {
        ListNodeLRuCache* next_noda = current_list_noda->p_next;
        ListNodeLRuCache* prev_noda = current_list_noda->p_previous;

        prev_noda->p_next = next_noda;
        next_noda->p_previous = prev_noda;

        auto previos_head_noda = m_dummy_head->p_previous;
        previos_head_noda->p_next = current_list_noda;
        current_list_noda->p_previous = previos_head_noda;
        current_list_noda->p_next = m_dummy_head;
        m_dummy_head->p_previous = current_list_noda;
    }

    int m_capacity_cache{ 0 };
    ListNodeLRuCache* m_dummy_head;
    ListNodeLRuCache* m_dummy_tail;
    std::unordered_map<int, ListNodeLRuCache*> m_map_list_node;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */