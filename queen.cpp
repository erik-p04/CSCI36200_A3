#include "queen.h"

Queen::Queen(){
	Queen::row = 0;
	Queen::col = 0;
}//end constructor

Queen::Queen(int r, int c){
	Queen::row = r;
	Queen::col = c;
}

void Queen::setRow(int r){
	Queen::row = r;
}

int Queen::getRow(){
	return Queen::row;
}

void Queen::setCol(int c){
	Queen::col = c;
}

int Queen::getCol(){
	return Queen::col;
}
