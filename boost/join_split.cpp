#include <iostream>
#include <boost/algorithm/string.hpp>
//#include <string>

int main()
{
    std::string lala;
    lala.append("la");
    lala.append("la");
    std::cout<<lala<<std::endl;
    return 0;
}

// int main()
// {
//     uint64_t uuid = 1000;
//     std::string filename("Lala.txt");

//     std::string sbuf;
//     std::vector<std::string> vbuf;
//     vbuf.push_back(std::to_string(uuid));;
//     vbuf.push_back(filename);

//     if (vbuf.size() != 0) {
//         sbuf = boost::join(vbuf, ":");
//     }

//     std::cout<<sbuf<<std::endl;

//     if (strlen(sbuf.c_str()) != 0) {
//         boost::split(vbuf, sbuf, boost::is_any_of(":"), boost::token_compress_on);
//     }

//     std::cout<<stoi(vbuf[0])<<" | "<<vbuf[1]<<std::endl;

//     return 0;
// }

//boost::lexical_cast<std::string>(fname->uuid())

/*void gen_key(std::string &key);

int main()
{
    std::string key;
    gen_key(key);
    std::cout<<key<<std::endl;
    return 0;
}

void gen_key(std::string &key) {
    key = "lala";
    return;
}*/
