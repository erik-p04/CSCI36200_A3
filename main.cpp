#include <iostream>
#include <stack>
#include <cmath>
#include "queen.h"

// Function to check for conflicts
bool noConf(int r, int c, Queen queens[], int filled){
	for (int i=0; i<filled; i++){
	       //making sure no overlapping queens
	       if (queens[i].getCol() == c || std::abs(queens[i].getRow() - r) == std::abs(queens[i].getCol() - c)){
			return false;
	       }
	}
	return true;
}

void showBoard(Queen queens[], int N){
	bool gotQ;//check if queen is in that spot
	for (int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			gotQ = false;
			for(int k=0; k<N; k++){
				if(queens[k].getRow() == i && queens[k].getCol() == j){
					gotQ = true;
				}
			}
			std::cout << (gotQ ? " Q " : " . ");
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}	

void solve(int N){
	std::stack<Queen> queenStack;
	Queen queens[N];
	//Start at first row and first col
	int row = 0;
	int col = 0;
	//keep track of how many filled rows
	int filled = 0;

	bool keepGoing = true;
	bool placed; //used to check if queen was able to be placed
	while (row < N && keepGoing){
		placed = false;//reset placed indicator
		while (col < N && !placed){
			if (noConf(row, col, queens, filled)){
				//Placing queen
				Queen q(row, col);
				queenStack.push(q);
				queens[filled] = q;
				filled++;
				placed = true; //queen was placed
				showBoard(queens, N);
			}else{
				col++; //try next col
			}
		}

		if(!placed){
			//backtracking
			if(!queenStack.empty()){
				Queen lastQueen = queenStack.top();
				queenStack.pop();
				filled--;
				row = lastQueen.getRow();
				col = lastQueen.getCol() + 1;//shift queen
				showBoard(queens, N);
			}else{
				//stack is empty
				keepGoing = false;
			}
		}else{
			//next row, starting with first col
			row++;
			col = 0;

			if(filled == N){
				std::cout << "Final solution: " << std::endl;
				showBoard(queens, N);
				keepGoing = false;//all queens placed, stop
			}
		}
	}
	//not solution
	if(filled != N){
		std::cout << "All queens cannot be placed without a conflict on a board size of " << N << std::endl;
	}

}

int main(){
	int N;
	bool keepGoing = true;
	while(keepGoing){
		std::cout << "Enter board size greater than 3: " << std::endl;
		std::cin >> N;
		if(N > 3){
			keepGoing = false;
		}
	}
	solve(N);
	return 0;
}
