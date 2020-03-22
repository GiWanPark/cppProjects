#include <iostream>
#include <vector>
#define SUDOKUSIZE 9


class SudokuSolver
{
private :
	int SudokuMap[SUDOKUSIZE][SUDOKUSIZE];
	int SudokuSection[SUDOKUSIZE][SUDOKUSIZE];
	long long int count;

	bool CheckRightNumber(int y, int x)
	{
		int i, j;
		int thisSection = SudokuSection[y][x];
		for (i = 0; i < SUDOKUSIZE; ++i)
		{
			if (i != x && SudokuMap[y][i] == SudokuMap[y][x]) return false;
			if (i != y && SudokuMap[i][x] == SudokuMap[y][x]) return false;
		}
		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3; ++j)
				if (thisSection / 3 * 3 + i != y && thisSection % 3 * 3 + j != x &&
					SudokuMap[thisSection / 3 * 3 + i][thisSection % 3 * 3 + j] == SudokuMap[y][x])
					return false;
		return true;
	}
	void GetDefaultSudoku()
	{
		int i, j;

		for (i = 0; i < SUDOKUSIZE; ++i)
		{
			for (j = 0; j < SUDOKUSIZE; ++j)
			{
				std::cin >> SudokuMap[i][j];
				//SudokuSection[i * SUDOKUSIZE + j] = (i / 3) * 3 + j / 3;
				SudokuSection[i][j] = (i / 3) * 3 + j / 3;
			}
		}
	}
	int Solve(int y, int x)
	{
		if (SudokuMap[y][x] != 0)
		{
			if (x + 1 > SUDOKUSIZE - 1)
			{
				if (y + 1 >= SUDOKUSIZE)
				{
					print();
					std::exit(0);
				}
				Solve(y + 1, 0);
			}
			else
				Solve(y, x + 1);
			return 999;
		}

		
		//std::vector<int> pNumber = GetPossibleNumber(y, x);
		int i;
		for (i = 1; i <= SUDOKUSIZE; ++i)
		{
			SudokuMap[y][x] = i;
			if (CheckRightNumber(y, x) == false)
				continue;

			if (x + 1 > SUDOKUSIZE - 1)
			{
				if (y + 1 >= SUDOKUSIZE)
				{
					print();
					std::exit(0);
				}
				Solve(y + 1, 0);
			}
			else
				Solve(y, x + 1);
		}
		SudokuMap[y][x] = 0;
		return 0;
	}
	
public :
	SudokuSolver()
	{
		count = 1;
	}
	int Solve()
	{
		GetDefaultSudoku();
		return Solve(0, 0);
	}
	void print()
	{
		system("cls");
		for (int i = 0; i < SUDOKUSIZE; ++i)
		{
			for (int j = 0; j < SUDOKUSIZE; ++j)
			{
				std::cout << SudokuMap[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	SudokuSolver sSolver;

	std::cout << sSolver.Solve() << std::endl;
	//sSolver.print();
	return 0;
}