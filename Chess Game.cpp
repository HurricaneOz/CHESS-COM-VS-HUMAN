/*

  Chess Game
  Author: Osman Khan
  Chess Pieces Website: https://unicode-table.com/en/sets/chess-symbols/ 
  December 2022
  
*/

#include <iostream>
#include <sstream>
#include <string>
#include <map>

//sets up the board for the beginning
void initizalizeBoard(std::string board[8][8]){
  //names all the pieces
  std::string blackRook = "[♜ ]";
  std::string blackKnight = "[♞ ]";
  std::string blackBishop = "[♝ ]";
  std::string blackQueen = "[♛ ]";
  std::string blackKing = "[♚ ]";
  std::string blackPawn = "[♟ ]";
  std::string whitePawn = "[♙ ]";
  std::string whiteRook = "[♖ ]";
  std::string whiteKnight = "[♘ ]";
  std::string whiteBishop = "[♗ ]";
  std::string whiteQueen = "[♕ ]";
  std::string whiteKing = "[♔ ]";
  
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      board[i][j] = "[  ]";
    }
  }
  //prints out the black pieces;
  board[0][0] = whiteRook;
  board[0][1] = whiteKnight;
  board[0][2] = whiteBishop;
  board[0][3] = whiteQueen;
  board[0][4] = whiteKing;
  board[0][5] = whiteBishop;
  board[0][6] = whiteKnight;
  board[0][7] = whiteRook;
  //prints out the pawns
  for (int i = 0; i < 8; i++){
    board[1][i] = whitePawn;
    board[6][i] = blackPawn;
  }
  //prints out the white pieces
  board[7][0] = blackRook;
  board[7][1] = blackKnight;
  board[7][2] = blackBishop;
  board[7][3] = blackQueen;
  board[7][4] = blackKing;
  board[7][5] = blackBishop;
  board[7][6] = blackKnight;
  board[7][7] = blackRook;
}//end of initialize board

void displayBoard(std::string board[8][8]){
    for (int i = 0; i < 8; i++){
      //printing out the positions of the pieces (alphabets)
      if (i == 0){
        std::cout << "8  ";
      }
      else if (i == 1){
        std::cout << "7  ";
      }
      else if (i == 2){
        std::cout << "6  ";
      }
      else if (i == 3){
        std::cout << "5  ";
      }
      else if (i == 4){
        std::cout << "4  ";
      }
      else if (i == 5){
        std::cout << "3  ";
      }
      else if (i == 6){
        std::cout << "2  ";
      }
      else{
        std::cout << "1  ";
      }
      for (int j = 0; j < 8; j++){
        std::cout << board[i][j];
      }
    std::cout << std::endl;
  }
  //prints out the position of the pieces (numbers)
  std::cout << "   ";
  for (int i = 0; i < 8; i++){
    printf("  %c ", 65+i);
  }
  std::cout << std::endl;
}//end of displayBoard

//used to make a move
void makeMove(std::string board[8][8], std::string wherePiece, std::string movePiece, std::map<std::string,std::string*> &position){
  //used to keep track of if the player enters a valid position or not
  int count = 0;
  //loops through the hash map to see if it's a valid position of a piece and where they move is valid.
  for (auto move : position){
    if (wherePiece == move.first){
      count++;
    }
    else if (movePiece == move.first){
      count++;
    }
  }
  if (count == 2){
    *position[movePiece] = *position[wherePiece];
    *position[wherePiece] = "[  ]";
  }
  else{
    std::cout << "Not a valid move" << std::endl;
  }
}//end of making move;

int main() {
  //the position of where the piece that the player wants to move
  std::string wherePiece = "P";
  //the position of where the player wants the piece to move to
  std::string movePiece = "P";
  //stores the positions of the board used to put into a hashmap
  std::string positions;
  // makes the board that the player will play on
  std::string board[8][8];
  //stores the pieces in what position they are;
  std::map<std::string,std::string*> position;
  // sets the pieces for the board and the empty spaces
  initizalizeBoard(board);
  // displays the board
  displayBoard(board);
  //sets the positions equal to the pieces
  for (int i = 0; i < 8; i++){
    //resets what the postion inserted as the key in the hashmap is going to be
    positions = "";
    for (int j = 0; j < 8; j++){
      //sets the alphabet for the position
      if (j == 0){
        positions = "A";
      }
      else if (j == 1){
        positions = "B";
      }
      else if (j == 2){
        positions = "C";
      }
      else if (j == 3){
        positions = "D";
      }
      else if (j == 4){
        positions = "E";
      }
      else if (j == 5){
        positions = "F";
      }
      else if (j == 6){
        positions = "G";
      }
      else if (j == 7){
        positions = "H";
      }
      //sets the number for the positions
      if (i == 0){
        positions += "8";
      }
      else if (i == 1){
        positions += "7";
      }
      else if (i == 2){
        positions += "6";
      }
      else if (i == 3){
        positions += "5";
      }
      else if (i == 4){
        positions += "4";
      }
      else if (i == 5){
        positions += "3";
      }
      else if (i == 6){
        positions += "2";
      }
      else{
        positions += "1";
      }
      position.insert(std::pair<std::string,std::string*>(positions, &board[i][j]));
    }
  }//end of making the map
  while (wherePiece != "Q"){
    //gets the position of piece you want to move
    std::cout << "Type position of piece you want to move (Type Q to end game): ";
    std::cin >> wherePiece;
    if (wherePiece == "Q"){
      break;
    }
    std::cout << std::endl;
    //gets the position of where you want to move the piece
    std::cout << "Type position of where you want to move the piece: ";
    std::cin >> movePiece;
    std::cout << std::endl;
    //makes the move
    makeMove(board, wherePiece, movePiece, position);
    std::cout << std::endl;
    //displays the move
    displayBoard(board);
  }
  std::cout << std::endl << "Game over!" << std::endl;
}//end of main