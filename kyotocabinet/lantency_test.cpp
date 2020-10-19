#include <kccachedb.h>
#include <string>
#include <sys/timeb.h>
using namespace std;

long long getSystemTime(){
	struct timeb t;
	ftime(&t);
	return 1000*t.time + t.millitm;
}

int main() {

	long long t_start, t_end;
	kyotocabinet::CacheDB *db(new kyotocabinet::CacheDB());
	db->open("lala", kyotocabinet::CacheDB::OWRITER | kyotocabinet::CacheDB::OCREATE);
	int i;
	string key("key");
	string value("value");

	t_start = getSystemTime();
	for (i=0;i<10000;i++) {
		if (db->set(key+to_string(i),value+to_string(i)) == false) {
			cout<<"insert false"<<endl;
		}
	}
	t_end=getSystemTime();

	printf("insert time:%lld ms\n", t_end-t_start);

	string tmp;
	t_start = getSystemTime();
	for (i=0;i<10000;i++) {
		if (db->get(key+to_string(i),&tmp) == false) {
			cout<<"query false"<<endl;
		}
	}
	t_end=getSystemTime();

	printf("query time:%lld ms\n", t_end-t_start);

	db->close();
	return 0;
}

