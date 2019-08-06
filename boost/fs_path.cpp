#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;

int main() {
	boost::filesystem::path p("/Users/apple/Desktop/LocoFS/Loco/data/");
	std::cout << p.string() << std::endl;
	std::cout << p.generic_string() << std::endl;
	return 0;
}
