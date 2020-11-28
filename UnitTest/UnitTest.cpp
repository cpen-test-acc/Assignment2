#include "pch.h"
#include "CppUnitTest.h"
#include "../Interface.h"
#include "../File_Fetcher.h" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
class Interface;
class File_Fetcher;
namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Interface intf;
			File_Fetcher fetcher;

			intf.Add_File_Fetcher(&fetcher);
			Assert::AreEqual((int)intf.verify_login("wrong","login"), 0);
		}
	};
}
