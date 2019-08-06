#ifndef KVStore_hpp
#define KVStore_hpp

#include "level_hashing.hpp"
#include <string>
#include <glog/logging.h>

class KVStore{

private:
	level_hash *level;

public:
    KVStore():level(NULL){};

    ~KVStore() {
    	level_destroy(level);
    };

    bool initDB(uint64_t level_size);
    bool getValue(const std::string &path, std::string &value);
    bool setValue(const std::string &path, const std::string & value);
    bool remove(const std::string &path);
};

#endif
