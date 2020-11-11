#include <kcpolydb.h>
#include <kcthread.h>

using namespace std;

int main(int *argc, char **argv)
{
    kyotocabinet::PolyDB *db = new kyotocabinet::PolyDB();
    if (db->open("%", kyotocabinet::CacheDB::OWRITER | kyotocabinet::CacheDB::OCREATE) == false)
        return -1;

    auto lala = new kyotocabinet::RWLock;
    auto lolo = lala->lock_reader_try();

    db->set("0", "0000");
    int *key = (int *)malloc(1 * sizeof(int));
    *key = 1;
    int *value = (int *)malloc(2 * sizeof(int));
    *value = 1;
    *(value + 1) = 1;
    db->set(key, 1 * sizeof(int), value, 2 * sizeof(int));

    // traverse records
    kyotocabinet::PolyDB::Cursor *cur = db.cursor();
    cur->jump();
    string ckey, cvalue;
    while (cur->get(&ckey, &cvalue, true))
    {
        cout << ckey << ":" << cvalue << endl;
    }
    delete cur;

    if (!db->close())
        return -1;
    return 0;
}