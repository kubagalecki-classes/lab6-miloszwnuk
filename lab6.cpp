#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Human
{
public:
    Human() : name{"Anonymous"}, age{0}, likes_dogs{true}, likes_cats{true} {}
    Human(std::string name_, unsigned int age_, bool ld, bool lk)
        : name{std::move(name_)}, age{age_}, likes_dogs{ld}, likes_cats{lk}
    {}

    const std::string& getName() const { return name; }
    unsigned int       getAge() const { return age; }
    bool               isMonster() const { return !likes_dogs && !likes_cats; }
    void               birthday() { ++age; }

private:
    std::string  name;
    unsigned int age;
    bool         likes_dogs;
    bool         likes_cats;
};

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

int main()
{
    char  b;
    Human h1("A", 5, true, true);
    Human h2("B", 10, true, false);
    Human h3("C", 15, false, false);
    Human h4("D", 20, false, true);

    list< Human > humans{h1, h2, h3, h4};
    auto          whoLikesAnimals = foo(humans);

    for (char isMonster : whoLikesAnimals) {
        cout << isMonster << endl;
    }
    cout << endl;
    for (auto human : humans) {
        cout << human.getAge() << endl;
    }

    return 0;
}
