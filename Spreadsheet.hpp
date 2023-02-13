#ifndef SPREADSHEET_HPP
#define SPREADSHEET_HPP
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <map>
#include <fstream>
#include "Cell.hpp"
#include "DateCell.hpp"
#include "DoubleCell.hpp"
#include "IntCell.hpp"
#include "StringCell.hpp"
#define ui unsigned int

class Spreadsheet
{
public:
  Spreadsheet() = default;
  Spreadsheet(ui row, ui col) noexcept;
  Spreadsheet(Spreadsheet&& src) noexcept;
  ~Spreadsheet() = default;

public:
  void setCellAt(ui row, ui col, const std::string& str);
  void setCellAt(ui row, ui col, std::unique_ptr<Cell> cell);
  std::string getCellAt(ui row, ui col) const;
  ui getSizeRow() const;
  ui getSizeCol() const;
  void addRow(ui rowNum);
  void removeRow(ui rowNum);
  void addColumn(ui colNum);
  void removeColumn(ui colNum);
  void swapRows(ui row1, ui row2);
  void swapColumns(ui col1, ui col2);
  void displayMatrix() const;
  void swapCells(std::pair<int, int> p1, std::pair<int, int> p2);
  void writeToFile() const;

public:
  Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

private:
  std::map<std::pair<int, int>, std::unique_ptr<Cell>> m_cells;
  ui m_row {};
  ui m_col {};
};
#endif // SPREADSHEET_HPP
