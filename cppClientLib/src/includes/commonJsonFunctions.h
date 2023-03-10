#pragma once
#include <string>

enum class JsonRequests : uint8_t
{
	Set_motors = 0,
	Left,
	Right,
	Foreward,
	Backward,
	Stop,
	Disconnect
};

enum class HTTPReq : uint8_t
{
	None,
	Get,
	Post,
	Shutdown
};

enum class Result : uint8_t
{
	FailedToSend = 0,
	Succeeded = 1,
};

const int PackageSize = 2000;
const int PackageSizeInBytes = PackageSize*sizeof(int);

struct MotionSpeed
{
	MotionSpeed(
		const float leftMotor,
		const float rightMotor = 0.0f
	);
	MotionSpeed();
	const bool isSingleMotion() const;
	float leftMotor;
	float rightMotor;
};

namespace JsonFunction
{
const std::string prepareHTTPReqPost(
	HTTPReq request,
	int sizeToSendInBytes
);
const int getReqAndSize(
	const std::string& msg,
	HTTPReq& req
);
const bool getJsonRequest(
	const std::string& msg,
	JsonRequests& req
);
const std::string createJsonAsString(
	const char* function,
	const MotionSpeed& motionSpeed
);
};
