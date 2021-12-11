#pragma once

#include <string>

struct Coordinates
{
	// Maybe I should have used std::pair instead
	int row;
	int col;
	bool isOnBoard() const
	{
		return (row >= 0 && row <= 7) && (col >= 0 && col <= 7);
	}

	std::string toString() const
	{
		char file{static_cast<char>(row + 49)};
		char rank{static_cast<char>(col + 65)};
		return std::string{rank, file};
	}
};
