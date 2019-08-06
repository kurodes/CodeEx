#include <iostream>
#include <string>
#include <bitset>

int main () {
	int32_t sid;
	int64_t suuid;
	int32_t oid;
	sid = 0x42410041;
	suuid = 0x4341414100004141;
	oid = 0x44410041;

	std::bitset<32> sid_b(sid);
	std::bitset<64> suuid_b(suuid);
	std::bitset<32> oid_b(oid);
	//std::bitset<8> end(0);
	std::string key_s;
	//key_s.append(end.to_string());
	key_s.append(sid_b.to_string());
	key_s.append(suuid_b.to_string());
	key_s.append(oid_b.to_string());

	std::bitset<136> key_b(key_s);

	std::string Key_Obj((char *)&key_b);

	std::cout<<Key_Obj<<std::endl;
	return 0;
}
