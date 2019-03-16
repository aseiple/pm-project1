//August Seiple as2813 18003763

#include <iostream>
#include <algorithm>

using namespace std;

void displayMatrix(int** mat, int h, int w);
void displayMatrix(double** mat, int h, int w);
int** createMatrix(int height, int width);
double** createMatrix(double height, double width);
int** addMatrix(int** mat1, int h1, int w1, int** mat2, int h2, int w2);
int** subMatrix(int** mat1, int h1, int w1, int** mat2, int h2, int w2);
int** mulMatrix(int** mat1, int h1, int w1, int** mat2, int h2, int w2);
int detMatrix(int** mat, int h, int w);
int** traMatrix(int** mat, int h, int w);
double** invMatrix(int** mat, int h, int w);

int main()
{
	int h1, w1, h2, w2 = 0;
	cout << "What is the size of your first array? ";
	cin >> h1;
	w1 = h1;
	
	int** mat1 = createMatrix(h1, w1);

	cout << "Here is a refrence for the order the numbers in array 1 should be entered in" << endl;
	int ct = 0;
	int** templateMatrix = createMatrix(h1, w1);
	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w1; j++)
		{
			ct = templateMatrix[i][j];
			ct++;
		}
	}

	displayMatrix(templateMatrix, h1, w1);

	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w1; j++)
		{
			cin >> mat1[i][j];
		}
	}

	cout << "What is the size of your second array? ";
	cin >> h2;
	w2 = h2;

	int** mat2 = createMatrix(h2, w2);

	cout << "Here is a refrence for the order the numbers in array 2 should be entered in" << endl;
	ct = 0;
	templateMatrix = createMatrix(h2, w2);
	for (int i = 0; i < h2; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			ct = templateMatrix[i][j];
			ct++;
		}
	}

	displayMatrix(templateMatrix, h2, w2);

	for (int i = 0; i < h2; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			cin >> mat2[i][j];
		}
	}
	
	
	int choice = 0;
	bool running = true;
	while (running)
	{
		cout << endl << "0. Add arrays A and B" << endl;
		cout << "1. Subtract arrays A and B" << endl;
		cout << "2. Multiply arrays A and B" << endl;
		cout << "3. Find the derterminant of array A" << endl;
		cout << "4. Find the transpose of array A" << endl;
		cout << "5. Find the inverse of array A" << endl;
		cout << "6. Edit array A" << endl;
		cout << "7. Edit array B" << endl;
		cout << "Please enter the number of your operation choice (0-7): ";
		cin >> choice;
		int** out = createMatrix(h1, w1);
		double** doubleout = createMatrix((double)h1, (double)w1);
		int intout = 0;
		cout << endl;
		switch (choice)
		{
		case 0:
			displayMatrix(mat1, h1, w1);
			cout << " + " << endl;
			displayMatrix(mat2, h2, w2);
			out = addMatrix(mat1, h1, w1, mat2, h2, w2);
			cout << "Result:" << endl;
			displayMatrix(out, h1, w1);
			break;
		case 1:
			displayMatrix(mat1, h1, w1);
			cout << " - " << endl;
			displayMatrix(mat2, h2, w2);
			out = subMatrix(mat1, h1, w1, mat2, h2, w2);
			cout << "Result:" << endl;
			displayMatrix(out, h1, w1);
			break;
		case 2:
			displayMatrix(mat1, h1, w1);
			cout << " * " << endl;
			displayMatrix(mat2, h2, w2);
			out = mulMatrix(mat1, h1, w1, mat2, h2, w2);
			cout << "Result:" << endl;
			displayMatrix(out, h1, w1);
			break;
		case 3:
			cout << "Source:" << endl;
			displayMatrix(mat1, h1, w1);
			intout = detMatrix(mat1, h1, w1);
			cout << "Result: " << intout << endl;
			break;
		case 4:
			cout << "Source:" << endl;
			displayMatrix(mat1, h1, w1);
			out = traMatrix(mat1, h1, w1);
			cout << "Result: " << endl;
			displayMatrix(out, w1, h1);
			break;
		case 5:
			cout << "Source:" << endl;
			displayMatrix(mat1, h1, w1);
			doubleout = invMatrix(mat1, h1, w1);
			cout << "Result: " << endl;
			displayMatrix(doubleout, h1, w1);
			break;
		case 6:
			cout << "What is the size of your array? ";
			cin >> h1;
			w2 = h1;

			mat1 = createMatrix(h1, w1);

			cout << "Here is a refrence for the order the numbers in array 2 should be entered in" << endl;
			ct = 0;
			templateMatrix = createMatrix(h1, w1);
			for (int i = 0; i < h1; i++)
			{
				for (int j = 0; j < w1; j++)
				{
					ct = templateMatrix[i][j];
					ct++;
				}
			}
			displayMatrix(templateMatrix, h1, w1);
			for (int i = 0; i < h1; i++)
			{
				for (int j = 0; j < w1; j++)
				{
					cin >> mat1[i][j];
				}
			}
			break;
		case 7:
			cout << "What is the size of your array? ";
			cin >> h2;
			w2 = h2;

			mat2 = createMatrix(h2, w2);

			cout << "Here is a refrence for the order the numbers in array 2 should be entered in" << endl;
			ct = 0;
			templateMatrix = createMatrix(h2, w2);
			for (int i = 0; i < h2; i++)
			{
				for (int j = 0; j < w2; j++)
				{
					ct = templateMatrix[i][j];
					ct++;
				}
			}
			displayMatrix(templateMatrix, h2, w2);
			for (int i = 0; i < h2; i++)
			{
				for (int j = 0; j < w2; j++)
				{
					cin >> mat2[i][j];
				}
			}
			break;
		}

		cout << endl << "0. Perform more operations" << endl << "1. Exit" << endl << "(0/1): ";
		int exit;
		cin >> exit;
		if (exit == 1)
		{
			running = false;
		}
	}
}

int** createMatrix(int height, int width)
{
	int** mat = 0;
	mat = new int* [height];

	for (int h = 0; h < height; h++)
	{
		mat[h] = new int[width];

		for (int w = 0; w < width; w++)
		{
			mat[h][w] = w + width * h;
		}
	}
	
	return mat;
}

double** createMatrix(double height, double width)
{
	double** mat = 0;
	mat = new double* [height];

	for (int h = 0; h < height; h++)
	{
		mat[h] = new double[width];

		for (int w = 0; w < width; w++)
		{
			mat[h][w] = w + width * h;
		}
	}

	return mat;
}

void displayMatrix(int** mat, int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		cout <<  "| ";
		for (int j = 0; j < w; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "|" << endl;
	}
}

void displayMatrix(double** mat, int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		cout << "| ";
		for (int j = 0; j < w; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "|" << endl;
	}
}

int** addMatrix(int** mat1, int h1, int w1, int** mat2, int h2, int w2)
{
	if ((h1 != h2) || (w1 != w2))
	{
		cout << "Not able to preform operation on arrays of different dimensions." << endl;
		return 0;
	}
	else 
	{
		int** result = createMatrix(h1, w1);
		for (int i = 0; i < h1; i++)
		{
			for (int j = 0; j < w1; j++)
			{
				result[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
		return result;
	}
}

int** subMatrix(int** mat1, int h1, int w1, int** mat2, int h2, int w2)
{
	if ((h1 != h2) || (w1 != w2))
	{
		cout << "Not able to preform operation on arrays of different dimensions." << endl;
		return 0;
	}
	else
	{
		int** result = createMatrix(h1, w1);
		for (int i = 0; i < h1; i++)
		{
			for (int j = 0; j < w1; j++)
			{
				result[i][j] = mat1[i][j] - mat2[i][j];
			}
		}
		return result;
	}
}

int** mulMatrix(int** mat1, int h1, int w1, int** mat2, int h2, int w2)
{
	int** result = createMatrix(max(h1, h2), max(w1, w2));
	for (int row = 0; row < w1; row++) {
		for (int col = 0; col < h1; col++) {
			for (int inner = 0; inner < h1-1; inner++) {
				result[row][col] += mat1[row][inner] * mat2[inner][col];
			}
			return result;
		}
	}
}

int detMatrix(int** mat, int h, int w)
{
	int det = 0;
	int** subMat = createMatrix(h, w);
	if (h != w)
	{
		cout << "Not able to preform operation on rectangular arrays.";
		return 0;
	}
	else
	{
		if (h == 2)
		{
			return((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
		}
		else
		{
			for (int i = 0; i < h; i++) {
				int sj = 0;
				for (int j = 1; j < h; j++) {
					int sk = 0;
					for (int k = 0; k < h; k++) {
						if (k == i)
							continue;
						subMat[sj][sk] = mat[j][k];
						sk++;
					}
					sj++;
				}
				det = det + (pow(-1, i) * mat[0][i] * detMatrix(subMat, h - 1, w - 1));
			}
		}
	}
}

int** traMatrix(int** mat, int h, int w)
{
	int** result = createMatrix(w, h);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			result[j][i] = mat[i][j];
		}
	}
	return result;
}

double** invMatrix(int** mat, int h, int w)
{
	double** result = createMatrix((double)h, (double)w);
	int det = detMatrix(mat, h, w);
	if (det == 0)
	{
		cout << "Cannot find inverse of this matrix.";
		return false;
	}

	int** adj = createMatrix(h, w);
	int** temp = createMatrix(h, w);
	int sign = 1;
	if (h == 1)
	{
		adj[0][0] = 1;
	}
	else
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int x = 0, y = 0;
				int** temp = createMatrix(h, w);

				for (int row = 0; row < h; row++)
				{
					for (int col = 0; col < w; col++)
					{
						if (row != i && col != j)
						{
							temp[x][y++] = mat[row][col];

							if (y == h - 1)
							{
								y = 0;
								x++;
							}
						}
					}
				}

				sign = ((i + j) % 2 == 0) ? 1 : -1;
				adj[j][i] = (sign) * (detMatrix(temp, h - 1, w - 1));
			}
		}

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				result[i][j] = adj[i][j] / float(det);

		return result;
	}
}