#include <memory>

#include "Logger.h"
#include "Observer.h"
#include "W_Observer.h"
#include "E_Observer.h"
#include "FE_Observer.h"

int main() {
    Logger logger;

    auto warningObserver{ std::make_shared<WarningObserver>() };
    auto errorObserver{ std::make_shared<ErrorObserver>("error_log.txt") };
    auto fatalErrorObserver{ std::make_shared<FatalErrorObserver>("fatal_error_log.txt") };

    logger.addObserver(warningObserver);
    logger.addObserver(errorObserver);
    logger.addObserver(fatalErrorObserver);

    logger.warning("Warning message.");
    logger.error("Error message.");
    logger.fatalError("Fatal error message.");

    return EXIT_SUCCESS;
}