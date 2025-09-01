#include "teller.h"

Teller::Teller() = default;

void Teller::take_clients() {
	using std::chrono::operator""ms;

	//Ожидание первого клиента
	while (Clients::clients_queue == 0) {
		std::this_thread::sleep_for(50ms);
	}

	while (Clients::clients_queue > 0) {
		std::cout << "Teller - Число клиентов в очереди: " << --Clients::clients_queue << std::endl;
		std::this_thread::sleep_for(2000ms);
	}
}