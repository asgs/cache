#include <string>
#include <map>
#ifndef CACHE_H
#define CACHE_H

class EntryWithTtl {
	private: 
		std::string entry;
		long ttl;

	public:
		EntryWithTtl() {
			EntryWithTtl("NIL", -1);
		}

		EntryWithTtl(std::string entry, long ttl) {
			this -> entry = entry;
			this -> ttl = ttl;
		}

		std::string get();

		long get_ttl();

};

class SimpleCache
{
	private:
		std::map<std::string, EntryWithTtl> cache;

	public:
	 	void put(std::string key, EntryWithTtl value);

		std::string get(std::string key);

		std::map<std::string, EntryWithTtl> get_map();
};	

#endif // CACHE_H
