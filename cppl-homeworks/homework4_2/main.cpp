#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/catch_session.hpp>

#include "List.h"

TEST_CASE("Testing List base functions", "[List]") {
	List test_list;
	CHECK_THROWS_WITH(test_list.PopFront(), "list is empty");
	CHECK_THROWS_WITH(test_list.PopBack(), "list is empty");
	CHECK(test_list.Empty() == true);
	test_list.PushFront(666);
	test_list.PushFront(42);
	test_list.PushBack(-1);
	CHECK(test_list.PopFront() == 42);
	test_list.PushBack(0);
	CHECK(test_list.Size() == 3);
	CHECK(test_list.PopBack() == 0);
	CHECK(test_list.PopFront() == 666);
	test_list.PushFront(1);
	CHECK(test_list.PopBack() == -1);
	CHECK(test_list.PopBack() == 1);
	CHECK(test_list.Size() == 0);
	CHECK_THROWS_WITH(test_list.PopFront(), "list is empty");
	CHECK_THROWS_WITH(test_list.PopBack(), "list is empty");
	test_list.PushFront(1);
	test_list.PushFront(2);
	test_list.PushFront(3);
	CHECK(test_list.PopFront() == 3);
	CHECK(test_list.PopFront() == 2);
	CHECK(test_list.PopFront() == 1);
	test_list.PushBack(1);
	test_list.PushBack(2);
	test_list.PushBack(3);
	CHECK(test_list.PopBack() == 3);
	CHECK(test_list.PopBack() == 2);
	CHECK(test_list.PopBack() == 1);
	CHECK_THROWS_WITH(test_list.PopFront(), "list is empty");
	CHECK_THROWS_WITH(test_list.PopBack(), "list is empty");
	test_list.Clear();
	CHECK(test_list.Size() == 0);
	CHECK(test_list.Empty() == true);
}

int main() {
	return Catch::Session().run();
}