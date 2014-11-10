#include "..\include\RadarData.h"
#include "..\include\RadarPointDrawer.h"


RadarData::RadarData(void)
{
	nextUpdatePoint = std::chrono::system_clock::now();
	keepUpdating = true;
}


RadarData::~RadarData(void)
{
}

void RadarData::update(void) {
	if (nextUpdatePoint <= std::chrono::system_clock::now()) {
		// TODO: Do something better than just purging the whole list each time.
		pings.clear();
		// For now, let's not bug the API until we circle back there.
		//loadTrimetVehicles();
		nextUpdatePoint += std::chrono::milliseconds(1000);
	}
	if (pings.size() < 1) {
		TrimetPoint point(ci::Vec2d(0.0, 0.0), "Debug");
		pings.insert(std::make_pair(1, point));
	}
}

void RadarData::draw() {
	for_each(pings.begin(), pings.end(), [this](std::pair<int, TrimetPoint> pair) {
		RadarPointDrawer drawer;
		drawer.drawPoint(pair.second);
	});
}

	/** API Reference: 
vehicle 	Contains all vehicle attributes.
vehicle[@vehicleID] 	Identifies the vehicle.
vehicle[@type] 	Identifies the type of vehile. Can be "bus" or "rail".
vehicle[@blockID] 	Identifies the block number of the vehicle.
vehicle[@bearing] 	Bearing of the vehicle if available. 0 is north, 180 is south.
vehicle[@serviceDate] 	Midnight of the service day the vehicle is performing service for.
vehicle[@locationInScheduleDay] 	Number of seconds since midnight from the scheduleDate that the vehicle is positioned at along its schedule.
vehicle[@time] 	Time this position was initially recorded.
vehicle[@expires] 	Time this vehicle's entry should be discarded if no new position information is received from the vehicle.
vehicle[@longitude] 	Longitude of the vehicle.
vehicle[@latitude] 	Latitude of the vehicle.
vehicle[@routeNumber] 	Route number the vehicle is servicing.
vehicle[@direction] 	Direction of the route the vehicle is servicing.
vehicle[@tripID] 	TripID the vehicle is servicing. Will match published GTFS schedule.
vehicle[@delay] 	Delay of the vehilce along its schedule. Negative is late. Positive is early.
vehicle[@messageCode] 	Identifier for the over head sign message.
vehicle[@signMessage] 	Vehicle's over head sign text message.
vehicle[@signMessageLong] 	Vehicle's full over head sign text message.
vehicle[@nextLocID] 	Location ID (or stopID) of the next stop this vehicle is scheduled to serve.
vehicle[@nextStopSeq] 	Stop sequence for the next stop this vehicle is scheduled to serve. Some trips serve the same stop twice.
vehicle[@lastLocID] 	Location ID (or stopID) of the previous stop this vehicle was scheduled to serve.
vehicle[@lastStopSeq] 	Stop sequence for the next stop this vehicle is scheduled to serve. Some trips serve the same stop twice.
vehicle[@garage] 	Identifies the garage the vehicle originates from.
vehicle[@extraTripID] 	String value identifies a new unscheduled trip the vehicle is servicing. This will not be in the published GTFS schedule.
vehicle[@extrablockID] 	Integer value identifies a new unscheduled block the vehicle is servicing. This will not be in the published GTFS schedule.
vehicle[@offRoute] 	Placeholder for future. Set to true if the vehicle reported that it has gone off route.
vehicle[@inCongestion] (Experimental) 	Set to true if vehicle is reporting its not moving while in traffic. Bus only.
vehicle[@loadPercentage] (Experimental) */


void RadarData::loadTrimetVehicles() {
	ci::ThreadSetup threadSetup;

	const cinder::Url endpoint("http://developer.trimet.org/ws/v2/vehicles?appId=025A6204A70B5C27A98583CE1");
	cinder::JsonTree json;
	cinder::JsonTree::ConstIter jsonIter = json.end();
    json = cinder::JsonTree(loadUrl(endpoint));
	try {
		cinder::JsonTree vehicles = json.getChild("resultSet").getChild("vehicle");
		for_each(vehicles.begin(), vehicles.end(), [this](ci::JsonTree vehicleJson) {
			// Each vehicle becomes a radar point.
			int id = vehicleJson.getValueForKey<int>("vehicleID");
			ci::Vec2d location(vehicleJson.getValueForKey<double>("longitude"), vehicleJson.getValueForKey<double>("latitude"));
			std::string label = vehicleJson.getValueForKey<std::string>("signMessage");
			TrimetPoint point(location, label);
			pings.insert(std::make_pair(id, point));
		});
	}
	catch (...) {}
}
