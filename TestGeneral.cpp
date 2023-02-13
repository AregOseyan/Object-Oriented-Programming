#include "DateCell.hpp"
#include "Date.hpp"
#include <memory>
#include "IntCell.hpp"
#include "DoubleCell.hpp"
#include "StringCell.hpp"
#include "Cell.hpp"

void testDateCell() {
  std::cout << "The test of DateCell has started.\n(case 1) : ";
  std::unique_ptr<DateCell> obj(new DateCell());

  obj->setValue("2/12/2023");
  if (obj->getStringValue() == "2/12/2023") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "(case 2) : ";
  obj->reset();
  if (obj->getStringValue() == "") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "(case 3) : ";
  obj->reset();
  obj->setValue(" 2/  12/  2023");
  if (obj->getStringValue() == "2/12/2023") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "--------------------------------\n";
}

void testDoubleCell() {
  std::cout << "The test of DoubleCell has started.\n(case 1) : ";
  std::unique_ptr<DoubleCell> obj(new DoubleCell());

  obj->setValue("3.14");
  if (obj->getStringValue() == "3.14") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  obj->reset();
  std::cout << "(case 2) : ";
  if (obj->getStringValue() == "") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  obj->reset();
  std::cout << "(case 3) : ";
  obj->setValue(1.04);
  if (obj->getStringValue() == "1.04") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  obj->reset();
  std::cout << "(case 4) : ";
  obj->setValue(-1.04);
  if (obj->getStringValue() == "-1.04") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  obj->reset();
  std::cout << "(case 5) : ";
  obj->setValue(" 00.02 ");
  if (obj->getStringValue() == "0.02") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "--------------------------------\n";
}

void testIntCell() {
  std::cout << "The test of IntCell has started.\n(case 1) : ";
  std::unique_ptr<IntCell> obj(new IntCell());

  obj->setValue(" 5 5 ");
  if (obj->getStringValue() == "55") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  obj->reset();
  std::cout << "(case 2) : ";
  if (obj->getStringValue() == "") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "(case 3) : ";
  obj->reset();
  obj->setValue(100);
  if (obj->getStringValue() == "100") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "(case 4) : ";
  obj->reset();
  obj->setValue(-41);
  if (obj->getStringValue() == "-41") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "(case 5) : ";
  obj->reset();
  obj->setValue("41.0000");
  if (obj->getStringValue() == "41") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "(case 6) : ";
  obj->reset();
  obj->setColor(Color::Blue);
  if (obj->getColor() == Color::Blue) {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "--------------------------------\n";
}

void testStringCell() {
  std::cout << "The test of StringCell has started.\n(case 1) : ";
  std::unique_ptr<StringCell> obj(new StringCell());
  obj->setValue("Hello!");
  
  if (obj->getStringValue() == "Hello!") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  obj->reset();
  std::cout << "(case 2) : ";
  if (obj->getStringValue() == "") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }
}
