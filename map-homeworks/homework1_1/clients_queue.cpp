#include "clients_queue.h"

Clients::Clients(int max_clients) {
	this->max_clients = max_clients;
}

void Clients::add_client() {
	using std::chrono::operator""ms;

	do {
		std::cout << "Clients - Число клиентов в очереди: " << ++clients_queue << std::endl;
		std::this_thread::sleep_for(1000ms);
	} while (clients_queue != max_clients);
}