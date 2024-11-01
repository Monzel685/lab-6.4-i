#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.4 i/lab 6.4 i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
    TEST_CLASS(UnitTest64it)
    {
    public:

        TEST_METHOD(TestSumPositivesBeforeMax_NoPositiveBeforeMax)
        {
            const int SIZE = 5;
            double arr[SIZE] = { -10.5, -5.0, -15.2, 0.0, 10.0 };
            Assert::AreEqual(30.2, sumAfterFirstNegative(arr, SIZE), 0.00001);
        }

        TEST_METHOD(TestSumPositivesBeforeMax_PositiveBeforeMax)
        {
            const int SIZE = 5;
            double arr[SIZE] = { 1.2, 3.4, -5.6, 8.7, 7.8 };
            Assert::AreEqual(16.5, sumAfterFirstNegative(arr, SIZE), 0.00001);
        }
    };
}
