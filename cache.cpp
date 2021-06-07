#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include "cache.h"
#include "datetime_utils.h"

std::string EntryWithTtl::get() 
{
	long current = current_time();
	if (ttl > current) 
	{
		//std::cout << "current_time is " << current << ";ttl is " << ttl << " and entry is " << entry << std::endl;
		return static_cast<std::string>(entry);
	}
	else
	{
		return "NIL";
	}
}

long EntryWithTtl::get_ttl() {
	return ttl;
}

void SimpleCache::put(std::string key, EntryWithTtl value)
{
	cache[key] = value;
}

std::string SimpleCache::get(std::string key)
{
	EntryWithTtl entry = cache[key];
	if (entry.get_ttl() > current_time())
	{
		return cache[key].get();
	}
	return "NIL";
}

std::map<std::string, EntryWithTtl> SimpleCache::get_map()
{
	return this -> cache;
}

std::ostream& operator<<(std::ostream& os, EntryWithTtl& e)
{
	//std::cout << "e.get() is " << e.get() << std::endl;
	return os << e.get();
}

/*std::ostream& operator<<(std::ostream& os, SimpleCache& c)
{
	return os << c.get_map();
}*/

