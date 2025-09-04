#include <iostream>
#include <thread>
#include <atomic>
#include "clients_queue.h"
#include "teller.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

	int max_queue_count{};
	std::cout << "Введите максимальную длину очереди: ";
	std::cin >> max_queue_count;

	std::cout << "\nstd::memory_order_seq_cst" << std::endl; {
		Clients clients(max_queue_count);
		Teller teller;
		std::memory_order memory_flag_store{ std::memory_order_seq_cst };
		std::memory_order memory_flag_load{ std::memory_order_seq_cst };

		std::thread t1(&Clients::add_client, clients, memory_flag_store);
		std::thread t2(&Teller::take_clients, teller, memory_flag_store, memory_flag_load);
		if (t1.joinable()) {
			t1.join();
		}

		if (t2.joinable()) {
			t2.join();
		}
	}

	std::cout << "\nstd::memory_order_relaxed" << std::endl; {
		Clients clients(max_queue_count);
		Teller teller;
		std::memory_order memory_flag_store{ std::memory_order_relaxed };
		std::memory_order memory_flag_load{ std::memory_order_relaxed };

		std::thread t1(&Clients::add_client, clients, memory_flag_store);
		std::thread t2(&Teller::take_clients, teller, memory_flag_store, memory_flag_load);
		if (t1.joinable()) {
			t1.join();
		}

		if (t2.joinable()) {
			t2.join();
		}
	}

	std::cout << "\nstd::memory_order_release и std::memory_order_acquire" << std::endl; {
		Clients clients(max_queue_count);
		Teller teller;
		std::memory_order memory_flag_store{ std::memory_order_release };
		std::memory_order memory_flag_load{ std::memory_order_acquire };

		std::thread t1(&Clients::add_client, clients, memory_flag_store);
		std::thread t2(&Teller::take_clients, teller, memory_flag_store, memory_flag_load);
		if (t1.joinable()) {
			t1.join();
		}

		if (t2.joinable()) {
			t2.join();
		}
	}

	std::cout << "\nstd::memory_order_acq_rel и std::memory_order_acquire" << std::endl; {
		Clients clients(max_queue_count);
		Teller teller;
		std::memory_order memory_flag_store{ std::memory_order_acq_rel };
		std::memory_order memory_flag_load{ std::memory_order_acquire };

		std::thread t1(&Clients::add_client, clients, memory_flag_store);
		std::thread t2(&Teller::take_clients, teller, memory_flag_store, memory_flag_load);
		if (t1.joinable()) {
			t1.join();
		}

		if (t2.joinable()) {
			t2.join();
		}
	}
	return EXIT_SUCCESS;
}


