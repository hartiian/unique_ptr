template <typename T>
void Deleter<T>::operator()(T* ptr) {
    if(ptr) {
        delete ptr;
    }
}

template<typename T, typename Deleter>
constexpr unique_ptr<T, Deleter>::unique_ptr() noexcept : m_ptr(nullptr) {}

template<typename T, typename Deleter>
constexpr unique_ptr<T, Deleter>::unique_ptr(std::nullptr_t) noexcept : m_ptr(nullptr) {}

template<typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(T* ptr) noexcept : m_ptr(ptr) {}

template<typename T, typename Deleter>
unique_ptr<T, Deleter>::~unique_ptr() {
    if(m_ptr) {
        deleter(m_ptr);
    }
}

template<typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(unique_ptr<T>&& other) noexcept : m_ptr(other.release()) {}

template<typename T, typename Deleter>
unique_ptr<T, Deleter>& unique_ptr<T, Deleter>::operator=(unique_ptr<T>&& other) noexcept {
    if(this != &other) {
        reset(other.release());
    }
    return *this;
}

template<typename T, typename Deleter>
T& unique_ptr<T, Deleter>::operator*() const noexcept {
    return *m_ptr;
}

template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::operator->() const noexcept {
    return m_ptr;
}

template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::get() const noexcept {
    return m_ptr;
}

template<typename T, typename Deleter>
void unique_ptr<T, Deleter>::reset(T* ptr) noexcept {
    if(m_ptr != ptr) {
        deleter(m_ptr);
        m_ptr = ptr;
    }
}

template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::release() noexcept {
    T* tmp = m_ptr;
    m_ptr = nullptr;
    return tmp;
}

template<typename T, typename Deleter>
unique_ptr<T, Deleter>::operator bool() const noexcept {
    return m_ptr != nullptr;
}

template<typename T, typename Deleter>
constexpr void unique_ptr<T, Deleter>::swap(unique_ptr& other) noexcept {
    using std::swap;
    swap(m_ptr, other.m_ptr);
}
