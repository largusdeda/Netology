#include "Timer.h"

//private
double Timer::elapsed() const {
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}

//public
Timer::Timer() : m_beg(clock_t::now()) 
{}
Timer::Timer(std::string name) : m_name(name), m_beg(clock_t::now()) 
{}

void Timer::start(std::string name) {
    m_name = name;
    m_beg = clock_t::now();
}
void Timer::print() const {
    std::stringstream ss;
    ss << elapsed() * 1000 << " ms";
    std::cout << ss.str();
}
