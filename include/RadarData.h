#pragma once
#include <map>
#include <TrimetPoint.h>
#include <chrono>
#include "cinder\Thread.h"
#include "cinder\Json.h"

class RadarData
{
public:
	RadarData(void);
	~RadarData(void);

	void update(void);
	void draw();

protected:
	std::map<int, TrimetPoint> pings;
	std::chrono::time_point<std::chrono::system_clock> nextUpdatePoint;
	bool keepUpdating;

	void loadTrimetVehicles(void);
};

