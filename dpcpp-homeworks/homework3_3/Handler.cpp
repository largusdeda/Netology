#include "Handler.h"

void Handler::setNext(std::shared_ptr<Handler> next) {
    next_ = next;
}