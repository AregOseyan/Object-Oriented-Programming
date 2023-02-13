#include <iostream>

void testDateGetValues();
void testDateSetValues();
void runTestsDate() {
  std::cout << "***The Date class test has started***\n";
  testDateGetValues();
  testDateSetValues();
  std::cout << "********************************\n\n";
}

void testSpreadsheetValues();
void testSpreadsheetAdd();
void testSpreadsheetRemove();
void testSpreadsheetSwap();
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

void testDateCell();
void testDoubleCell();
void testIntCell();
void testStringCell();
void runTestsGeneral() {
  std::cout << "***The general test's has started***\n";
  testDateCell();
  testDoubleCell();
  testIntCell();
  testStringCell();
  std::cout << "********************************\n\n";
}

int main()
{
  runTestsDate();
  runTestsSpreadsheet();
  runTestsGeneral();

  return {};
}
