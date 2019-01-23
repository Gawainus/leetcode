#define once

#include <list>
#include <unordered_map>

class LRUCache {
    using Hist = std::list<int>;    // the int is the key for keeping the history
    using HistValuePair = std::pair<Hist::iterator, int>; // storing the history and the value
    using Cache = std::unordered_map<int, HistValuePair>;


public:
    LRUCache(int capacity): m_capacity(capacity) {

    }

    int get(int key) {
        const auto iter = m_cache.find(key);
        if (iter == m_cache.end())
            return -1;

        return touch(iter);
    }

    void put(int key, int value) {
        const auto iter = m_cache.find(key);

        if (iter == m_cache.end()) // new value
        {
            // insert
            m_hist.push_front(key);
            m_cache[key] = {m_hist.begin(), value};
        }
        else {// updating existing key
            touch(iter);
            iter->second.second = value;
        }

        // kick out the least recent element
        if (m_cache.size() > m_capacity)
        {
            int key = m_hist.back();
            m_hist.pop_back();
            m_cache.erase(key);
        }
    }

private:

    // functions

    // update history and return the value
    int touch(Cache ::iterator it) {
        int key = it->first;

        auto & pair = it->second;
        m_hist.erase(pair.first);
        m_hist.push_front(key);
        pair.first = m_hist.begin();
        return pair.second;
    }

    // members
    int m_capacity;
    Hist m_hist;
    Cache m_cache;
};
