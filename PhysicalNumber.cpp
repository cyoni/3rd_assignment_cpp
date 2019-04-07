#include <iostream>
#include <sstream>
#include <stdexcept>
#include "PhysicalNumber.h"
//clang++-5.0 -std=c++17 PhysicalNumber.cpp Unit.cpp

using std::cout, std::endl, std::boolalpha, std::istringstream;
using ariel::PhysicalNumber, ariel::Unit;

    ariel::PhysicalNumber::PhysicalNumber(){ }

    ariel::PhysicalNumber::PhysicalNumber(double d, Unit k){
    data=d;
    switch(k){
    ms=k;
    case Unit::CM:
    measure = "cm";
    break;
    case Unit::M:
    measure = "m";
    break;
    case Unit::KM:
    measure = "km";
    break;
    case Unit::S:
    measure = "s";
    break;
    case Unit::MIN:
    measure = "min";
    break;
    case Unit::HOUR:
    measure = "hour";
    break;
    case Unit::G:
    measure = "g";
    break;
    case Unit::KG:
    measure = "kg";
    break;
    case Unit::TON:
    measure = "ton";
    break;
    }

    }

    std::ostream& ariel::operator<<(std::ostream &os, const PhysicalNumber&  dt){
    return os << dt.get_data() << '[' << dt.get_measure() << ']';
    }

    ariel::Unit PhysicalNumber::getmeasure() const{
    return ms;
    }

    void PhysicalNumber::Throw(std::string str) const{
     throw std::invalid_argument(str);
    }

    const PhysicalNumber ariel::operator+(const PhysicalNumber& a, const PhysicalNumber& b){


    return PhysicalNumber(a.get_data(), a.getmeasure());
    }

    const PhysicalNumber ariel::operator-(const PhysicalNumber& a, const PhysicalNumber& b){
    return PhysicalNumber(a.get_data(), a.getmeasure());
    }


    const bool ariel::operator!=(const PhysicalNumber& a, const PhysicalNumber& b){
    return (!(a==b));
    }

    const bool ariel::operator>(const PhysicalNumber& a, const PhysicalNumber& b){
    return false;
    }

    const bool ariel::operator<(const PhysicalNumber& a, const PhysicalNumber& b){
    return false;
    }

    const PhysicalNumber ariel::operator-(const PhysicalNumber& a){
    return PhysicalNumber(-a.get_data(), a.getmeasure());
    }

    const PhysicalNumber ariel::operator+(const PhysicalNumber& a){
    return PhysicalNumber(a.get_data(), a.getmeasure());
    }
    const bool ariel::operator<=(const PhysicalNumber& a, const PhysicalNumber& b){
    return false;
    }

    const bool ariel::operator>=(const PhysicalNumber& a, const PhysicalNumber& b){
    return false;
    }

    const bool ariel::operator==(const PhysicalNumber& a, const PhysicalNumber& b){
    return false;
    }


