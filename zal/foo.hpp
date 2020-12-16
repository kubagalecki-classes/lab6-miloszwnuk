#pragma once

#include "Human.hpp"
using namespace std;

#include <iostream>
#include <list>
#include <string>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > likesAnimals;
    std::for_each(people.rbegin(), people.rend(), [&likesAnimals](Human& human) {
        human.birthday();
        if (human.isMonster() == true) {
            likesAnimals.push_back('n');
        }
        else {
            likesAnimals.push_back('y');
        }
    });

    return likesAnimals;
}


