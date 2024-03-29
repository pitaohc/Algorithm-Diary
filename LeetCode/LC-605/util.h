﻿#pragma once
#include <iostream>
#include<vector>

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vect)
{
    out << "[";
    for (const auto& elem : vect)
    {
        out << elem << ", ";
    }
    out << "\b\b]";
    return out;
}


template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<T>>& vect)
{
    out << "[";

    for (const auto& elem : vect)
    {
        out << elem << ",\n";
    }
    out << "]";
    return out;
}