#pragma once

#include <chrono>
#include <thread>
#include "teller.h"

class Teller;

class Clients {
	friend class Teller;
public:
	Clients(int max_clients);
	void add_client();
private:
	int max_clients;
	static inline int clients_queue{};
};