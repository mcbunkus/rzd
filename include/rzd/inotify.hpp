#pragma once

#include <filesystem>

namespace rzd {

class Inotify {

  int m_inotifyId;

public:
  Inotify();

  void add(const std::filesystem::path &path, uint32_t event);
};

} // namespace rzd
