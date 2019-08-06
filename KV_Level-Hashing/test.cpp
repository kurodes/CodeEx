#include "KVStore.hpp"
#include <iostream>
#include <fstream>
#include <glog/logging.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>



int main(int argc, char const *argv[]) {

	FLAGS_logtostderr = 1;
	google::InitGoogleLogging(argv[0]);

	KVStore *db1 = new KVStore();
	db1->initDB(14);
	std::string key("/");


	std::ostringstream os;
	boost::archive::text_oarchive oa(os);
	std::string s1 = "First";
	std::string s2 = "Second";
	int s3 = 123;
	oa<<s1; oa<<s2; oa<<s3;
	std::string value = os.str();

	LOG(INFO)<<"Begin setValue";
	db1->setValue(key, value);
	LOG(INFO)<<"End setValue";

	LOG(INFO)<<"Begin getvalue";
	std::string getvalue;
	db1->getValue(key, getvalue);
	LOG(INFO)<<"End getvalue";

	LOG(INFO)<<"value size="<< getvalue.size()<<" value="<<getvalue;

	std::istringstream is(value);
    boost::archive::text_iarchive ia(is);
    std::string ss1;
	std::string ss2;
	int ss3;
    ia>>ss1; ia>>ss2; ia>>ss3;
    std::cout<<"\n"<<ss1<<"\n"<<ss2<<"\n"<<ss3<<std::endl;

	return 0;
}
