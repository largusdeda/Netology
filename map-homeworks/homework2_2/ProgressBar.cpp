#include "ProgressBar.h"


void progressBar(int threadsNumber) {
    thread_local std::random_device rd;
    thread_local std::mt19937 gen(rd());
    thread_local std::uniform_int_distribution<> dis(0, 10);

    int progressBar{ 23 };
    int total{ 37 };
    int PositionForTime{ 43 };

    static std::once_flag flag;
    static std::mutex console_mutex;

    std::call_once(flag, tableHeader);

    Timer t;
    ConsoleParameter cp;

    {
        std::scoped_lock<std::mutex> lock(console_mutex);
        cp.SetPosition(0, threadsNumber + 1);
        std::stringstream ss;
        ss << std::setw(2) << threadsNumber << "\t" << std::this_thread::get_id() << "\t";
        std::cout << ss.str();
    }

    while (progressBar < total) {
        bool exceptionOccurred{ false };
        try {
            if (dis(gen) == 0) {
                throw std::exception();
            }
        }
        catch (...) {
            exceptionOccurred = true;
        }

        {
            std::scoped_lock<std::mutex> lock(console_mutex);
            if (exceptionOccurred)
                cp.SetColor(12, 0);

            cp.SetPosition(progressBar, threadsNumber + 1);
            std::cout << char(219);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            cp.SetColor(7, 0);
            progressBar++;
        }

    }

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    {
        std::scoped_lock<std::mutex> lock(console_mutex);
        cp.SetPosition(PositionForTime, threadsNumber + 1);
        t.print();
    }
}