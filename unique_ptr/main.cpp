#include "unique_ptr.hpp"
#include <iostream>

int main() {
    unique_ptr<int> ptr1;
    std::cout << "ptr1: " << (ptr1 ? "not nullptr" : "nullptr") << std::endl;

    unique_ptr<int> ptr2(nullptr);
    std::cout << "ptr2: " << (ptr2 ? "not nullptr" : "nullptr") << std::endl;

    unique_ptr<int> ptr3(new int(42));
    std::cout << "ptr3: " << *ptr3 << std::endl;

    unique_ptr<int> ptr4(std::move(ptr3));
    std::cout << "ptr4: " << *ptr4 << std::endl;

    unique_ptr<int> ptr5(new int(100));
    ptr5 = std::move(ptr4);
    std::cout << "ptr5: " << *ptr5 << std::endl;

    ptr5.reset(new int(200));
    std::cout << "ptr5 (after reset): " << *ptr5 << std::endl;

    int* raw_ptr = ptr5.release();
    std::cout << "ptr5 (after release): " << (ptr5 ? "not nullptr" : "nullptr") << std::endl;
    delete raw_ptr;

    unique_ptr<int> ptr6(new int(10));
    unique_ptr<int> ptr7(new int(20));
    std::cout << "Before swap: ptr6=" << *ptr6 << ", ptr7=" << *ptr7 << std::endl;
    ptr6.swap(ptr7);
    std::cout << "After swap: ptr6=" << *ptr6 << ", ptr7=" << *ptr7 << std::endl;
}
