/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    ///

    PhysicalNumber z0(10, Unit::M);
    PhysicalNumber z1(120, Unit::KM);
    PhysicalNumber z2(5, Unit::G);
    PhysicalNumber z3(20, Unit::KG);
    PhysicalNumber z4(5, Unit::HOUR);
    PhysicalNumber z5(15, Unit::SEC);
    PhysicalNumber z6(2, Unit::CM);
    PhysicalNumber z7(2, Unit::MIN);
    PhysicalNumber z8(3600, Unit::SEC);
    PhysicalNumber z9(20, Unit::M);
    PhysicalNumber z10(10, Unit::HOUR);
    PhysicalNumber z11(15, Unit::M);
    PhysicalNumber z12(5, Unit::CM);
    PhysicalNumber z13(6, Unit::CM);
    PhysicalNumber z14(1, Unit::G);
    PhysicalNumber z15(25, Unit::KM);
    PhysicalNumber z16(3, Unit::MIN);
    PhysicalNumber z17(60, Unit::SEC);
    PhysicalNumber z18(0, Unit::MIN);
    PhysicalNumber z19(2, Unit::TON);
    PhysicalNumber z20(2000, Unit::KG);



    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

    .setname("Basic output")
    .CHECK_OUTPUT(z0, "10[m]")
    .CHECK_OUTPUT(z1, "120[km]")
    .CHECK_OUTPUT(z2, "5[g]")
    .CHECK_OUTPUT(z3, "20[kg]")
    .CHECK_OUTPUT(z4, "5[hour]")
    .CHECK_OUTPUT(z5, "15[sec]")
    .CHECK_OUTPUT(z6, "2[cm]")
    .CHECK_OUTPUT(z7, "2[min]")


    .CHECK_OK(istringstream("20[kg]") >> z5)
    .CHECK_OUTPUT((z5 += PhysicalNumber(1, Unit::KG)), "21[kg]")
    .CHECK_OK(istringstream("5[kg]") >> z5)
    .CHECK_OUTPUT((z5 += PhysicalNumber(1, Unit::TON)), "1005[kg]")
    .CHECK_OK(istringstream("10[g]") >> z14)
    .CHECK_OUTPUT((z14 -= PhysicalNumber(10, Unit::G)), "0[g]")
    .CHECK_OUTPUT(z14, "0[g]")
    .CHECK_OUTPUT((z15 += PhysicalNumber(10, Unit::M)), "25.01[km]")



   .setname("Compatible dimensions")
    .CHECK_OUTPUT(z0+z1, "120010[m]")
    .CHECK_OUTPUT((z0-=z1), "-119990[m]")
    .CHECK_OUTPUT(z2, "5[g]")
    .CHECK_OUTPUT(z3+z3, "40[kg]")
    .CHECK_OUTPUT(z2+z3, "20005[g]")
    .CHECK_OUTPUT(z4+z4, "10[hour]")
    .CHECK_OUTPUT(z4+z8, "6[hour]")
    .CHECK_OUTPUT((z4+=z8), "6[hour]")
    .CHECK_OUTPUT(z4+z8, "7[hour]")
    .CHECK_OUTPUT(z6-z6, "0[cm]")
    .CHECK_OUTPUT(z6++, "2[cm]")
    .CHECK_OUTPUT(z6, "3[cm]")
    .CHECK_OUTPUT(z3, "20[kg]")
    .CHECK_OUTPUT(--z3, "19[kg]")
    .CHECK_OUTPUT(z16+z17, "4[min]")
    .CHECK_OUTPUT(z16+(z17++), "4[min]")
    .CHECK_OUTPUT(z16+(--z18), "3[min]")
    .CHECK_OUTPUT((--z20)+(--z19), "2999[kg]")//
    .CHECK_OUTPUT((--z20)-(--z19), "1998[kg]")//


    .setname("Incompatible dimensions")
    .CHECK_THROWS(z7+z5)
    .CHECK_THROWS(z0+z7)
    .CHECK_THROWS(z0+z2)
    .CHECK_THROWS(z4+z6)
    .CHECK_THROWS(z3+z0)
    .CHECK_THROWS(z6-z4)
    .CHECK_THROWS(z2-z0)

    .setname("Comparison operators")

    .CHECK_OUTPUT((z9>z11), "1")  // 1 is true
    .CHECK_OUTPUT((z9<z11), "0") // 0 is false
    .CHECK_OUTPUT((z9<=z11), "0")  // 1 is true
    .CHECK_OUTPUT((z12>=z13), "0")  // 1 is true
    .CHECK_OUTPUT((z4<z10), "1")


      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}

