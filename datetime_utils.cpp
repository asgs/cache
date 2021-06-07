#include "datetime_utils.h"
#include <ctime>

long current_time()
{
	return (long)std::time(nullptr);
}
