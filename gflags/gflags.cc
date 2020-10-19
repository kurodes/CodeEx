#include <gflags/gflags.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

DEFINE_bool(big_menu, true, "big menue descriptions");
DEFINE_string(path, "/root/config.json", "path description");

int main(int argc, char **argv)
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    cout << FLAGS_big_menu << endl;
    cout << FLAGS_path << endl;
    return 0;
}