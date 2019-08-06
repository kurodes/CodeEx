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
	string key("thisis");
	string value("thisis");

	t_start = getSystemTime();
	for (i=0;i<10000;i++) {
		if (db->set(key+to_string(i),value+to_string(i+1)) == false) {
			cout<<"insert false"<<endl;
		}
	}
	t_end=getSystemTime();

	printf("insert time:%lld ms\n", t_end-t_start);

	string tmp("thisis0");
	t_start = getSystemTime();
	for (i=0;i<10000;i++) {
		key = tmp;
		if (db->get(key,&tmp) == false) {
			cout<<"query false"<<endl;
		}
	}
	t_end=getSystemTime();

	printf("query time:%lld ms\n", t_end-t_start);

	db->close();
	return 0;
}

