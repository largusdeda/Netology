#pragma once

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <atomic>
#include "clients_queue.h"

class Clients;

class Teller {
public:
	Teller();
	void take_clients(std::memory_order memory_flag_store, std::memory_order memory_flag_load);
};