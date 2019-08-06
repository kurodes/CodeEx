#include "KVStore.hpp"

bool KVStore::initDB(uint64_t level_size)
{
	level = level_init(level_size);
	if (level == NULL) {
		LOG(FATAL)<<"DB init failed";
		///printf("DB init failed\n");
		return false;
	}
	LOG(INFO)<<"DB init success";
	///printf("DB init success\n");
	return true;
}

bool KVStore::getValue(const std::string &path, std::string &value)
{
	char* get_value = (char *)level_dynamic_query(level, (uint8_t *)path.c_str());
	if (get_value == NULL) {
		LOG(WARNING)<<"getValue failed: key="<<path;
		///printf("getValue failed: key=%s\n", path.c_str());
		return false;
	} else {
		value = get_value;
		LOG(INFO)<<"getValue success: key="<<path<<" value="<<value;
		///printf("getValue success: key=%s value=%s\n", path.c_str(), value.c_str());
		return true;
	}
}

/**
 * 	if ( query failed ) {
 * 		insert;
 * 	} else {
 * 		update;
 * 	}
 */
bool KVStore::setValue(const std::string &path, const std::string & value)
{
	if (level_dynamic_query(level, (uint8_t *)path.c_str())==NULL) {
		///printf("insert new kv\n");
		if (!level_insert(level, (uint8_t *)path.c_str(), (uint8_t *)value.c_str())) {
			LOG(INFO)<<"insert new kv success: key="<<path<<" value="<<value;
			///printf("insert new kv success: key=%s value=%s\n", path.c_str(), value.c_str());
			return true;
		} else {
			LOG(ERROR)<<"insert new kv fail";
			///printf("insert new kv fail\n");
			return false;
		}
	} else {
		///printf("update old kv\n");
		if (!level_update(level, (uint8_t *)path.c_str(), (uint8_t *)value.c_str())) {
			LOG(INFO)<<"update old kv success: key="<<path<<" value="<<value;
			///printf("update old kv success: key=%s value=%s\n", path.c_str(), value.c_str());
			return true;
		} else {
			LOG(ERROR)<<"update old kv failed";
			///printf("update old kv failed\n");
			return false;
		}
	}
}

bool KVStore::remove(const std::string &path)
{
	if (!level_delete(level, (uint8_t *)path.c_str())) {
		LOG(INFO)<<"remove kv success: key="<<path;
		///printf("remove kv success: key=%s\n", path.c_str());
		return true;
	} else {
		LOG(WARNING)<<"remove kv failed: key="<<path<<" not exist";
		///printf("remove kv failed: key=%s\n", path.c_str());
		return false;
	}
}
