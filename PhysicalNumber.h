
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Unit.h"

using std::cout, std::endl, std::boolalpha, std::istringstream;
//using ariel::Unit;

namespace ariel{

    class PhysicalNumber{
    private:
    double data;
    std::string measure;
    Unit ms;

    public:

    PhysicalNumber();
    PhysicalNumber(double,Unit); // constructor
                                 // declarations
    bool boolalpha = false;
    friend std::ostream& operator<<(std::ostream&, const PhysicalNumber&);
    friend std::istream& operator>> (std::istream&, PhysicalNumber&);

    friend const PhysicalNumber operator+(const PhysicalNumber&, const PhysicalNumber&);
    friend const PhysicalNumber operator-(const PhysicalNumber&, const PhysicalNumber&);
    friend const PhysicalNumber operator+(const PhysicalNumber&);
    friend const PhysicalNumber operator-(const PhysicalNumber&);

    friend bool operator>(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator<(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator<=(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator>=(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator==(const PhysicalNumber&, const PhysicalNumber&);
    friend  bool operator!=(const PhysicalNumber&, const PhysicalNumber&); // friend does not need name of class in cpp

    const PhysicalNumber operator++(double);
    const PhysicalNumber operator--(double);

    PhysicalNumber& operator-=(const PhysicalNumber&);
    PhysicalNumber& operator--();
    PhysicalNumber& operator++();
    PhysicalNumber& operator+=(const PhysicalNumber&);
    double convert(Unit, Unit, std::string ,std::string , double) const;
    double get_data() const;

    std::string get_measure() const;
    Unit getmeasure() const;
    Unit getmeasure(std::string);
    void Throw(std::string) const;


};

}// end namespace



