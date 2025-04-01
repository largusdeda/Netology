#include "pch.h"
#include "CppUnitTest.h"
#include "../extended_array.h"
#include <exception>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(ExtendedArrayTest) {
	public:
		
		TEST_METHOD(Mean) {
			ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
			Assert::AreEqual(v1.mean(), 1.125);
		}
		TEST_METHOD(Median) {
			ExtArray<double> v2{ 4.5, 0.7, 10.8, -3.5 };
			Assert::AreEqual(v2.median(), 2.6);
		}
		TEST_METHOD(Mode) {
			ExtArray<int> v1{ 4, 2, 7, 2, 5, -5, 0, 5, 5 };
			Assert::AreEqual(v1.mode().first, 5);
		}

		TEST_METHOD(Mean_EmptyArray) {
			ExtArray<int> v1(0);
			Assert::AreEqual(v1.mean(), 0.0);
		}
		TEST_METHOD(Median_EmptyArray) {
			ExtArray<double> v2(0);
			Assert::AreEqual(v2.median(), 0.0);
		}
		TEST_METHOD(Mode_Empty_Array) {
			ExtArray<int> v1(0);
			Assert::AreEqual(v1.mode().first, 0);
		}

		TEST_METHOD(Mean_InRange_Valid) {
			ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
			Assert::AreEqual(v1.mean(0, 3), 4.0);
		}
		TEST_METHOD(Mean_InRange_Invalid) {
			ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
			auto method = [&] { v1.mean(-1, 7); };
			Assert::ExpectException<std::invalid_argument>(method);
		}

		TEST_METHOD(CheckSum_Bool) {
			ExtArray<bool> v3{ true, false, false, true };
			Assert::AreEqual(v3.checkSum(), 2);
		}
		TEST_METHOD(CheckSum_Int) {
			ExtArray<int> v3{ 1, 0, 0, 1 };
			Assert::AreEqual(v3.checkSum(), 2);
		}
		TEST_METHOD(CheckSum_BadType) {
			ExtArray<double> v3{ 1.0, 0.0, 0.0, 1.0 };
			auto method = [&] { v3.checkSum(); };
			Assert::ExpectException<std::bad_typeid>(method);
		}
	};
}
