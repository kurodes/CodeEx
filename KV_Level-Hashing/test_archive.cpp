#include "KVStore.hpp"
#include <iostream>
#include <fstream>
#include <glog/logging.h>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

int main(int argc, char const *argv[]) {

	FLAGS_logtostderr = 1;
	google::InitGoogleLogging(argv[0]);

	KVStore *db1 = new KVStore();
	db1->initDB(14);
	std::string key("/");

	std::ostringstream os;
	boost::archive::binary_oarchive oa(os);
	std::string s1 = "First:Field";
	std::string s2 = "Second:Field";
	std::string s3 = "Third:Field";
	oa<<s1; oa<<s2; oa<<s3;
	std::string value = os.str();

	//std::string value("1 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");

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
