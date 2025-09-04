#include "teller.h"

Teller::Teller() = default;

void Teller::take_clients(std::memory_order memory_flag_store, std::memory_order memory_flag_load) {
	using std::chrono::operator""ms;

	//Ожидание первого клиента
	while (!Clients::clients_queue.load(memory_flag_load))
		;

	while (Clients::clients_queue.load(memory_flag_load) > 0) {
		Clients::clients_queue.fetch_sub(1, memory_flag_load);
		std::cout << (std::stringstream() << "Teller - Число клиентов в очереди: " << Clients::clients_queue << "\n").str();
		std::this_thread::sleep_for(2000ms);
	}
}