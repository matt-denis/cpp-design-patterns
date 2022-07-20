#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <cstdint>
#include <iostream>
#include <stdexcept>

struct Creature
{
    std::string name;
    uint32_t attack;
    uint32_t defense;

    Creature(std::string name, uint32_t attack = 0, uint32_t defense = 0)
        : name{name}, attack{attack}, defense{defense} {}

    friend std::ostream& operator<<(std::ostream& stream, const Creature& creature)
    {
        stream << creature.name << " " << creature.attack << " " << creature.defense << std::endl;
    }

};


class CreatureModifier
{
public:
    explicit CreatureModifier(Creature& creature) : next_modifier{nullptr}, creature{creature} {}

    void add(CreatureModifier& creature_modifier)
    {
        if (next_modifier) next_modifier->add(creature_modifier);
        else next_modifier = &creature_modifier;
    }

    virtual void handle()
    {
        if (next_modifier) next_modifier->handle();
    }

protected:
    Creature& creature;

private:
    CreatureModifier* next_modifier;

};


class DoubleAttackModifier : public CreatureModifier
{

public:

    explicit DoubleAttackModifier(Creature& creature) : CreatureModifier{creature} {}

    void handle() override
    {
        creature.attack *= 2;
        CreatureModifier::handle();
    }

};

class NoBonusesModifier : public CreatureModifier
{
public:
    explicit NoBonusesModifier(Creature& creature) : CreatureModifier{creature} {}

    void handle() override {}
};

#endif
