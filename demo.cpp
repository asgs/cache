#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#include "cache.h"
#include "datetime_utils.h"

int main() {
	SimpleCache<std::string, std::string> cache;

	std::string value1 = "1";
	std::string key1 = "a";
	cache.put(key1, value1, current_time() + 3);

	std::string value2 = "2";
	std::string key2 = "b";
	cache.put(key2, value2, current_time() + 11);

	cache.print();
	std::this_thread::sleep_for(std::chrono::seconds(5));

	cache.print();
	//std::cout << "value of key " << key1 << " is " << cache.get(key1);
	//std::cout << std::endl << "value of key " << key2 << " is " << cache.get(key2);
}

