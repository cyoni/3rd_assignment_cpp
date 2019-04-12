#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string.h>
//clang++-5.0 -std=c++17 PhysicalNumber.cpp Unit.cpp

#include "PhysicalNumber.h"



using std::cout, std::endl, std::boolalpha, std::istringstream;
using ariel::PhysicalNumber, ariel::Unit;

    ariel::PhysicalNumber::PhysicalNumber(){

      }

    ariel::PhysicalNumber::PhysicalNumber(double d, Unit k){
        cout.setf(std::ios::fixed, std::ios::floatfield); // get fixed number of digits after the decimal num
        cout.precision(5);

    data=d;
    switch(k){
    case Unit::CM:
    ms = k;
    measure = "cm";
    break;
    case Unit::M:
    measure = "m";
    ms = k;
    break;
    case Unit::KM:
    measure = "km";
    ms = k;
    break;
    case Unit::SEC:
    measure = "sec";
    ms = k;
    break;
    case Unit::MIN:
    measure = "min";
    ms = k;
    break;
    case Unit::HOUR:
    measure = "hour";
    ms = k;
    break;
    case Unit::G:
    measure = "g";
    ms = k;
    break;
    case Unit::KG:
    measure = "kg";
    ms = k;
    break;
    case Unit::TON:
    measure = "ton";
    ms = k;
    break;
    }

    }

    Unit ariel::PhysicalNumber::getmeasure(std::string m){
    Unit u ;

    if (m == "CM" || m == "cm") u = Unit::CM;
    else if (m == "KM" || m == "km") u = Unit::KM;
    else if (m == "M" || m == "m") u = Unit::M;
    else if (m == "HOUR" || m == "hour") u = Unit::HOUR;
    else if (m == "MIN" || m == "min") u = Unit::MIN;
    else if (m == "SEC" || m == "sec") u = Unit::SEC;
    else if (m == "TON" || m == "ton") u = Unit::TON;
    else if (m == "G" || m == "g") u = Unit::G;
    else if (m == "KG" || m == "kg") u = Unit::KG;
    else Throw("error 552");

    return u;
    }
    std::ostream& ariel::operator<<(std::ostream &os, const PhysicalNumber&  dt){
    return os << dt.get_data() << '[' << dt.get_measure() << ']';
    }

    ariel::Unit PhysicalNumber::getmeasure() const{
    return ms;
    }


    double PhysicalNumber::convert(ariel::Unit ms_a, ariel::Unit ms_b,std::string str1,  std::string str2, double data) const{
    double res=0;

         if (ms_a==ariel::Unit::M && ms_b == ariel::Unit::CM)   res = data/100; // CM->M
    else if (ms_a==ariel::Unit::KM && ms_b == ariel::Unit::CM)   res = data/1000; // CM->KM

    else if (ms_a==ariel::Unit::CM && ms_b == ariel::Unit::M)   res = data*100; // M->CM
    else if (ms_a==ariel::Unit::KM && ms_b == ariel::Unit::M)   res = data/1000; // M->KM

    else if (ms_a==ariel::Unit::CM && ms_b == ariel::Unit::KM)   res = data*100000; // KM->CM
    else if (ms_a==ariel::Unit::M && ms_b == ariel::Unit::KM)   res = data*1000; // KM->M

//---
    else if (ms_a==ariel::Unit::MIN && ms_b == ariel::Unit::SEC)   res = data/60;
    else if (ms_a==ariel::Unit::HOUR && ms_b == ariel::Unit::SEC)   res = data/3600;

    else if (ms_a==ariel::Unit::SEC && ms_b == ariel::Unit::MIN)  {res = data*60;}
    else if (ms_a==ariel::Unit::HOUR && ms_b == ariel::Unit::MIN)   res = data/60;

    else if (ms_a==ariel::Unit::SEC && ms_b == ariel::Unit::HOUR)   res = data*3600;
    else if (ms_a==ariel::Unit::MIN && ms_b == ariel::Unit::HOUR)   res = data*60;

// --
    else if (ms_a==ariel::Unit::TON && ms_b == ariel::Unit::G)   res = data/1000000;
    else if (ms_a==ariel::Unit::KG && ms_b == ariel::Unit::G)   res = data/1000;

    else if (ms_a==ariel::Unit::G && ms_b == ariel::Unit::KG)   res = data*1000;
    else if (ms_a==ariel::Unit::TON && ms_b == ariel::Unit::KG)   res = data/1000;

    else if (ms_a==ariel::Unit::KG && ms_b == ariel::Unit::TON)   res = data*1000;
    else if (ms_a==ariel::Unit::G && ms_b == ariel::Unit::TON)   res = data*1000000;
    else{

    PhysicalNumber::Throw("Units do not match - [" +str1+ "] cannot be converted to ["+ str2 +"]");
        }

    return res;
    }

    void PhysicalNumber::Throw(std::string str) const{
     throw std::invalid_argument(str);
    }

    const PhysicalNumber ariel::operator+(const PhysicalNumber& a, const PhysicalNumber& b){
    double res=0;
    if (a.getmeasure()==b.getmeasure()) res = b.get_data();
    else
    res = a.convert(a.getmeasure(),b.getmeasure(),a.get_measure(), b.get_measure(), b.get_data());

    return PhysicalNumber(res+a.get_data(), a.getmeasure());
    }

    const PhysicalNumber ariel::operator-(const PhysicalNumber& a, const PhysicalNumber& b){
    double res=0;
    if (a.getmeasure()==b.getmeasure()) res = b.get_data();
    else
    res = a.convert(a.getmeasure(),b.getmeasure(),a.get_measure(), b.get_measure(), b.get_data());
    return PhysicalNumber(-res+a.get_data(), a.getmeasure());
    }


    const bool ariel::operator!=(const PhysicalNumber& a, const PhysicalNumber& b){
    return (!(a==b));
    }

    const bool ariel::operator>(const PhysicalNumber& a, const PhysicalNumber& b){
    double res=0;
    if (a.getmeasure()==b.getmeasure()) res = b.get_data();
    else
    res = a.convert(a.getmeasure(),b.getmeasure(),a.get_measure(), b.get_measure(), b.get_data());
    return (a.get_data() > res);
    }

    const bool ariel::operator<(const PhysicalNumber& a, const PhysicalNumber& b){
    double res=0;
    if (a.getmeasure()==b.getmeasure()) res = b.get_data();
    else
    res = a.convert(a.getmeasure(),b.getmeasure(),a.get_measure(), b.get_measure(), b.get_data());
    return (a.get_data() < res);
    }

    const PhysicalNumber ariel::operator-(const PhysicalNumber& a){
    return PhysicalNumber(-a.get_data(), a.getmeasure());
    }

    const PhysicalNumber ariel::operator+(const PhysicalNumber& a){
    return PhysicalNumber(a.get_data(), a.getmeasure());
    }
    const bool ariel::operator<=(const PhysicalNumber& a, const PhysicalNumber& b){
    double res=0;
    if (a.getmeasure()==b.getmeasure()) res = b.get_data();
    else
    res = a.convert(a.getmeasure(),b.getmeasure(),a.get_measure(), b.get_measure(), b.get_data());
    return (a.get_data() <= res);
    }

    const bool ariel::operator>=(const PhysicalNumber& a, const PhysicalNumber& b){
    double res=0;
    if (a.getmeasure()==b.getmeasure()) res = b.get_data();
    else
    res = a.convert(a.getmeasure(),b.getmeasure(),a.get_measure(), b.get_measure(), b.get_data());
    return (a.get_data() >= res);
    }

    const bool ariel::operator==(const PhysicalNumber& a, const PhysicalNumber& b){
    double res=0;
    if (a.getmeasure()==b.getmeasure()) res = b.get_data();
    else
    res = a.convert(a.getmeasure(),b.getmeasure(),a.get_measure(), b.get_measure(), b.get_data());
    return (a.get_data() == res);
    }


