#include <string>
#include <map>
#include <iostream>
#ifndef CACHE_H
#define CACHE_H
#include "datetime_utils.h"

template<class K, class V>
class SimpleCache
{
	class EntryWithTtl {
		private:
			K entry;
			long ttl;

		public:
			EntryWithTtl()
			{
				EntryWithTtl("NIL", -1);
			}

			EntryWithTtl(K entry, long ttl)
			{
				this -> entry = entry;
				this -> ttl = ttl;
			}

			K get()
			{
				return entry;
			}

			long get_ttl()
			{
				return ttl;
			}

	};

	private:
		std::map<K, EntryWithTtl> cache;

	public:
		void put(K key, V value, long ttl)
		{
			typename SimpleCache::EntryWithTtl entry(value, ttl);
			cache[key] = entry;
		}

		void put(K key, V value)
		{
			SimpleCache::put(key, value, -1);
		}

		V get(K key)
		{
			typename SimpleCache::EntryWithTtl entry = cache[key];
			if (entry.get_ttl() >= current_time())
			{
				return cache[key].get();
			}
			std::cerr << "Key " << key << " exceeded TTL. Removing it" << std::endl;
			cache.erase(key);
			return "";
		}

		void print()
		{
			for (auto it = cache.begin(); it != cache.end(); it++)
			{
				K key = it->first;
				V value = get(key);
				if (value != "")
				{
					std::cout << key << ":" << value << ",";
				}
			}

			std::cout << std::endl;
		}

		//friend std::ostream& operator<<(std::ostream& os, SimpleCache::EntryWithTtl& e);
};

/*std::ostream& operator<<(std::ostream& os, SimpleCache::EntryWithTtl& e)
{
        //std::cout << "e.get() is " << e.get() << std::endl;
        return os << e.get();
}*/

/*std::ostream& operator<<(std::ostream& os, SimpleCache& c)
{
        return os << c.get_map();
}*/

#endif // CACHE_H
