#include <gtk/gtk.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

GtkWidget *entry;

// Callback function for button click
void on_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *current_text = gtk_entry_get_text(GTK_ENTRY(entry));
    gchar *new_text = g_strconcat(current_text, (gchar *)data, NULL);
    gtk_entry_set_text(GTK_ENTRY(entry), new_text);
}

// Function to evaluate a simple arithmetic expression
double evaluate_expression(const gchar *expression) {
    double result = 0.0;
    char operator = 0;
    double current_number = 0.0;
    int position = 0;
    int len = strlen(expression);

    for (int i = 0; i < len; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            current_number = current_number * 10 + (expression[i] - '0');
        } else if (expression[i] == '.') {
            double fraction = 1.0;
            i++;
            while (i < len && expression[i] >= '0' && expression[i] <= '9') {
                fraction /= 10.0;
                current_number += (expression[i] - '0') * fraction;
                i++;
            }
            i--;
        } else if (strchr("+-*/", expression[i])) {
            if (operator) {
                switch (operator) {
                    case '+': result += current_number; break;
                    case '-': result -= current_number; break;
                    case '*': result *= current_number; break;
                    case '/': result /= current_number; break;
                }
            } else {
                result = current_number;
            }
            operator = expression[i];
            current_number = 0.0;
        }
    }

    if (operator) {
        switch (operator) {
            case '+': result += current_number; break;
            case '-': result -= current_number; break;
            case '*': result *= current_number; break;
            case '/': result /= current_number; break;
        }
    } else {
        result = current_number;
    }

    return result;
}

// Function to handle trigonometric functions
double evaluate_trigonometric(const gchar *expression) {
    double result = 0.0;
    if (g_str_has_prefix(expression, "sin")) {
        result = sin(atof(expression + 3));
    } else if (g_str_has_prefix(expression, "cos")) {
        result = cos(atof(expression + 3));
    } else if (g_str_has_prefix(expression, "tan")) {
        result = tan(atof(expression + 3));
    }
    return result;
}

// Callback function for equals button
void on_equals_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *current_text = gtk_entry_get_text(GTK_ENTRY(entry));
    double result = 0.0;

    if (g_str_has_prefix(current_text, "sin") || g_str_has_prefix(current_text, "cos") || g_str_has_prefix(current_text, "tan")) {
        result = evaluate_trigonometric(current_text);
    } else {
        result = evaluate_expression(current_text);
    }

    gchar result_text[32];
    snprintf(result_text, sizeof(result_text), "%lf", result);
    gtk_entry_set_text(GTK_ENTRY(entry), result_text);
}

// Callback function for clear button
void on_clear_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *vbox;

    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Prashant's Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box container
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create the entry widget
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);

    // Create a grid for the buttons
    grid = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    // Button labels
    const char *buttons[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+",
        "C", "sin", "cos", "tan"
    };

    // Attach buttons to the grid
    for (int i = 0; i < 20; i++) {
        button = gtk_button_new_with_label(buttons[i]);
        g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), (gpointer)buttons[i]);
        if (i == 14) { // Equals button
            g_signal_connect(button, "clicked", G_CALLBACK(on_equals_button_clicked), NULL);
        } else if (i == 16) { // Clear button
            g_signal_connect(button, "clicked", G_CALLBACK(on_clear_button_clicked), NULL);
        }
        gtk_grid_attach(GTK_GRID(grid), button, i % 4, i / 4, 1, 1);
    }

    // Show all widgets
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
