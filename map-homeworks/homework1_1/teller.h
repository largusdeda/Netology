#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include "clients_queue.h"

class Clients;

class Teller {
public:
	Teller();
	void take_clients();
};