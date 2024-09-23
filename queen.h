//queen.h
#ifndef QUEEN_H_EXISTS
#define QUEEN_H_EXISTS

class Queen{
	private:
		int row;
		int col;
	public:
		Queen();
		Queen(int row, int col);
		void setRow(int r);
		void setCol(int c);
		int getRow();
		int getCol();
};//end class def 

#endif
