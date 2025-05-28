#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

#include "List.h"

TEST_CASE("Testing List base functions", "[List]") {
	List test_list;
	CHECK(test_list.Empty() == true);
	test_list.PushFront(666);
	test_list.PushFront(42);
	test_list.PushBack(-1);
	test_list.PushBack(-28282);
	CHECK(test_list.Size() == 4);
	test_list.Clear();
	CHECK(test_list.Size() == 0);
	CHECK(test_list.Empty() == true);
}

int main() {
	return Catch::Session().run();
}