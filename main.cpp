#include <iostream>

#include "first_app.h"

int main() {
    lve::FirstApp app;
    lve::FirstApp app2;

    try {
        app.run();
        app2.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
