#ifndef SPREADSHEET_HPP
#define SPREADSHEET_HPP
#include "Cell.hpp"
#define ui unsigned int

class SpreadSheet 
{
public:
  SpreadSheet() = default;
  SpreadSheet(ui row, ui col) noexcept;
  SpreadSheet(const SpreadSheet& rhs) noexcept;
  ~SpreadSheet();

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
public:
  SpreadSheet& operator=(const SpreadSheet& other);

private:
  Cell** m_cells;
  ui m_row {}; 
  ui m_col {};
};
#endif // SPREADSHEET_HPP
