#include <stdio.h>


char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;


void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}


int placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return 1;
    } else {
        return 0;
    }
}


int checkWinner() {
   
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }

  
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }

    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0; 
}


void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

int main() {
    int slot;
    int winner;

    current_marker = 'X';
    current_player = 1;

  
    for (int i = 0; i < 9; i++) {
        printBoard();
        printf("Player %d, chon o (1-9): ", current_player);
        scanf("%d", &slot);

        
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            printf("Vi tri khong hop le, hay chon lai!\n");
            i--;
            continue;
        }

        winner = checkWinner();
        if (winner == 1 || winner == 2) {
            printBoard();
            printf("Player %d chien thang!\n", current_player);
            return 0;
        }

        
        swapPlayerAndMarker();
    }

    
    printBoard();
    printf("Tro choi ket thuc voi ket qua hoa!\n");

    return 0;
}
