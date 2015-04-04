#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#include <unordered_map>

//List of ANSI Colors
// Black       0;30     Dark Gray     1;30
// Blue        0;34     Light Blue    1;34
// Green       0;32     Light Green   1;32
// Cyan        0;36     Light Cyan    1;36
// Red         0;31     Light Red     1;31
// Purple      0;35     Light Purple  1;35
// Brown       0;33     Yellow        1;33
// Light Gray  0;37     White         1;37
typedef enum ColorKey_t {
    KeyRed,
    KeyGreen,
    KeyBlue,
    KeyCyan,
    KeyYellow,
    KeyWhite,
    KeyPurple,
    KeyBrown,
    KeyBlack,
    KeyEnd
} ColorKey;

typedef std::unordered_map<uint16_t, std::string> ColorMap_t;

static const ColorMap_t ColorMap = {
    {(uint16_t)KeyRed, "\033[31m"},
    {(uint16_t)KeyGreen, "\033[32m"},
    {(uint16_t)KeyBlue, "\033[34m"},
    {(uint16_t)KeyCyan, "\033[36m"},
    {(uint16_t)KeyYellow, "\033[1;33m"},
    {(uint16_t)KeyWhite, "\033[1;37m"},
    {(uint16_t)KeyPurple, "\033[35m"},
    {(uint16_t)KeyBrown, "\033[33m"},
    {(uint16_t)KeyBlack, "\033[30m"},
    {(uint16_t)KeyEnd, "\033[m"}
};

class Color {
private:

public:
    static std::string Red(const std::string s) {
        return ColorMap.at((uint16_t)KeyRed) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string Green(const std::string s) {
        return ColorMap.at((uint16_t)KeyGreen) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string Blue(const std::string s) {
        return ColorMap.at((uint16_t)KeyBlue) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string Cyan(const std::string s) {
        return ColorMap.at((uint16_t)KeyCyan) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string Yellow(const std::string s) {
        return ColorMap.at((uint16_t)KeyYellow) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string White(const std::string s) {
        return ColorMap.at((uint16_t)KeyWhite) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string Purple(const std::string s) {
        return ColorMap.at((uint16_t)KeyPurple) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string Brown(const std::string s) {
        return ColorMap.at((uint16_t)KeyBrown) + s + ColorMap.at((uint16_t)KeyEnd);
    }

    static std::string Black(const std::string s) {
        return ColorMap.at((uint16_t)KeyBlack) + s + ColorMap.at((uint16_t)KeyEnd);
    }
};

#endif//COLOR_H
