
#include <gtest/gtest.h>

#if 0
class EmptyTestEventListener : public TestEventListener {
 public:
  void OnTestProgramStart(const UnitTest& /*unit_test*/) override {}
  void OnTestIterationStart(const UnitTest& /*unit_test*/,
                            int /*iteration*/) override {}
  void OnEnvironmentsSetUpStart(const UnitTest& /*unit_test*/) override {}
  void OnEnvironmentsSetUpEnd(const UnitTest& /*unit_test*/) override {}
  void OnTestSuiteStart(const TestSuite& /*test_suite*/) override {}
  void OnTestStart(const TestInfo& /*test_info*/) override {}
  void OnTestPartResult(const TestPartResult& /*test_part_result*/) override {}
  void OnTestEnd(const TestInfo& /*test_info*/) override {}
  void OnTestSuiteEnd(const TestSuite& /*test_suite*/) override {}
  void OnEnvironmentsTearDownStart(const UnitTest& /*unit_test*/) override {}
  void OnEnvironmentsTearDownEnd(const UnitTest& /*unit_test*/) override {}
  void OnTestIterationEnd(const UnitTest& /*unit_test*/,
                          int /*iteration*/) override {}
  void OnTestProgramEnd(const UnitTest& /*unit_test*/) override {}
};
#endif

using testing::UnitTest;
using testing::TestSuite;
using testing::TestInfo;
using testing::TestPartResult;

class MyTestListener : public testing::EmptyTestEventListener {
public:
	void OnTestProgramStart(const UnitTest& unit_test) override {
		printf(">>>>>>>>>>> OnTestProgramStart >>>>>>>>>>>\n");
	}

	void OnTestProgramEnd(const UnitTest& unit_test) override {
		printf(">>>>>>>>>>> OnTestProgramEnd >>>>>>>>>>>\n");
	}

	void OnTestSuiteStart(const TestSuite& test_suite) override {
		printf("TestSuite Start > ---- %s ---- \n", test_suite.name());
	}

	void OnTestSuiteEnd(const TestSuite& test_suite) override {
		printf("TestSuite End---- %s ---- \n", test_suite.name());
	}

	void OnTestStart(const TestInfo& test_info) override {
		printf("TestCase Start:  %s.%s\n", test_info.test_suite_name(), test_info.name());
	}

	void OnTestPartResult(const TestPartResult& test_part_result) override { 
		bool failed = test_part_result.failed();
		printf("TestCase Result: %s\n", failed ? "FAIL" : "SUCCEED");
	}

	void OnTestEnd(const TestInfo& test_info) override {
		printf("TestCase End: %s.%s\n", test_info.test_suite_name(), test_info.name());
	}
};

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	// 리스너 등록하는 방법.
	testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();
	listeners.Append(new MyTestListener);

	return RUN_ALL_TESTS();
}









