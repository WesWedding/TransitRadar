#pragma once
#include <map>
#include <TrimetPoint.h>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <chrono>
#include "cinder\Thread.h"
//#include "cinder\Url.h"
#include "cinder\Json.h"

class RadarData
{
public:
	RadarData(void);
	~RadarData(void);

	void update(void);

protected:
	std::map<int, TrimetPoint> pings;
	std::chrono::time_point<std::chrono::system_clock> nextUpdatePoint;
	bool keepUpdating;

	void loadTrimetVehicles(void);
};

