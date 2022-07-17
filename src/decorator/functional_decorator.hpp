#ifndef FUNCTIONAL_DECORATOR_H
#define FUNCTIONAL_DECORATOR_H

#include <functional>
#include <string>
#include <iostream>

class Logger
{
public:
    std::function<void()> callback;
    std::string name;

    Logger(const std::function<void()>& callback, const std::string& name)
        : callback{callback}, name{name} {}

    void operator()() const
    {
        std::cout << "Entering " << name << std::endl;
        callback();
        std::cout << "Exiting " << name << std::endl;
    }

};

template <typename> class LoggerTemplate;

template <typename R, typename... Args>
class LoggerTemplate<R(Args...)>
{
public:
    LoggerTemplate(std::function<R(Args...)> callback, const std::string& name)
        : callback{callback}, name{name} {}

    R operator()(Args... args)
    {
        std::cout << "Entering " << name << std::endl;
        R result{callback(args...)};
        std::cout << "Exiting " << name << std::endl;

        return result;
    }

private:
    std::function<R(Args...)> callback;
    const std::string name;
};

template <typename R, typename... Args>
auto make_logger(R (*callback)(Args...), const std::string& name)
{
    return ::LoggerTemplate<R(Args...)>(
        std::function<R(Args...)>(callback), name
    );
}



#endif
