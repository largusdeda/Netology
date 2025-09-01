#include <iostream>
#include <thread>
#include "clients_queue.h"
#include "teller.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

	int max_queue_count{};
	std::cout << "Введите максимальную длину очереди: ";
	std::cin >> max_queue_count;

	Clients clients(max_queue_count);
	Teller teller;
	std::thread t1(&Clients::add_client, clients);
	std::thread t2(&Teller::take_clients, teller);
	if (t1.joinable()) {
		t1.join();
	}

	if (t2.joinable()) {
		t2.join();
	}

	return EXIT_SUCCESS;
}


