#include <iostream>

void testDateGetValues();
void testDateSetValues();
void runTestsDate() {
  std::cout << "***The Date class test has started***\n";
  testDateGetValues();
  testDateSetValues();
  std::cout << "********************************\n\n";
}

void testCellValues();
void testCellReset();
void testCellToInt(); 
void testCellToDouble();
void testCellToDate();
void runTestsCell() {
  std::cout << "***The Cell class test has started***\n";
  testCellValues();
  testCellReset();
  testCellToInt();
  testCellToDouble();
  testCellToDate();
  std::cout << "********************************\n\n";
}

void testSpreadsheetValues();
void testSpreadsheetAdd();
void testSpreadsheetSwap();
void testSpreadsheetRemove();
void testSpreadsheetDisplay();
void runTestsSpreadsheet() {
  std::cout << "***The Spreadsheet class test has started***\n";
  testSpreadsheetValues();
  testSpreadsheetAdd();
  testSpreadsheetRemove();
  testSpreadsheetSwap();
  testSpreadsheetDisplay();
  std::cout << "********************************\n\n";
}

int main()
{
  runTestsDate();
  runTestsCell();
  runTestsSpreadsheet();

  return {};
}
