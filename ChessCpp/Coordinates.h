#pragma once

struct Coordinates
{
	int row;
	int col;
	bool isOnBoard() const
	{
		return (row >= 0 || row <= 7) && (col >= 0 || col <= 7);
	}
};
