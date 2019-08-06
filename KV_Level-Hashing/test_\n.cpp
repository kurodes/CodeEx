#include "KVStore.hpp"
#include <iostream>
#include <glog/logging.h>

int main(int argc, char const *argv[]) {

	FLAGS_logtostderr = 1;
	google::InitGoogleLogging(argv[0]);

	KVStore *db1 = new KVStore();
	db1->initDB(14);
	std::string key("/");
	std::string value("1\n11\n111");

	LOG(INFO)<<"Begin setValue";
	db1->setValue(key, value);
	LOG(INFO)<<"End setValue";

	LOG(INFO)<<"Begin getvalue";
	std::string getvalue;
	db1->getValue(key, getvalue);
	LOG(INFO)<<"End getvalue";

	LOG(INFO)<<"value size="<< getvalue.size()<<" value="<<getvalue;

	return 0;
}
