#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <iostream>
#include <fstream>

void save()
{
  std::ofstream file("archive.txt");
  boost::archive::text_oarchive oa(file);
  std::string s1 = "First_Field";
  std::string s2 = "Second_Field";
  std::string s3 = "Third_Field";
  oa & s1; // has same effect as oa << s
  oa & s2;
  oa & s3;
}

void load()
{
  std::ifstream file("archive.txt");
  boost::archive::text_iarchive ia(file);
  std::string s;
  ia & s; // has same effect as oa >> s
  std::cout << s << std::endl;
  ia & s;
  std::cout << s << std::endl;
  ia & s;
  std::cout << s << std::endl;

}
int main()
{
  save();
  load();
  return 0;
}

