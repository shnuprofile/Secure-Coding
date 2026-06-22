// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept> // For standard exceptions
// Custom exception class
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom Exception: Something went wrong!";
    }
};

bool do_even_more_custom_application_logic()
{
    // Throw a standard exception
    throw std::runtime_error("Standard Exception: An error occurred in even more custom application logic.");

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic()) {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    // Throw a custom exception
    throw CustomException();
    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    if (den == 0) {
        throw std::invalid_argument("Invalid argument: Division by zero.");
    }
    return (num / den);
}

void do_division() noexcept
{
    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Caught an invalid argument exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    try {
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomException& e) {
        std::cerr << "Caught a custom exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught a standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Caught an unknown exception." << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu