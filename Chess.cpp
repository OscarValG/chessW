#include <iostream>
#include <vector>

enum PieceType {
  PAWN,
  KNIGHT,
  BISHOP,
  ROOK,
  QUEEN,
  KING
};

struct Piece {
  PieceType type;
  bool isWhite;

  Piece(PieceType type, bool isWhite) : type(type), isWhite(isWhite) {}
};

class ChessBoard {
  std::vector<std::vector<Piece>> board;

public:
  ChessBoard() {
    // Inicializa el tablero de ajedrez vacío
    board.resize(8, std::vector<Piece>(8));
  }

  void movePiece(int fromX, int fromY, int toX, int toY) {
    // Mueve la pieza en (fromX, fromY) a (toX, toY)
    board[toX][toY] = board[fromX][fromY];
    board[fromX][fromY] = Piece(PieceType::PAWN, false);
  }

  bool isCheckmate(bool isWhite) {
    // Verifica si el rey de isWhite está en jaque mate
    // Código omitido por simplicidad
    return false;
  }
};

int main() {
  ChessBoard chessBoard;
  chessBoard.movePiece(1, 1, 2, 2);
  std::cout << (chessBoard.isCheckmate(true) ? "Checkmate!" : "Not in checkmate.") << std::endl;

  return 0;
}