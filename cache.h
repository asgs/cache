#include <string>
#include <map>
#ifndef CACHE_H
#define CACHE_H

class SimpleCache
{

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

			std::string get()
			{
				return entry;
			}

			long get_ttl()
			{
				return ttl;
			}

	};

	private:
		std::map<std::string, EntryWithTtl> cache;

	public:
		void put(std::string key, std::string value);

		void put(std::string key, std::string value, long ttl);

		std::string get(std::string key);

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
