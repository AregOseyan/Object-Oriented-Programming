#ifndef SPREADSHEET_HPP
#define SPREADSHEET_HPP
#include <iostream>
#include <stdexcept>
#include "Cell.hpp"
#define ui unsigned int

class Spreadsheet 
{
public:
  Spreadsheet() = default;
  Spreadsheet(ui row, ui col) noexcept;
  Spreadsheet(const Spreadsheet& src) noexcept;
  Spreadsheet(Spreadsheet&& src) noexcept;
  ~Spreadsheet();

public:
  void setCellAt(ui row, ui col, const Cell& cells);
  void setCellAt(ui row, ui col, const std::string& str);
  Cell getCellAt(ui row, ui col) const;
  ui getSizeRow() const;
  ui getSizeCol() const;

  void addRow(ui rowNum);
  void removeRow(ui rowNum);
  void addColumn(ui colNum);
  void removeColumn(ui colNum);

  void swapRows(ui row1, ui row2);
  void swapColumns(ui col1, ui col2);
  void displayMatrix() const;
public:
  Spreadsheet& operator=(const Spreadsheet& rhs);
  Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

private:
  void deleteMatrix() noexcept;
  void copySpreadsheet(const Spreadsheet& other);
  void moveFrom(Spreadsheet& src) noexcept;

private:
  Cell** m_cells;
  ui m_row {}; 
  ui m_col {};
};
#endif // SPREADSHEET_HPP
