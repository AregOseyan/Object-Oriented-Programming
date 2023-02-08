#include <iostream>
#include <memory>
#include "Cell.hpp"
#include "Date.hpp"

void testCellValues() {
  std::cout << "The test of setValue(), getValue() methods has started. ";
  std::unique_ptr<Cell> obj(new Cell());
  obj->setValue("10");
  if (obj->getValue() == "10") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }
}

void testCellReset() {
  std::cout << "The test of reset() method has started. ";
  std::unique_ptr<Cell> obj(new Cell());
  obj->setValue("10");
  obj->reset();
  if (obj->getValue() == "") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }
}

void testCellToInt() {
  std::cout << "The test of toInt() method has started.\n(case 1) ";
  std::unique_ptr<Cell> obj(new Cell());
  obj->setValue("41");
  try {
    if (obj->toInt() == 41) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
 
  std::cout << "(case 2) ";
  obj->reset();
  obj->setValue("-41");
  try {
    if (obj->toInt() == -41) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "(case 3) ";
  obj->reset();
  obj->setValue(" 41.000");
  try {
    if (obj->toInt() == 41) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "(case 4) ";
  obj->reset();
  obj->setValue("aaah 41.000");
  try {
    if (obj->toInt() == 41) {
      std::cout << "[ Test failed ]\n";
    }
    else {
      std::cout << "[ Test passed ]\n";
    }
  } 
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

void testCellToDouble() {
  std::cout << "The test of toDouble() method has started.\n(case 1) ";
  std::unique_ptr<Cell> obj(new Cell());
  obj->setValue("3.14");
  try {
    if (obj->toDouble() == 3.14) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "(case 2) ";
  obj->reset();
  obj->setValue("-3.14");
  try {
    if (obj->toDouble() == -3.14) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "(case 3) ";
  obj->reset();
  obj->setValue(" 00.2");
  try {
    if (obj->toDouble() == 0.2) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

void testCellToDate() {
  std::cout << "The test of toDate() method has started.\n(case 1) ";
  std::unique_ptr<Cell> obj(new Cell());
  std::unique_ptr<Date> cmpObj(new Date(2, 8, 2023));
  obj->setValue("2 /8/ 2023 ");
  try {
    Date cellDate = obj->toDate();
    if ((cellDate.getDay() == cmpObj->getDay()) && (cellDate.getMonth() == cmpObj->getMonth()) 
        && (cellDate.getYear() == cmpObj->getYear())) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "(case 2) ";
  obj->reset();
  obj->setValue("2 /8/ 2023 / 25/ 6");
  try {
    Date cellDate = obj->toDate();
    if ((cellDate.getDay() == cmpObj->getDay()) && (cellDate.getMonth() == cmpObj->getMonth())
        && (cellDate.getYear() == cmpObj->getYear())) {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
