#include <iostream>
#include <memory>
#include "Cell.hpp"
#include "Spreadsheet.hpp"
#include "Date.hpp"

void testSpreadsheetValues() {
  std::cout << "The test of setCellAt(), getCellAt() methods has started.\n(case 1) ";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(4, 4));
  try {
    obj->setCellAt(0, 0, "name");
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  Cell tmp1 = obj->getCellAt(0, 0);
  if (tmp1.getValue() == "name") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }

  std::cout << "(case 2) ";
  try {
    obj->setCellAt(2, 2, tmp1);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  Cell tmp2 = obj->getCellAt(2, 2);
  if (tmp2.getValue() == "name") {
    std::cout << "[ Test passed ]\n";
  }
  else {
    std::cout << "[ Test failed ]\n";
  }
}

void testSpreadsheetAdd() {
  std::cout << "The test of addRow(), addColumn() methods has started.\n(case 1) ";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(4, 4));
  int oldSizeRow = obj->getSizeRow();
  int oldSizeCol = obj->getSizeCol();

  try {
    obj->addRow(2);
    oldSizeRow += 1;
    Cell tmp1 = obj->getCellAt(2, 1);
    if (tmp1.getValue() == "Success") {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }
    
    std::cout << "(case 2) ";
    obj->addColumn(3);
    oldSizeCol += 1;
    
    Cell tmp2 = obj->getCellAt(2, 3);
    if (tmp1.getValue() == "Success") {
      std::cout << "[ Test passed ]\n";
    }
    else {
      std::cout << "[ Test failed ]\n";
    }

    std::cout << "(case 3) ";
    if ((oldSizeRow == obj->getSizeRow()) && (oldSizeCol == obj->getSizeCol())) {
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

void testSpreadsheetRemove() {
  std::cout << "The test of removeRow(), removeColumn() methods has started.\n(case 1) ";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(4, 4));
  int oldSizeRow = obj->getSizeRow();
  int oldSizeCol = obj->getSizeCol();

  try {
    obj->removeRow(2);
    oldSizeRow -= 1;
    obj->removeColumn(2);
    oldSizeCol -= 1;
    if ((oldSizeRow == obj->getSizeRow()) && (oldSizeCol == obj->getSizeCol())) {
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

void testSpreadsheetSwap() {
  std::cout << "The test of swapRows(), swapColumns() methods has started.\n(case 1) ";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(2, 2));
  try {
    obj->setCellAt(0, 0, "3");
    obj->setCellAt(0, 1, "4");
    obj->setCellAt(1, 0, "5");
    obj->setCellAt(1, 1, "6");
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  
  try {
    obj->swapRows(1, 0);
    Cell tmp1 = obj->getCellAt(0, 0);
    Cell tmp2 = obj->getCellAt(1, 1);
    if ((tmp1.getValue() == "5") && (tmp2.getValue() == "4")) {
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
  try {
    obj->swapColumns(1, 0);
    Cell tmp3 = obj->getCellAt(0, 0);
    Cell tmp4 = obj->getCellAt(1, 1);
    if ((tmp3.getValue() == "6") && (tmp4.getValue() == "3")) {
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

void testSpreadsheetDisplay() {
  std::cout << "The test of displayMatrix() method has started.\n";
  std::unique_ptr<Spreadsheet> obj(new Spreadsheet(3, 4));
  try {
    obj->setCellAt(0, 0, "name");
    obj->setCellAt(0, 1, "4");
    obj->setCellAt(1, 0, "5");
    obj->setCellAt(1, 1, "6");
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Input matrix[0][0] = name\n      matrix[0][1] = 4\n      matrix[1][0] = 5\n      matrix[1][1] = 6\n";
  std::cout << "Matrix is\n";
  obj->displayMatrix();
  std::cout << std::endl;
}
