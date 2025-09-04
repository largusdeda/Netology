#pragma once

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <atomic>
#include "teller.h"

class Teller;

class Clients {
	friend class Teller;
public:
	Clients(int max_clients);
	void add_client(std::memory_order memory_flag_store);
private:
	int max_clients;
	static inline std::atomic<int> clients_queue{};
};