#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;

int main()
{
	string p1("/A/B");
	string p2("/A/B/");

	boost::filesystem::path path1(p1);
    boost::filesystem::path parent1 = path1.parent_path();
    boost::filesystem::path filename1 = path1.filename();
    cout<<"For "<<p1<<" : "<<parent1<<"   : "<<filename1<<endl;

    boost::filesystem::path path2(p2);
    boost::filesystem::path parent2 = path2.parent_path();
    boost::filesystem::path filename2 = path2.filename();
    cout<<"For "<<p2<<": "<<parent2<<" : "<<filename2<<endl;

	return 0;
}
