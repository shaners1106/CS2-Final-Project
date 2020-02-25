#include "cellClass.h"

Property::Property(int in_value, std::string descr, bool av)
{
	description = descr;
	value = in_value;
	available = av;
	owner = -1;
}
