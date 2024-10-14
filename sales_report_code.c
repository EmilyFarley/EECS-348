#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// Function to read sales data from a file
void read_file(char *filename, float monthly_sales[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: The file '%s' does not exist.\n", filename);
        exit(1); // Exit if file not found
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &monthly_sales[i]);
    }

    fclose(file);
}

// Function to print the monthly sales report
void monthly_sales_report(float monthly_sales[]) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("\nMonthly Sales Report for 2024\n\n");
    printf("%-10s %10s\n", "Month", "Sales");
    
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s %10.2f\n", months[i], monthly_sales[i]);
    }
    printf("\n");
}

// Function to print the sales summary report
void sales_summary_report(float monthly_sales[]) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    float min_sales = monthly_sales[0];
    float max_sales = monthly_sales[0];
    float total_sales = 0.0;
    int min_index = 0, max_index = 0;

    for (int i = 0; i < MONTHS; i++) {
        total_sales += monthly_sales[i];
        if (monthly_sales[i] < min_sales) {
            min_sales = monthly_sales[i];
            min_index = i;
        }
        if (monthly_sales[i] > max_sales) {
            max_sales = monthly_sales[i];
            max_index = i;
        }
    }

    float avg_sales = total_sales / MONTHS;

    printf("Sales summary report:\n\n");
    printf("Minimum sales: %.2f (%s)\n", min_sales, months[min_index]);
    printf("Maximum sales: %.2f (%s)\n", max_sales, months[max_index]);
    printf("Average sales: %.2f\n\n", avg_sales);
}

// Function to print the six-month moving average report
void six_month_moving_average_report(float monthly_sales[]) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Six-Month moving average report:\n\n");
    for (int i = 0; i <= 6; i++) {
        float total = 0.0;
        for (int j = i; j < i + 6; j++) {
            total += monthly_sales[j];
        }
        float average = total / 6;
        printf("%s-%s: %.2f\n", months[i], months[i + 5], average);
    }
    printf("\n");
}

// Function to print the sales report sorted from highest to lowest
void sales_report_highest_to_lowest(float monthly_sales[]) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Create an array of sales and corresponding months
    struct SalesMonth {
        char *month;
        float sales;
    } sales_month_pairs[MONTHS];

    for (int i = 0; i < MONTHS; i++) {
        sales_month_pairs[i].month = months[i];
        sales_month_pairs[i].sales = monthly_sales[i];
    }

    // Sort the sales_month_pairs array in descending order based on sales
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sales_month_pairs[i].sales < sales_month_pairs[j].sales) {
                struct SalesMonth temp = sales_month_pairs[i];
                sales_month_pairs[i] = sales_month_pairs[j];
                sales_month_pairs[j] = temp;
            }
        }
    }

    printf("Sales report (highest to lowest):\n\n");
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; i++) {
        // Adding a dollar sign ($) in front of the sales value
        printf("%-10s $%9.2f\n", sales_month_pairs[i].month, sales_month_pairs[i].sales);
    }
    printf("\n");

}

int main() {
    char filename[100];
    float monthly_sales[MONTHS];

    printf("Enter the name of the file you would like a generated report for: ");
    scanf("%s", filename);

    // Read the sales data
    read_file(filename, monthly_sales);

    // Generate all reports
    monthly_sales_report(monthly_sales);
    sales_summary_report(monthly_sales);
    six_month_moving_average_report(monthly_sales);
    sales_report_highest_to_lowest(monthly_sales);

    return 0;
}
