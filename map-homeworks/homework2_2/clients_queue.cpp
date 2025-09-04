#include "clients_queue.h"

Clients::Clients(int max_clients) {
	this->max_clients = max_clients;
}

void Clients::add_client(std::memory_order memory_flag_store) {
	using std::chrono::operator""ms;

	while (clients_queue != max_clients) {
		clients_queue.fetch_add(1, memory_flag_store);
		std::cout << (std::stringstream() << "Clients - Число клиентов в очереди: " << clients_queue << "\n").str();
		std::this_thread::sleep_for(1000ms);
	} 
}