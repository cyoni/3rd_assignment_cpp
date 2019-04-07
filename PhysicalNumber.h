
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Unit.h"

using std::cout, std::endl, std::boolalpha, std::istringstream;

namespace ariel{

    class PhysicalNumber{
    private:
    double data;
    std::string measure;
    Unit ms;
    public:

    PhysicalNumber();
    PhysicalNumber(double,Unit); // constructor

    bool boolalpha = false;
    void getMeasures(std::string& g,  ariel::Unit ms_a) const;
    friend std::ostream& operator<<(std::ostream&, const PhysicalNumber&);
    friend const PhysicalNumber operator+(const PhysicalNumber&, const PhysicalNumber&);
    friend const PhysicalNumber operator-(const PhysicalNumber&, const PhysicalNumber&);
    friend const PhysicalNumber operator+(const PhysicalNumber&);
    friend const PhysicalNumber operator-(const PhysicalNumber&);
    friend const bool operator>(const PhysicalNumber&, const PhysicalNumber&);
    friend const bool operator<(const PhysicalNumber&, const PhysicalNumber&);
    friend const bool operator<=(const PhysicalNumber&, const PhysicalNumber&);
    friend const bool operator>=(const PhysicalNumber&, const PhysicalNumber&);
    friend const bool operator==(const PhysicalNumber&, const PhysicalNumber&);
    friend const bool operator!=(const PhysicalNumber&, const PhysicalNumber&);

    friend std::istream& operator>> (std::istream& input, PhysicalNumber& a) {
    return (input >> a.data);
    }


     double convert(ariel::Unit, ariel::Unit, double) const;
     double get_data() const{return data;}
     std::string get_measure() const{return measure;}
     Unit getmeasure() const;
     void Throw(std::string) const;

     PhysicalNumber& operator+=(const PhysicalNumber& b){
     return *this;
     }

     PhysicalNumber& operator-=(const PhysicalNumber& b){
     return *this;
     }

     PhysicalNumber& operator++(){ // prefix inc (++a)
     return *this;
     }

    const PhysicalNumber operator++(int d) { // postfix inc (a++)
    PhysicalNumber copy = *this;
    return copy;
    }


    PhysicalNumber& operator--(){ // prefix inc (--a)
    return *this;
    }

    const PhysicalNumber operator--(int d) { // postfix inc (a--)
    PhysicalNumber copy = *this;
    return copy;
    }
};

}// end namespace



