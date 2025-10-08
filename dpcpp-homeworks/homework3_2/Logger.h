#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Observer.h"


class Logger {

public:
	void addObserver(std::weak_ptr<Observer> observer);
	void warning(const std::string& message) const;
	void error(const std::string& message) const;
	void fatalError(const std::string& message) const;

private:
	std::vector<std::weak_ptr<Observer>> observers_;

};