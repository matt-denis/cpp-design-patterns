#include <cstdint>


class BankAccount
{
public:
    void deposit(uint32_t amount) noexcept
    {
        balance += amount;
    }

    bool withdraw(uint32_t amount) noexcept
    {
        if (has_sufficient_funds(amount)) {
            balance -= amount;
            return true;
        }

        return false;
    }

private:
    int64_t balance{0};
    int64_t overdraft_limit{-500};

    constexpr bool has_sufficient_funds(uint32_t amount)
    {
        return amount <= balance;
    }

};

class Command
{
public:
    virtual void call() const = 0;
    virtual void undo() const = 0;
protected:
    mutable bool success{};
};

class BankAccountCommand : public Command
{
public:
    enum Action {deposit, withdraw};

    BankAccountCommand(BankAccount& account, const Action action, const uint32_t amount)
        : account{account}, action{action}, amount{amount} {}

    void call() const override
    {
        switch (action)
        {
        case deposit:
            account.deposit(amount);
            break;
        case withdraw:
            success = account.withdraw(amount);
            break;
        default:
            break;
        }
    }

    void undo() const override
    {
        switch (action)
        {
        case deposit:
            account.withdraw(amount);
            break;
        case withdraw:
            if (success) account.deposit(amount);
            break;
        default:
            break;
        }
    }

private:
    uint32_t amount;
    Action action;
    BankAccount& account;
};
