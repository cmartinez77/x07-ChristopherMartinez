/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


/*CONSTRUCTER TESTS*/

TEST(TicTacToeBoardTest, constructorInit)
{
	TicTacToeBoard board;
	Piece expected = X;
	Piece actual = board.placePiece(1,1);
	ASSERT_EQ(expected, actual);
}


/*GET PIECE TESTS*/
TEST(TicTacToeBoardTest, boardClear)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.clearBoard();
	Piece actual = board.getPiece(0,0);
	Piece expected = Blank;
	ASSERT_EQ(expected, actual);
}





/*GET PIECE TESTS*/

TEST(TicTacToeBoardTest, emptyGetPiece)
{
	TicTacToeBoard board;
	Piece actual = board.getPiece(0,0);
	Piece expected = Blank;
	ASSERT_EQ(expected, actual);
}

TEST(TicTacToeBoardTest, turnOneGetPiece)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	Piece actual = board.getPiece(0,0);
	Piece expected = Blank;
	ASSERT_EQ(expected, actual);
}

TEST(TicTacToeBoardTest, invalidGetPiece)
{
	TicTacToeBoard board;
	Piece actual = board.getPiece(4,-1);
	Piece expected = Invalid;
	ASSERT_EQ(expected, actual);
}


/*PLACE PIECE TESTS*/

TEST(TicTacToeBoardTest, outOfBoundsOver)
{
	TicTacToeBoard board;
	Piece actual = board.placePiece(4,4);
	Piece expected = Invalid;
	ASSERT_EQ(expected, actual);
}

TEST(TicTacToeBoardTest, outOfBoundsUnder)
{
	TicTacToeBoard board;
	Piece actual = board.placePiece(-1,-1);
	Piece expected = Invalid;
	ASSERT_EQ(expected, actual);
}

TEST(TicTacToeBoardTest, outOfBoundsDifferent)
{
	TicTacToeBoard board;
	Piece actual = board.placePiece(-1,4);
	Piece expected = Invalid;
	ASSERT_EQ(expected, actual);
}

TEST(TicTacToeBoardTest, outOfBoundsDifferentReverse)
{
	TicTacToeBoard board;
	Piece actual = board.placePiece(4,-1);
	Piece expected = Invalid;
	ASSERT_EQ(expected, actual);
}

TEST(TicTacToeBoardTest, inBounds)
{
	TicTacToeBoard board;
	Piece actual = board.placePiece(1,1);
	Piece expected = X;
	ASSERT_EQ(expected, actual);
}


/*INDIRECT TOGGLE TEST*/

TEST(TicTacToeBoardTest, ToggleTurnOne)
{
	TicTacToeBoard board;
	board.placePiece(1,1);
	Piece actual = board.placePiece(0,0);
	Piece expected = O;
	ASSERT_EQ(expected, actual);
}

TEST(TicTacToeBoardTest, ToggleTurnTwo)
{
	TicTacToeBoard board;
	board.placePiece(1,1);
	board.placePiece(0,0);
	Piece actual = board.placePiece(2,2);
	Piece expected = X;
	ASSERT_EQ(expected, actual);
}


/*SANITY CHECK*/

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
