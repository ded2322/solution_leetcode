class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (m_rundom_value.find(val) != m_rundom_value.end())
            return false;
        elements.push_back(val);
        m_rundom_value[val] = elements.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (m_rundom_value.find(val) == m_rundom_value.end())
            return false;
        int index = m_rundom_value[val];
        int element = elements[elements.size() - 1];
        std::swap( elements[index], elements[elements.size() - 1] );
        m_rundom_value[element] = index;
        elements.pop_back();
        m_rundom_value.erase(val);
        return true;
    }

    int getRandom() {
        return elements[rand() % elements.size()];
    }
private:
    std::vector<int> elements;
    std::unordered_map<int, int> m_rundom_value;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */