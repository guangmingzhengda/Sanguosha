#pragma once
#ifndef _DEFINES_H_
#define  _DEFINES_H_
#include<easyx.h>
#include<string>

struct Vector
{
    double x;
    double y;

    Vector() : x(0.0), y(0.0)
    {
    }

    Vector(double _x, double _y) : x(_x), y(_y)
    {
    }

    bool operator==(const Vector& obj) const
    {
        return x == obj.x && y == obj.y;
    }

    bool operator!=(const Vector& obj) const
    {
        return !(*this == obj);
    }

    Vector operator+(const Vector& obj) const
    {
        return { x + obj.x, y + obj.y };
    }

    Vector operator-(const Vector& obj) const
    {
        return { x + obj.x, y + obj.y };
    }

    Vector operator-() const
    {
        return { -x, -y };
    }

    friend Vector operator*(const Vector& lhs, double rhs)
    {
        return { lhs.x * rhs, lhs.y * rhs };
    }

    friend Vector operator*(double lhs, const Vector& rhs)
    {
        return rhs * lhs;
    }

    friend Vector operator/(const Vector& lhs, double rhs)
    {
        return { lhs.x / rhs, lhs.y / rhs };
    }

    friend Vector operator/(double lhs, const Vector& rhs)
    {
        return rhs / lhs;
    }
};

using Coordinate = Vector;


struct Kapai {
    std::wstring name;
    std::wstring zhongwen;
    int dianshu;
    int huase;//0123ºÚºìÃ··½
    int type;//0123»ù±¾½õÄÒÎäÆ÷·À¾ß
    bool operator < (const Kapai& rhs) const {
        return type > rhs.type;
//        return rhs.name == name ? rhs.name < name : rhs.dianshu < dianshu;
    }
    bool operator == (const Kapai& rhs) const {
        return rhs.name == name && rhs.dianshu == dianshu && rhs.huase == huase;
    }
    Kapai() {
        name = L"";
        zhongwen = L"";
        dianshu = 0;
        huase = 0;
        type = 0;
    }
    Kapai(std::wstring _name,std::wstring _zhongwen,int _dianshu,int _huase,int _type) {
        name = _name;
        zhongwen = _zhongwen;
        dianshu = _dianshu;
        huase = _huase;
        type = _type;
    }
};

struct Rect
{
    union
    {
        Coordinate pos;

        struct
        {
            double x;
            double y;
        };
    };

    double width;
    double height;

    Rect() : x(0.0), y(0.0), width(0.0), height(0.0)
    {
    }

    Rect(double _x, double _y, double _width, double _height)
        : x(_x), y(_y), width(_width), height(_height)
    {
    }

    Coordinate GetCenter() const
    {
        return { x + width * 0.5, y + height * 0.5 };
    }

    Coordinate Intersect(const Rect& rect) const
    {
        Coordinate overlap;
        if (this->x < rect.x)
        {
            overlap.x = this->x + this->width - rect.x;
        }
        else
        {
            overlap.x = rect.x + rect.width - this->x;
        }
        if (this->y < rect.y)
        {
            overlap.y = this->y + this->height - rect.y;
        }
        else
        {
            overlap.y = rect.y + rect.height - this->y;
        }
        return overlap;
    }

    bool Contains(const Coordinate& coord) const
    {
        return ((x < coord.x && coord.x < x + width) && (y < coord.y && coord.y < y + height));
    }

    RECT ToEasyXRect() const
    {
        return {
            static_cast<LONG>(x), static_cast<LONG>(y), static_cast<LONG>(x + width), static_cast<LONG>(y + height)
        };
    }
};


#endif