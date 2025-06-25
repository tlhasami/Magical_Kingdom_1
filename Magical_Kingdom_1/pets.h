#pragma once
#include "object.h"
#include "HealthBar.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class Pet : public Object
{
protected:
    int MaxHealth;

    int Health;
    int Defence;
    int Attack;

    int TotalFrames;
    int currentFrame;

    float speed;

    float animationTimer;

    std::string petName;

    HealthBar healthBar;

    int level;

    string ability_1;
    string ability_2;
    bool is_unlocked_1;
    bool is_unlocked_2;

public:
    Pet(std::string path, float startX, float startY, float scaleX, float scaleY, int totalFrames, const std::string &name);

    void takeDamage(int amount);
    void increaseAttack(int amount);
    void increaseDefence(int amount);
    void increaseHealth(int amount);
    bool isAlive() const;
    void setSpeed(float s);
    float getSpeed() const;

    void increaseLevel(int up);

    void draw(RenderWindow &window, bool);
    int getAttack() const;
    int getDefence() const;
    int getHealth() const;
    int getLevel() const;
    string getAbility_1() const;
    string getAbility_2() const;
    bool get_is_unlocked_1() const;
    bool get_is_unlocked_2() const;

    void setAttack(int value);
    void setDefence(int value);
    void setHealth(int value);
    void setLevel(int value);

    void set_is_unlocked_1(bool val);
    void set_is_unlocked_2(bool val);

    void addHealth(int val);
    void addDefence(int val);
    void addAttack(int val);

    virtual void useAbility1() = 0; // Every pet must override this
};

class Dragon : public Pet
{
public:
    Dragon(std::string path, float startX, float startY, float scaleX, float scaleY, int totalFrames);
    void useAbility1() override; // Dragon special ability
    void updateAnimation(float deltaTime);
};

class Griffin : public Pet
{
public:
    Griffin(std::string path, float startX, float startY, float scaleX, float scaleY, int totalFrames);
    void useAbility1() override; // Griffin special ability
    void updateAnimation(float deltaTime);
};

class Phoenix : public Pet
{
public:
    Phoenix(std::string path, float startX, float startY, float scaleX, float scaleY, int totalFrames);
    void useAbility1() override; // Phoenix special ability
    void updateAnimation(float deltaTime);
};

class Unicorn : public Pet
{
public:
    Unicorn(std::string path, float startX, float startY, float scaleX, float scaleY, int totalFrames);
    void useAbility1() override; // Unicorn special ability
    void updateAnimation(float deltaTime);
};
