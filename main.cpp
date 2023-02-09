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

void testSpreadSheetValues();
void testSpreadSheetAdd();
void testSpreadSheetSwap();
void testSpreadSheetRemove();
void testSpreadSheetDisplay();
void runTestsSpreadSheet() {
  std::cout << "***The SpreadSheet class test has started***\n";
  testSpreadSheetValues();
  testSpreadSheetAdd();
  testSpreadSheetRemove();
  testSpreadSheetSwap();
  testSpreadSheetDisplay();
  std::cout << "********************************\n\n";
}

int main()
{
  runTestsDate();
  runTestsCell();
  runTestsSpreadSheet();

  return {};
}
