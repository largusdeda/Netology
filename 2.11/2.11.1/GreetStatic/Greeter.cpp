#include "Greeter.h"

namespace Greeter {
	std::string Greeter::greet(std::string name) {
		return "Здравствуйте, " + name + "!\n";
	}
}