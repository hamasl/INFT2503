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

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = move(piece_from);
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }

    std::string board_to_string() const{
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
        return board;
    }
};

int main() {
    ChessBoard board;

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
    cout << board.board_to_string() << endl;
    board.move_piece("e1", "e2");
    cout << board.board_to_string() << endl;
    board.move_piece("g8", "h6");
    cout << board.board_to_string() << endl;
    board.move_piece("b1", "c3");
    cout << board.board_to_string() << endl;
    board.move_piece("h6", "g8");
    cout << board.board_to_string() << endl;
    board.move_piece("c3", "d5");
    cout << board.board_to_string() << endl;
    board.move_piece("g8", "h6");
    cout << board.board_to_string() << endl;
    board.move_piece("d5", "f6");
    cout << board.board_to_string() << endl;
    board.move_piece("h6", "g8");
    cout << board.board_to_string() << endl;
    board.move_piece("f6", "e8");
    cout << board.board_to_string() << endl;

}
