#include<stdio.h>

void OddMagicSquare()
{
#define ROW 3
#define COL ROW
	int arr[ROW][COL] = { 0 };
	int row = 0;
	int col = ROW / 2;
	arr[row][col] = 1;
	for (int i = 2; i <= ROW*COL; i++)
	{
		if (row == 0)
		{
			row = ROW - 1;
		}
		else
		{
			row--;
		}
		col = (col + 1) % COL;
		if (arr[row][col] != 0)
		{
			row = (row + 2) % ROW;
			col = (col - 1 + COL) % COL;
		}
		arr[row][col] = i;
	}

	for (int i = 0; i<ROW; i++)
	{
		for (int j = 0; j<COL; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

#undef ROW
}

void MagicSquare2()
{
#define N 10
		int a[N][N] = { 0 };//存储魔方
		int i, k, temp;
		int col, row;// col 列，row 行

		//初始化
		k = N / 2;
		col = (k - 1) / 2;
		row = 0;
		a[row][col] = 1;
		//生成奇魔方A
		for (i = 2; i <= k*k; i++)
		{
			if ((i - 1) % k == 0)//前一个数是3的倍数
			{
				row++;
			}
			else
			{
				// if row = 0, then row = N-1, or row = row - 1
				row--;
				row = (row + k) % k;

				// if col = N, then col = 0, or col = col + 1
				col++;
				col %= k;
			}
			a[row][col] = i;
		}

		//根据A生成B、C、D魔方
		for (row = 0; row < k; row++)
		{
			for (col = 0; col < k; col++)
			{
				a[row + k][col + k] = a[row][col] + k*k;
				a[row][col + k] = a[row][col] + 2 * k*k;
				a[row + k][col] = a[row][col] + 3 * k*k;
			}
		}

		// Swap A and C
		for (row = 0; row < k; row++)
		{
			if (row == k / 2)//中间行，交换从中间列向右的m列，N = 2*(2m+1)
			{
				for (col = k / 2; col < k - 1; col++)
				{
					temp = a[row][col];
					a[row][col] = a[row + k][col];
					a[row + k][col] = temp;
				}
			}
			else//其他行，交换从左向右m列,N = 2*(2m+1)
			{
				for (col = 0; col < k / 2; col++)
				{
					temp = a[row][col];
					a[row][col] = a[row + k][col];
					a[row + k][col] = temp;
				}
			}
		}

		// Swap B and D
		for (row = 0; row < k; row++)//交换中间列向左m-1列，N = 2*(2m+1)
		{
			for (i = 0; i < (k - 1) / 2 - 1; i++)
			{
				temp = a[row][k + k / 2 - i];
				a[row][k + k / 2 - i] = a[row + k][k + k / 2 - i];
				a[row + k][k + k / 2 - i] = temp;
			}
		}

		//输出魔方阵
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
			{
				printf("%5d", a[row][col]);
			}
			printf("\n");
		}
#undef N
}

void MagicSquare4()
{
#define N 8
		int a[N][N];
		int temparray[N*N / 2];
		int i;
		int col, row;
		i = 1;
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
			{
				a[row][col] = i;
				i++;
			}
		}
		i = 0;
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
			{
				if ((col % 4 == row % 4) || (3 == (col % 4 + row % 4)))
				{
					temparray[i] = a[row][col];
					i++;
				}
			}
		}
		i = N*N / 2 - 1;
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
			{
				if ((col % 4 == row % 4) || (3 == (col % 4 + row % 4)))
				{
					a[row][col] = temparray[i];
					i--;
				}
			}
		}
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
			{
				printf("%5d", a[row][col]);
			}
			printf("\n");
		}
#undef N
}

void MagicSquare3()
{
#define ROW 10
#define COL ROW
	int brr[ROW][COL] = { 0 };
	int k = ROW / 2;
	int row = 0;
	int col = (k - 1) / 2;
	brr[row][col] = 1;
	for (int i = 2; i <= k*k; i++)
	{
		if (row == 0)
		{
			row = k - 1;
		}
		else
		{
			row--;
		}
		col = (col + 1) % k;
		if (brr[row][col] != 0)
		{
			row = (row + 2) % k;
			col = (col - 1 + k) % k;
		}
		brr[row][col] = i;
	}

	for (int row = 0; row < k; row++)
	{
		for (int col = 0; col < k; col++)
		{
			brr[row + k][col + k] = brr[row][col] + k*k;
			brr[row][col + k] = brr[row][col] + 2 * k*k;
			brr[row + k][col] = brr[row][col] + 3 * k*k;
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%5d",brr[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	/*OddMagicSquare();
	MagicSquare4();
	MagicSquare2();
	*/
	MagicSquare3();
	return 0;
}