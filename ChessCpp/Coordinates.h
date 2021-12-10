#pragma once

struct Coordinates
{
	// Maybe I should have used std::pair instead
	int row;
	int col;
	bool isOnBoard() const
	{
		return (row >= 0 && row <= 7) && (col >= 0 && col <= 7);
	}
};
