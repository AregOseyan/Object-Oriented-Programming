#include <iostream>
#include <memory>
#include "Date.hpp"

void testDateGetValues() {
  std::cout << "The test of getMonth(), getDay(), getYear() methods has started. ";
  std::unique_ptr<Date> obj(new Date(2, 8, 2023));
  if ((obj->getMonth() == 2) && (obj->getDay() == 8) && (obj->getYear() == 2023)) {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }
}

void testDateSetValues() {
  std::cout << "The test of setMonth(), setDay(), setYear() methods has started. ";
  std::unique_ptr<Date> obj(new Date());
  try {
    obj->setMonth(2);
    obj->setDay(8);
    obj->setYear(2023);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  if ((obj->getMonth() == 2) && (obj->getDay() == 8) && (obj->getYear() == 2023)) {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }
}
