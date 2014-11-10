#pragma once
#include "d:\development\projects\cinder_master\include\cinder\json.h"
class VehicleJson :
	public cinder::JsonTree
{
public:
	int getvehicleID(void);
	std::string getType(void);
	int getBlockID(void);
	float getBearing(void);
	int getServiceDate(void);
	int getLocationInScheduleDay(void);
	int getTime(void);
	int getExpires(void);
	float getLongitude(void);
	float getLatitude(void);
	int getRouteNumber(void);
	int getDirection(void);
	int getTripID(void);
	int getDelay(void);
	int getMessageCode(void);
	std::string getSignMessage(void);
	std::string getSignMessageLong(void);
	int getNextLocId(void);
	int getNextStopSeq(void);
	int getLastLocId(void);
	int getLastStopSeq(void);
	int getGarage(void);
	int getExtraTripId(void);
	int getExtraBlockId(void);
	bool getOffRoute(void);
	bool getInCongestion(void);
	int getLoadPercentage(void);
	
	VehicleJson(void);
	VehicleJson(cinder::JsonTree);
	~VehicleJson(void);

private:
	cinder::JsonTree json;
};

