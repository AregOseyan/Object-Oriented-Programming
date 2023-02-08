#include "SpreadSheet.hpp"
#include <stdexcept>

SpreadSheet::SpreadSheet(ui row, ui col) noexcept
  : m_row(row)
  , m_col(col)
{
  m_cells = new Cell*[row];
  for (int i = 0; i < row; ++i) {
    m_cells[i] = new Cell[col];
  }
}

SpreadSheet::SpreadSheet(const SpreadSheet& rhs) noexcept
  : m_row(rhs.m_row)
  , m_col(rhs.m_col) 
{
  m_cells = new Cell*[m_row];
  for (int i = 0; i < m_row; ++i) {
    m_cells[i] = new Cell[m_col];
    for (int j = 0; j < m_col; j++) {
      m_cells[i][j] = rhs.m_cells[i][j];
    }
  }
}

SpreadSheet::~SpreadSheet() {
  for (int i = 0; i < m_row; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;
}

void SpreadSheet::setCellAt(ui row, ui col, const Cell& cells)  {
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  m_cells[row][col] = cells;
}

void SpreadSheet::setCellAt(ui row, ui col, const std::string& str) {
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  m_cells[row][col].setValue(str);
}

Cell SpreadSheet::getCellAt(ui row, ui col) const
{ 
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  Cell res = m_cells[row][col];
  return res;
}

ui SpreadSheet::getSizeRow() const {
  return m_row;
}

ui SpreadSheet::getSizeCol() const {
  return m_col;
}

void SpreadSheet::addRow(ui rowNum) {
  if (rowNum >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  SpreadSheet newSpreadSheet(m_row + 1, m_col);
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      if (i < rowNum) {
        newSpreadSheet.m_cells[i][j] = m_cells[i][j];
      } 
      else {
        newSpreadSheet.m_cells[i + 1][j] = m_cells[i][j];
      }
    }
  }

  for (int j = 0; j < m_col; ++j) {
    newSpreadSheet.m_cells[rowNum][j].setValue("Success");
  }
 
  for (int i = 0; i < m_row; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;

  m_row = newSpreadSheet.m_row;
  m_col = newSpreadSheet.m_col;
  m_cells = new Cell*[m_row];
  for (int i = 0; i < m_row; ++i) {
    m_cells[i] = new Cell[m_col];
    for (int j = 0; j < m_col; ++j) {
      m_cells[i][j] = newSpreadSheet.m_cells[i][j];
    }
  }
}

void SpreadSheet::removeRow(ui rowNum) {
  if (rowNum >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  int c = 0;
  SpreadSheet newSpreadSheet(m_row - 1, m_col);
  for (int i = 0; i < m_row; ++i) {
    if (i == rowNum) {
      continue;
    }
    for (int j = 0; j < m_col; ++j) {
      newSpreadSheet.m_cells[c][j] = m_cells[i][j];
    }
    c++;
  }
  
  for (int i = 0; i < m_row; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;

  m_row = newSpreadSheet.m_row;
  m_col = newSpreadSheet.m_col;
  m_cells = new Cell*[m_row];
  for (int i = 0; i < m_row; ++i) {
    m_cells[i] = new Cell[m_col];
    for (int j = 0; j < m_col; ++j) {
      m_cells[i][j] = newSpreadSheet.m_cells[i][j];
    }
  }
}

void SpreadSheet::addColumn(ui colNum) {
  if (colNum >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  SpreadSheet newSpreadSheet(m_row, m_col + 1);
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      if (j < colNum) {
        newSpreadSheet.m_cells[i][j] = m_cells[i][j];
      }
      else {
        newSpreadSheet.m_cells[i][j + 1] = m_cells[i][j];
      }
    }
  }

  for (int i = 0; i < m_row; ++i) {
    newSpreadSheet.m_cells[i][colNum].setValue("Success");
  }

  for (int i = 0; i < m_row; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;

  m_row = newSpreadSheet.m_row;
  m_col = newSpreadSheet.m_col;
  m_cells = new Cell*[m_row];
  for (int i = 0; i < m_row; ++i) {
    m_cells[i] = new Cell[m_col];
    for (int j = 0; j < m_col; ++j) {
      m_cells[i][j] = newSpreadSheet.m_cells[i][j];
    }
  }
}

void SpreadSheet::removeColumn(ui colNum) {
  if (colNum >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  int c = 0;
  SpreadSheet newSpreadSheet(m_row, m_col - 1);
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      if (j == colNum) {
        continue;
      }
      newSpreadSheet.m_cells[i][c] = m_cells[i][j];
      c++;
    }
    c = 0;
  }

  for (int i = 0; i < m_row; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;

  m_row = newSpreadSheet.m_row;
  m_col = newSpreadSheet.m_col;
  m_cells = new Cell*[m_row];
  for (int i = 0; i < m_row; ++i) {
    m_cells[i] = new Cell[m_col];
    for (int j = 0; j < m_col; ++j) {
      m_cells[i][j] = newSpreadSheet.m_cells[i][j];
    }
  }
}

void SpreadSheet::swapRows(ui row1, ui row2) {
  if ((row1 >= this->m_row) || (row2 >= this->m_row) || (row1 == row2)) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  for (int i = 0; i < m_col; ++i) {
    m_cells[row1][i].swap(m_cells[row2][i]);
  }
}

void SpreadSheet::swapColumns(ui col1, ui col2) {
  if ((col1 >= this->m_col) || (col2 >= this->m_col) || (col1 == col2)) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  for (int j = 0; j < m_row; ++j) {
    m_cells[j][col1].swap(m_cells[j][col2]);
  }
}

SpreadSheet& SpreadSheet::operator=(const SpreadSheet& other) {
  if (this != &other) {
    for (int i = 0; i < m_row; ++i) {
      delete[] m_cells[i];
    }
    delete[] m_cells;
    m_row = other.m_row;
    m_col = other.m_col;
    m_cells = new Cell*[m_row];
    for (int i = 0; i < m_row; ++i) {
      m_cells[i] = new Cell[m_col];
      for (int j = 0; j < m_col; ++j) {
        m_cells[i][j] = other.m_cells[i][j];
      }
    }
  }
  return *this;
}
