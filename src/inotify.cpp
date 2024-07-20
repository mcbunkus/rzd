#include "rzd/inotify.hpp"

#include <cerrno>
#include <cstring>
#include <stdexcept>
#include <sys/inotify.h>

namespace rzd {

Inotify::Inotify() : m_inotifyId{inotify_init1(IN_NONBLOCK)} {
  if (m_inotifyId == -1) {
    throw std::runtime_error(std::string{"failed to initialize inotify: "} +
                             std::strerror(errno));
  }
}

void Inotify::add(const std::filesystem::path &path, uint32_t event) {
  int wd = inotify_add_watch(m_inotifyId, path.c_str(), event);
}
} // namespace rzd
