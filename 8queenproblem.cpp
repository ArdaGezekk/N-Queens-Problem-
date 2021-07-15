#include <iostream>
#include <iomanip>
#include <vector >
#include <time.h>

const int unassign = -1;
const int rows = 8;
const int columns = 8;
std::vector <int> AssignRow(rows, unassign);
std::vector <std::vector  <int>> PlacementSolutions;

bool ValidPosition(int col_pos, int row_pos) {
	for (int i = 0; i < AssignRow.size(); ++i) {
		if (i == row_pos)
			continue;
		if (AssignRow[i] != unassign) {
			if (abs(AssignRow[i] - col_pos) == abs(i - row_pos))
				return false;
		}
	}
	return true;
}

void DisplayBoard(std::vector <int> &Row)
{
	for (int row = 0; row < rows; ++row) {
		if (Row[row] == unassign) {
			continue;
		}
		for (int col = 0; col < Row[row]; ++col) {
			std::cout  << " - ";
		}
		std::cout  << " 0 ";
		for (int col = Row[row] + 1; col < columns; ++col) {
			std::cout  << " - ";
		}
		std::cout  << std::endl << std::endl;
	}
		std::cout  << std::endl;
}

bool QueenLand(int column) {
	if (PlacementSolutions.size() == 92) {
		return true;
	}
	else if (column == columns) {
		PlacementSolutions.push_back(AssignRow);
		return false;
	}
	else {
		for (int row = 0; row < AssignRow.size(); ++row) {
			if (AssignRow[row] != unassign)
				continue;
			if (!ValidPosition(column, row))
				continue;
			AssignRow[row] = column;
			if (QueenLand(column + 1)) {
				return true;
			}
			AssignRow[row] = unassign;
		}
		return false;
	}
}

int main()
{
	QueenLand(0);
	time_t start, end;
	start = clock();
	for (int i = 0; i < 92; i++) {
				std::cout  << " \n ######  "<< i + 1  <<" ######\n\n  ";
		DisplayBoard(PlacementSolutions[i]);
	}
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "\n\tBig O notation :" << "O" <<char(253);
	std::cout << "\n\tTime taken by program is : " << time_taken << std::setprecision(5); 	std::cout << " sec " << std::endl;
}
