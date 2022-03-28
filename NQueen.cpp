#include<bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 4

vector<int> leftRow(COL);
vector<int> upperDiagonal(2*COL-1);
vector<int> lowerDiagonal(2*COL-1);

/* A utility function to print solution */
void printMatrix(int** board) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

/* A utility function to print solution */
void printBoard(int** board) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if(board[i][j]) {
            	cout << "(" << i << "," << j << ")" << " ";
            }
        }
    }
    cout << endl;
}

bool isQueenSafe(int** board, int row, int col) {
	// Check in same row
	for(int j = 0; j<col; ++j) {
		if(board[row][j]) {
			return false;
		}
	}

	// Check in left upper diagonal
	for(int i = row-1, j = col-1; i>=0 && j>=0; --i,--j) {
		if(board[i][j]) {
			return false;
		}
	}

	// Check in left lower diagonal
	for(int i= row+1, j=col-1;i<ROW && j>=0;++i,--j) {
		if(board[i][j]) {
			return false;
		}
	}
	return true;
}

void printQueen(int** board, int col) {
	if (col == COL) {
		// Print Board
		printBoard(board);
		// clear vectors
		leftRow.clear();upperDiagonal.clear();lowerDiagonal.clear();
		return;
	}
	for(int row = 0; row< ROW; ++row) {
		if (lowerDiagonal[row+col] ==0 && upperDiagonal[row-col + COL-1] == 0 && leftRow[row]==0) {
			board[row][col] = 1;
			lowerDiagonal[row+col] = upperDiagonal[row-col+COL-1] = leftRow[row] = 1;
			printQueen(board, col+1);
			board[row][col] = 0;
			lowerDiagonal[row+col] = upperDiagonal[row-col +COL-1] = leftRow[row] = 0;
		}
	}
}

int main() {

	int **board = new int*[ROW];
	for(int i=0;i<ROW;++i) {
		board[i] = new int[COL];
	}

	for (int i = 0; i < ROW; i++) {
    	for (int j = 0; j < COL; j++) {
            board[i][j] = 0;
        }
    }

    // printMatrix(board);

	// int board[][COL] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	printQueen(board, 0);
}
