#include "query.h"

std::istream& operator >> (std::istream& is, Query& q)
{
	std::string _type;
	is >> _type;

	if (_type == "NEW_BUS")
	{
		q.type = QueryType::NewBus;
		is >> q.bus;

		int count_of_stops = 0;
		is >> count_of_stops;

		q.stops.resize(count_of_stops);
		for (auto& stop : q.stops)
		{
			is >> stop;
		}
	}

	else if (_type == "BUSES_FOR_STOP")
	{
		q.type = QueryType::BusesForStop;

		is >> q.stop;
	}

	else if (_type == "STOPS_FOR_BUS")
	{
		q.type == QueryType::StopsForBus;

		is >> q.bus;
	}

	else if (_type == "ALL_BUSES")
	{
		q.type = QueryType::AllBuses;
	}

	return is;
}