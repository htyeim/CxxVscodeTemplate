#include "hello.hpp"

#include <glog/logging.h>

#include <gtest/gtest.h>

#include <filesystem>
#include <string>

namespace {
void setup_glog() {
  const std::string log_dir = "./logs/";
  if (!std::filesystem::is_directory(log_dir) ||
      !std::filesystem::exists(log_dir)) {
    std::filesystem::create_directory(log_dir);
    std::cout << "create_log_directory: " << log_dir << std::endl;
  }
  google::InitGoogleLogging("test_log");
  google::SetLogDestination(google::GLOG_INFO, log_dir.c_str());
}
int test_glog() {
  // Initialize Google’s logging library.
  // google::InitGoogleLogging(argv[0]);
  char str[20] = "hello log!";
  LOG(INFO) << str;
  LOG(WARNING) << "warning test";
  LOG(ERROR) << "error test";
  for (int i = 0; i < 100; i++) {
    LOG_FIRST_N(INFO, 20) << "Got the " << google::COUNTER << "th LOG";
    LOG_IF_EVERY_N(INFO, (i > 50), 10)
        << "Got the " << google::COUNTER << "th i LOG";
    LOG_EVERY_T(INFO, 0.01) << "LOG_EVERY_T(INFO, 0.01) ";
  }
  DLOG(INFO) << "DLOG(INFO)";
  return 0;
}
TEST(GLOG, Test) {
  EXPECT_EQ(test_glog(), 0); // PASS
  EXPECT_EQ(test_glog(), 1) << "FAILED: EXPECT: 0, but given 1";
}
} // namespace

int main(int argc, char *argv[]) {
  say_hello();
  setup_glog();
  say_hello();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  google::ShutdownGoogleLogging();
  return 0;
}