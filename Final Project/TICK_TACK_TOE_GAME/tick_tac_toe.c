#include <gtk/gtk.h>

// Global variables
GtkWidget *buttons[3][3];
int board[3][3];
int turn = 0;  // 0 for X, 1 for O

// Function prototypes
void reset_game();
void check_winner();

// Callback for button click
void button_clicked(GtkWidget *widget, gpointer data) {
    int row = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "row"));
    int col = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "col"));

    if (board[row][col] == -1) {
        if (turn == 0) {
            gtk_button_set_label(GTK_BUTTON(widget), "X");
            board[row][col] = 0;
        } else {
            gtk_button_set_label(GTK_BUTTON(widget), "O");
            board[row][col] = 1;
        }
        turn = 1 - turn;
        check_winner();
    }
}

// Check for a winner
void check_winner() {
    int winner = -1;

    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != -1 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
        }
        if (board[0][i] != -1 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            winner = board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] != -1 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
    }
    if (board[0][2] != -1 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = board[0][2];
    }

    // Announce the winner
    if (winner != -1) {
        GtkWidget *dialog;
        if (winner == 0) {
            dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "X wins!");
        } else {
            dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "O wins!");
        }
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        reset_game();
    }
}

// Reset the game
void reset_game() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gtk_button_set_label(GTK_BUTTON(buttons[i][j]), "");
            board[i][j] = -1;
        }
    }
    turn = 0;
}

// Main function
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tic-Tac-Toe");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j] = gtk_button_new_with_label("");
            gtk_grid_attach(GTK_GRID(grid), buttons[i][j], j, i, 1, 1);
            g_object_set_data(G_OBJECT(buttons[i][j]), "row", GINT_TO_POINTER(i));
            g_object_set_data(G_OBJECT(buttons[i][j]), "col", GINT_TO_POINTER(j));
            g_signal_connect(buttons[i][j], "clicked", G_CALLBACK(button_clicked), NULL);
            board[i][j] = -1;
        }
    }

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
