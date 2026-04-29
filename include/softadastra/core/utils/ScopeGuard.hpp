/**
 *
 *  @file ScopeGuard.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Softadastra.
 *  All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_SCOPE_GUARD_HPP
#define SOFTADASTRA_DRIVE_CORE_SCOPE_GUARD_HPP

#include <type_traits>
#include <utility>

namespace softadastra::core::utils
{

  /**
   * @brief Executes a callable when leaving scope.
   *
   * ScopeGuard is a small RAII utility used to guarantee cleanup.
   *
   * Typical use cases:
   * - rollback on failure
   * - closing resources
   * - temporary state restoration
   *
   * @tparam F Callable type.
   */
  template <typename F>
  class ScopeGuard
  {
  public:
    /**
     * @brief Creates an active scope guard.
     *
     * @param func Callable executed on destruction unless dismissed.
     */
    explicit ScopeGuard(F &&func) noexcept(std::is_nothrow_move_constructible_v<F>)
        : func_(std::forward<F>(func)), active_(true)
    {
    }

    /**
     * @brief Executes the stored callable if still active.
     */
    ~ScopeGuard() noexcept(noexcept(std::declval<F &>()()))
    {
      if (active_)
      {
        func_();
      }
    }

    ScopeGuard(const ScopeGuard &) = delete;
    ScopeGuard &operator=(const ScopeGuard &) = delete;

    /**
     * @brief Moves the guard and disables the source guard.
     */
    ScopeGuard(ScopeGuard &&other) noexcept(std::is_nothrow_move_constructible_v<F>)
        : func_(std::move(other.func_)), active_(other.active_)
    {
      other.dismiss();
    }

    /**
     * @brief Move-assigns another guard.
     *
     * If this guard is active, its current callable is executed before being
     * replaced.
     */
    ScopeGuard &operator=(ScopeGuard &&other) noexcept(
        std::is_nothrow_move_assignable_v<F> &&
        noexcept(std::declval<F &>()()))
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

    /**
     * @brief Disables execution on destruction.
     */
    void dismiss() noexcept
    {
      active_ = false;
    }

    /**
     * @brief Returns true if the guard is active.
     */
    [[nodiscard]] bool active() const noexcept
    {
      return active_;
    }

  private:
    F func_;
    bool active_{false};
  };

  /**
   * @brief Creates a ScopeGuard with type deduction.
   *
   * @param func Callable executed on scope exit.
   */
  template <typename F>
  [[nodiscard]] auto make_scope_guard(F &&func)
  {
    return ScopeGuard<std::decay_t<F>>(std::forward<F>(func));
  }

} // namespace softadastra::core::utils

#endif // SOFTADASTRA_DRIVE_CORE_SCOPE_GUARD_HPP
