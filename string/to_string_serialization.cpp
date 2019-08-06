#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string>
#include <sstream>

typedef struct
{
	int16_t ida;
	int64_t idb;
	int16_t idc;
} id;

namespace boost {
    namespace serialization{
        template<class Archive>
        void serialize(Archive & ar, id &d, const unsigned int version){
            ar & d.ida;
            ar & d.idb;
            ar & d.idc;
        }
    }
}

int main () {
	id uuid;
	uuid.ida = 1;
	uuid.idb = 2;
	uuid.idc = 3;

	std::ostringstream os;
    boost::archive::text_oarchive oa(os);
    oa<<uuid;
    std::string value = os.str();

    std::cout<<value.size()<<std::endl;
    std::cout<<value<<std::endl;
	return 0;
}

