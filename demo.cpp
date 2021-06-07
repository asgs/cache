#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#include "cache.h"
#include "datetime_utils.h"

int main() {
	SimpleCache cache;
	std::string value1 = "1";
        std::string key1 = "a";
        EntryWithTtl entry1(value1, current_time() + 3);

        std::string value2 = "2";
        std::string key2 = "b";

        EntryWithTtl entry2(value2, current_time() + 10);
	cache.put(key1, entry1);
	cache.put(key2, entry2);

	std::this_thread::sleep_for(std::chrono::seconds(5));


	//std::cout << "Cache is " << cache;
	std::cout << "value of key " << key1 << " is " << cache.get(key1);
	std::cout << std::endl << "value of key " << key2 << " is " << cache.get(key2);
}

