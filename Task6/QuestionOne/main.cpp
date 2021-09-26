#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        std::string color_board_representation() const {
            return (color == Color::WHITE) ? "w" : "b";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns how the piece is represented in the board
        virtual std::string board_representation() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    public:
        King(Color color) : Piece(color) {}

        std::string type() const override {
            return Piece::color_string() + " king";
        }

        std::string board_representation() const override {
            return Piece::color_board_representation() + " ki";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            // Standing still is not included as a move
            return std::abs(to_x-from_x) <= 1 && std::abs(to_y-from_y) <= 1 && (from_x != to_x || from_y != to_y );
        }

    };

    class Knight : public Piece {
    public:
        Knight(Color color) : Piece(color) {}

        std::string type() const override {
            return Piece::color_string() + " knight";
        }

        std::string board_representation() const override {
            return Piece::color_board_representation() + " kn";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            // Standing still is not included as a move
            return (std::abs(to_x-from_x) == 2 && std::abs(to_y-from_y) == 1) || (std::abs(to_x-from_x) == 1 && std::abs(to_y-from_y) == 2);
        }
    };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }



  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
  function<void(const Piece &piece, const string &square)> on_piece_removed;
  function<void(string color_string)> on_lost_game;
  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
  function<void(const string &square)> on_piece_move_missing;
  function<void(const vector<vector<unique_ptr<Piece>>> &square)> on_after_piece_move;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    bool return_val = false;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
          if(on_piece_move){
              on_piece_move(*piece_from, from, to);
          }
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {

            if(on_piece_removed){
                on_piece_removed(*piece_to, to);
            }
            if (auto king = dynamic_cast<King *>(piece_to.get())) {
                if (on_lost_game)
                    on_lost_game(king->color_string());
            }
          } else {
            // piece in the from square has the same color as the piece in the to square
              if(on_piece_move_invalid){
                  on_piece_move_invalid(*piece_from, from, to);
              }
            return false;
          }
        }
        piece_to = move(piece_from);
        return true;
      } else {
          if(on_piece_move_invalid){
              on_piece_move_invalid(*piece_from, from, to);
          }
        return false;
      }
    } else {
        if(on_piece_move_missing){
            on_piece_move_missing(from);
        }

      return false;
    }
    //TODO configure return so that it does not return until after this stament
    if(on_after_piece_move){
        on_after_piece_move(squares);
    }
  }

};

class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &board) {
        board.on_lost_game=[](string color_string){
            cout << color_string << " lost the game" << endl;
        };
        board.on_piece_move=[](const ChessBoard::Piece &piece, const string &from, const string &to){
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        board.on_piece_move_invalid=[](const ChessBoard::Piece &piece, const string &from, const string &to){
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        board.on_piece_move_missing=[](const string &square){
            cout << "no piece at " << square << endl;
        };
        board.on_piece_removed=[](const ChessBoard::Piece &piece, const string &square){
            cout << piece.type() << " is being removed from " << square << endl;
        };
        board.on_after_piece_move=[](const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares){
            std::string board = "\n    1    2    3    4    5    6    7    8  ";
            vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
            std::string empty_row = "|    |    |    |    |    |    |    |    |";
            std::string row_divider = "-----------------------------------------";
            for(int i = 0; i < squares.size(); ++i){
                std::string row = empty_row;
                for(int j = 0; j < squares[i].size(); ++j){
                    auto &piece = squares[i][j];
                    if (piece) {
                        row.replace(5*j+1, 4, piece->board_representation());
                    }
                }
                board += "\n  " + row_divider + "\n" + letters[i] + " " + row;
            }
            board += "\n  " + row_divider + "\n";
            cout << board << endl;
        };
    };
private:
    ChessBoard board;

};

int main() {
  ChessBoard board;
  /*ChessBoardPrint chessBoardPrint(
          board,

          );*/

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
