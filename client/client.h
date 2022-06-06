#pragma once
#include <thread>
#include <chrono>
#include "../cppzmq/zmq.hpp"
#include "../dependencies/depend.h"
#include "../Json/Json.h"

class Client
{
	Client(Client& other) = delete;
	Client(Client&& other) = delete;
	Client operator=(Client& other) = delete;
	Client& operator=(Client&& other) = delete;
	bool splitAndSendPackage(
		std::vector<uint8_t>& package
	);
public:
	Client() = default;
	void connect(
		const std::string& port
	);
	Result sendCamera(
		JsonSend sendOpt
	);
	Result sendBuffer(
		const std::string& filename, 
		bool isPhoto
	);
	~Client();
private:
	JsonFile json;
	zmq::context_t context{ 1 };
	zmq::socket_t socket{ context, zmq::socket_type::req };
	zmq::message_t message;
};
