
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
   // friend std::istream& operator>> (std::istream&, PhysicalNumber&);
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
    double convert(Unit, Unit, std::string ,std::string , double) const;
    double get_data() const{return data;}
    std::string get_measure() const{return measure;}
    Unit getmeasure() const;
    Unit getmeasure(std::string);
    void Throw(std::string) const;


   friend std::istream& operator>> (std::istream& input, PhysicalNumber& a) {
   // WHAT IS INPUT.GET , INPUT.PEEK   . INPUT.SETSTATE

    std::string tmpStr;
    std::string m_str;

    input >>  tmpStr;
    int index = tmpStr.find('[');
    int index2 = tmpStr.find(']');

    if (index==-1 || index2 == -1) { //
  //  a.Throw("[ or ] is missing= " + tmpStr);
  input.setstate(std::ios::failbit);
  return input;
    }

    if (index == 0) // there is nothing before the [
    {
   // a.Throw("nothing before [");
     input.setstate(std::ios::failbit);
    }
       // cout << "TEST1 " << tmpStr << endl;

    std::string newNum = tmpStr.substr(0,index);

    // check what is this type of number. (str, or number, or str+number)
   // cout << index2 << endl;
    m_str = tmpStr.substr(index+1);
    m_str = m_str.substr(0,m_str.length()-1);

    // check if it's appropriate measure.   Capital letter?

    if (m_str == "m" || m_str == "km" || m_str == "cm" || m_str == "sec" || m_str == "hour" || m_str == "min" || m_str == "ton"
     || m_str == "g"
    || m_str == "kg"){
    //cout << "TEST " << newNum << endl;

    int number = 0;
    istringstream xx(newNum);
    xx >> number;

    a = PhysicalNumber(number, a.getmeasure(m_str));
    }
    else{
   // a.Throw("not valid measurment "+ tmpStr);
     input.setstate(std::ios::failbit);

    }

    //cout << "try to test=" << tmpStr << ',' << index << ',' << m_str << endl;

    return (input >> a.data);

   }



     PhysicalNumber& operator+=(const PhysicalNumber& b){
     double res=0;
     if (getmeasure()==b.getmeasure()) res = b.get_data();
     else
     res = convert(getmeasure(),b.getmeasure(),get_measure(), b.get_measure(), b.get_data());
     data = data+res;
     return *this;
    }

     PhysicalNumber& operator-=(const PhysicalNumber& b){
     double res=0;
     if (getmeasure()==b.getmeasure()) res = b.get_data();
     else
     res = convert(getmeasure(),b.getmeasure(),get_measure(), b.get_measure(), b.get_data());
     data = data-res;
     return *this;
    }

     PhysicalNumber& operator++(){ // prefix inc (++a)
     data++;
     return *this;
    }

    const PhysicalNumber operator++(int d) { // postfix inc (a++)
    PhysicalNumber copy = *this;
    data++;
    return copy;
    }


    PhysicalNumber& operator--(){ // prefix inc (--a)
    data--;
    return *this;
    }

    const PhysicalNumber operator--(int d) { // postfix inc (a--)
    PhysicalNumber copy = *this;
    data--;
    return copy;
    }
};

}// end namespace



