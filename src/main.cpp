#include <filesystem>
#include <iostream>
#include <zip.h>

namespace fs = std::filesystem;

int main() {

  fs::path test_dir = "test_dir";
  fs::path zip_filename = "test.zip";

  if (!fs::exists(test_dir) || !fs::is_directory(test_dir)) {
    std::cerr << test_dir << " is not a valid directory!" << std::endl;
    return 1;
  }

  int error;
  zip_t *zipfile = zip_open(zip_filename.c_str(), ZIP_CREATE, &error);

  if (zipfile == nullptr) {
    zip_error_t err;
    zip_error_init_with_code(&err, error);
    std::cerr << "cannot open " << zip_filename << ": "
              << zip_error_strerror(&err) << std::endl;
    return 1;
  }

  zip_int64_t zip_test_dir = zip_dir_add(zipfile, test_dir.c_str(), 0);

  if (zip_test_dir == -1) {
    zip_error_t err;
    zip_error_init_with_code(&err, error);
    std::cerr << "cannot write " << test_dir << " to " << zip_filename << ": "
              << zip_error_strerror(&err) << std::endl;
    return 1;
  }

  zip_close(zipfile);
}
