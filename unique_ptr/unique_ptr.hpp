#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <iostream>

template<typename T>
struct Deleter {
    void operator()(T* ptr);
};

template<typename T, typename Deleter = Deleter<T>>
class unique_ptr {
private:
    T* m_ptr;
    Deleter deleter;

public:
    constexpr unique_ptr() noexcept;
    constexpr unique_ptr(std::nullptr_t) noexcept;
    explicit unique_ptr(T* ptr) noexcept;
    ~unique_ptr();

    unique_ptr(unique_ptr<T>&& other) noexcept;
    unique_ptr& operator=(unique_ptr<T>&& other) noexcept;

    unique_ptr(const unique_ptr<T>&) = delete;
    unique_ptr& operator= (const unique_ptr<T>&) = delete;

    T& operator*() const noexcept;
    T* operator->() const noexcept;
    T* get() const noexcept;

    void reset(T* ptr = nullptr) noexcept;
    T* release() noexcept;
    explicit operator bool() const noexcept;
    constexpr void swap (unique_ptr& other) noexcept;
};

#include "unique_ptr.cpp"

#endif
