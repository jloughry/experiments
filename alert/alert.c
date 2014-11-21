#include "alert.h"

int main(int argc, char ** argv)
{
    std::string message;
    std::string programme_name;

    programme_name = argv[0];

    switch (argc) {
        case 2:
            message = argv[1];
            break;
        default:
            std::cerr << "Usage: " << programme_name << " message" << std::endl;
            return 1;
            break;
    }

    ::MessageBox(NULL, message.c_str(), "Alert", MB_OK|MB_ICONINFORMATION);

    return 0;
}

