#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r)
{
	if (r.buses.empty())
	{
		os << "No stop";
	}
	else
	{
		for (auto& bus : r.buses)
		{
			os << bus << " ";
		}
	}
	os << std::endl;

	return os;
}



std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r)
{
	if (r.stop_for_buses.empty())
	{
		os << "No bus" << std::endl;
	}
	else
	{
		for (const auto& stop : r.stop_for_buses)
		{
			os << "Stop " << stop.first << ": ";

			if (stop.second.size() == 1)
			{
				os << "no interchange";
			}
			else
			{
				for (const auto& other_bus : stop.second)
				{
					if (r.bus != other_bus)
					{
						os << other_bus << " ";
					}
				}
			}

			os << std::endl;
		}
	}

	return os;
}



std::ostream& operator << (std::ostream& os, const AllBusesResponse& r)
{
	if (r.bus_and_stops.empty())
	{
		os << "No buses" << std::endl;
	}
	else
	{
		for (const auto& bus : r.bus_and_stops)
		{
			os << "Bus " << bus.first << ": ";

			for (const auto& stop : bus.second)
			{
				os << stop << " ";
			}
			os << std::endl;
		}
	}

	return os;
}