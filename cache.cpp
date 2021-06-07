#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include "cache.h"
#include "datetime_utils.h"

void SimpleCache::put(std::string key, std::string value, long ttl)
{
	SimpleCache::EntryWithTtl entry(value, ttl);
	cache[key] = entry;
}

void SimpleCache::put(std::string key, std::string value)
{
	SimpleCache::put(key, value, -1);
}

std::string SimpleCache::get(std::string key)
{
	SimpleCache::EntryWithTtl entry = cache[key];
	if (entry.get_ttl() > current_time())
	{
		return cache[key].get();
	}
	cache.erase(key);
	return "NIL";
}

