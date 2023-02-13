#include <iostream>
#include <memory>
#include "Cell.hpp"
#include "IntCell.hpp"
#include "DoubleCell.hpp"
#include "StringCell.hpp"
#include "DateCell.hpp"
#include "Spreadsheet.hpp"
#include "Date.hpp"

void testSpreadsheetValues() {
  std::cout << "The test of setCellAt(), getCellAt(), swapCells() methods has started.\n(case 1) : ";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(4, 4));
  try {
    std::unique_ptr<StringCell> obj1(new StringCell());
    obj1->setValue("name1");
    obj->setCellAt(0, 0, std::move(obj1));

    if (obj->getCellAt(0, 0) == "name1") {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }

    std::unique_ptr<StringCell> obj2(new StringCell());
    obj2->setValue("name2");
    obj->setCellAt(2, 3, std::move(obj2));
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  obj->displayMatrix();
  std::cout << "\nAfter swap(matrix[2][3], matrix[0][0])\n";
  obj->swapCells(std::make_pair(0, 0), std::make_pair(2, 3));
  obj->displayMatrix();
   
  std::cout<< "(case 2) : ";
  if (obj->getCellAt(0, 0) == "name2") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }
  std::cout << "--------------------------------\n";
}

void testSpreadsheetAdd() {
  std::cout << "The test of addRow(), addColumn() methods has started.\n";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(3, 4));
  try {
    std::unique_ptr<StringCell> obj1(new StringCell());
    obj1->setValue("name");
    obj->setCellAt(0, 0, std::move(obj1));

    std::unique_ptr<IntCell> obj2(new IntCell());
    obj2->setValue("4");
    obj->setCellAt(0, 1, std::move(obj2));

    std::unique_ptr<DoubleCell> obj3(new DoubleCell());
    obj3->setValue("5.4");
    obj->setCellAt(1, 0, std::move(obj3));

    std::unique_ptr<DateCell> obj4(new DateCell());
    obj4->setValue("2/13/2023");
    obj->setCellAt(1, 1, std::move(obj4));

    std::unique_ptr<IntCell> obj5(new IntCell());
    obj5->setValue("10");
    obj->setCellAt(0, 3, std::move(obj5));

    std::unique_ptr<IntCell> obj6(new IntCell());
    obj6->setValue("15");
    obj->setCellAt(2, 3, std::move(obj6));
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Before the modifications.\n";
  obj->displayMatrix();
  std::cout << "\nAfter addRow(0)\n";
  obj->addRow(0);
  obj->displayMatrix();
  std::cout << "--------------------------------\n";
  std::cout << "\nAfter addColumn(1)\n";
  obj->addColumn(1);
  obj->displayMatrix();
  std::cout << "--------------------------------\n";
}

void testSpreadsheetRemove() {
  std::cout << "The test of removeRow(), removeColumn() methods has started.\n";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(3, 4));
  try {
    std::unique_ptr<StringCell> obj1(new StringCell());
    obj1->setValue("name");
    obj->setCellAt(0, 0, std::move(obj1));

    std::unique_ptr<IntCell> obj2(new IntCell());
    obj2->setValue("4");
    obj->setCellAt(0, 1, std::move(obj2));

    std::unique_ptr<DoubleCell> obj3(new DoubleCell());
    obj3->setValue("5.4");
    obj->setCellAt(1, 0, std::move(obj3));

    std::unique_ptr<DateCell> obj4(new DateCell());
    obj4->setValue("2/13/2023");
    obj->setCellAt(1, 1, std::move(obj4));

    std::unique_ptr<IntCell> obj5(new IntCell());
    obj5->setValue("10");
    obj->setCellAt(0, 3, std::move(obj5));

    std::unique_ptr<IntCell> obj6(new IntCell());
    obj6->setValue("15");
    obj->setCellAt(2, 3, std::move(obj6));
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }  
  std::cout << "Before the modifications.\n";
  obj->displayMatrix();
  std::cout << "\nAfter removeRow(0)\n";
  obj->removeRow(0);
  obj->displayMatrix();
  std::cout << "--------------------------------\n";
  std::cout << "\nAfter removeColumn(2)\n";
  obj->removeColumn(2);
  obj->displayMatrix();
  std::cout << "--------------------------------\n";
}

void testSpreadsheetSwap() {
  std::cout << "The test of swapRows(), swapColumns() methods has started.\n";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(2, 2));
  try {
    std::unique_ptr<StringCell> obj1(new StringCell());
    obj1->setValue("name");
    obj->setCellAt(0, 0, std::move(obj1));

    std::unique_ptr<IntCell> obj2(new IntCell());
    obj2->setValue("4");
    obj->setCellAt(0, 1, std::move(obj2));

    std::unique_ptr<DoubleCell> obj3(new DoubleCell());
    obj3->setValue("5.4");
    obj->setCellAt(1, 0, std::move(obj3));

    std::unique_ptr<IntCell> obj4(new IntCell());
    obj4->setValue("2");
    obj->setCellAt(1, 1, std::move(obj4));
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Before the modifications.\n";
  obj->displayMatrix();
  std::cout << "\nAfter swapRows(1, 0)\n";
  try {
    obj->swapRows(1, 0);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  obj->displayMatrix();
  std::cout << "--------------------------------\n";
  std::cout << "\nAfter swapColumns(1, 0)\n";
  try {
    obj->swapColumns(1, 0);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  obj->displayMatrix();
  std::cout << "--------------------------------\n";
}

void testSpreadsheetDisplay() {
  std::cout << "The test of displayMatrix() method has started.\n";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(3, 4));
  try {
    std::unique_ptr<StringCell> obj1(new StringCell());
    obj1->setValue("name");
    obj->setCellAt(0, 0, std::move(obj1));

    std::unique_ptr<IntCell> obj2(new IntCell());
    obj2->setValue("4");
    obj->setCellAt(0, 1, std::move(obj2));

    std::unique_ptr<DoubleCell> obj3(new DoubleCell());
    obj3->setValue("5.4");
    obj->setCellAt(1, 0, std::move(obj3));

    std::unique_ptr<DateCell> obj4(new DateCell());
    obj4->setValue("2/13/2023");
    obj->setCellAt(1, 1, std::move(obj4));
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Input matrix[0][0] = name\n      matrix[0][1] = 4\n      matrix[1][0] = 5.4\n      matrix[1][1] = 2/13/2023\n\n";
  std::cout << "Matrix is\n";
  obj->displayMatrix();
  obj->writeToFile();
}
