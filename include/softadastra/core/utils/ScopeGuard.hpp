/*
 * ScopeGuard.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_SCOPE_GUARD_HPP
#define SOFTADASTRA_DRIVE_CORE_SCOPE_GUARD_HPP

#include <utility>

namespace softadastra::core::utils
{
  template <typename F>
  class ScopeGuard
  {
  public:
    explicit ScopeGuard(F &&func)
        : func_(std::move(func)), active_(true)
    {
    }

    ~ScopeGuard()
    {
      if (active_)
      {
        func_();
      }
    }

    // Non-copyable
    ScopeGuard(const ScopeGuard &) = delete;
    ScopeGuard &operator=(const ScopeGuard &) = delete;

    // Movable
    ScopeGuard(ScopeGuard &&other) noexcept
        : func_(std::move(other.func_)), active_(other.active_)
    {
      other.dismiss();
    }

    ScopeGuard &operator=(ScopeGuard &&other) noexcept
    {
      if (this != &other)
      {
        if (active_)
        {
          func_();
        }

        func_ = std::move(other.func_);
        active_ = other.active_;
        other.dismiss();
      }
      return *this;
    }

    void dismiss() noexcept
    {
      active_ = false;
    }

  private:
    F func_;
    bool active_;
  };

} // namespace softadastra::core::utils

#endif
