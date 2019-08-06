#include "level_hashing.hpp"
#include <string>

int main() {

	int level_size = 10;
	level_hash *level = level_init(level_size);

	char key1[10] = "aaa";
	char value1[10] = "lala";
	char key2[10] = "bbb";
	char value2[10] = "lolo";

	/**
	 * 	insert
	 */
	if (!level_insert(level, (uint8_t *)key1, (uint8_t *)value1))
	{
		printf("insert success\n");
	} else {
		printf("insert fail\n");
	}
	if (!level_insert(level, (uint8_t *)key2, (uint8_t *)value2))
	{
		printf("insert success\n");
	} else {
		printf("insert fail\n");
	}
	if (!level_insert(level, (uint8_t *)key1, (uint8_t *)value1))
	{
		printf("insert success\n");
	} else {
		printf("insert fail\n");
	}

	/**
	 * 	query
	 */
	printf("\nquery:\n");
	char* get_value1 = (char *)level_static_query(level, (uint8_t *)key1);
	printf("key=%s\tvalue=%s\n", key1, get_value1);
	char* get_value2 = (char *)level_dynamic_query(level, (uint8_t *)key2);
	printf("key=%s\tvalue=%s\n", key2, get_value2);

	/**
	 * 	update
	 */
	printf("\nupdate:\n");
	char tmp[10] = "lulu";
	if (!level_update(level, (uint8_t *)key1, (uint8_t *)tmp))
	{
		get_value1 = (char *)level_dynamic_query(level, (uint8_t *)key1);
		printf("key=%s\tvalue=%s\n", key1, get_value1);
	}

	/**
	 * 	delete
	 */
	printf("\ndelete\n");
	printf("The number of items stored in the level hash table: %ld\n",
				(long)(level->level_item_num[0]+level->level_item_num[1]));
	if (!level_delete(level, (uint8_t *)key1))
	{
		printf("key1 is deleted\n");
		if (level_dynamic_query(level, (uint8_t *)key1)==NULL)
		{
			printf("no key1\n");
			printf("The number of items stored in the level hash table: %ld\n",
				(long)(level->level_item_num[0]+level->level_item_num[1]));
		} else {
			printf("key1 exists\n");
		}
	}

	printf("\ndelete\n");
	printf("The number of items stored in the level hash table: %ld\n",
				(long)(level->level_item_num[0]+level->level_item_num[1]));
	if (!level_delete(level, (uint8_t *)key1))
	{
		printf("key1 is deleted\n");
		if (level_dynamic_query(level, (uint8_t *)key1)==NULL)
		{
			printf("no key1\n");
			printf("The number of items stored in the level hash table: %ld\n",
				(long)(level->level_item_num[0]+level->level_item_num[1]));
		} else {
			printf("key1 exists\n");
		}
	}

	level_destroy(level);
	return 0;
}
