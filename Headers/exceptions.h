#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <exception>


class OpenFail : public std::exception{
public:
    const char * what() noexcept{
            return "File couldn't not be opened\n";
        }

};

class ReadFail : public std::exception {
    public:
    const char * what() noexcept{
            return "File couldn't be read\n";
        }
};


class WidgetMismatch : public std::exception {
    public:
    const char * what() noexcept{
            return "Widget Mismatch\n";
        }
};

#endif
