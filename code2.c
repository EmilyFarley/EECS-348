#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   
#include <string.h>

//converting from celsius to fahrenheit using formula 
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

//converting from fahrenheit to celsius using formula 
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

//converting from celsius to kelvin using formula
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

//converting from kelvin to celsius using formula
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//converting from fahrenheit celsius and then to kelvin using formulas 
float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

//converting from kelvin to celsius and then to fahrenehit using formulas 
float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

//checking temperature in celsius and comparing it to place in a weather temperature category and give its respective message in accordance 
void categorize_temperature(float celsius, const char **category, const char **advisory) {
    if (celsius < 0) {
        *category = "Freezing";
        *advisory = "Put on layers and stay off the roads when possible!";
    } else if (celsius < 10) {
        *category = "Cold";
        *advisory = "Wear a jacket";
    } else if (celsius < 25) {
        *category = "Comfortable";
        *advisory = "You should feel comfortable, enjoy the day!";
    } else if (celsius < 35) {
        *category = "Hot";
        *advisory = "Drink plenty of water and avoid overexertion";
    } else {
        *category = "Extreme Heat";
        *advisory = "Stay indoors and stay cool!";
    }
}

//ensuring a valid input is obtained from the user, prompting them for a temperature until a valid value is provided 
float get_valid_temperature_input(const char *prompt) {
    float value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1) {
            while(getchar() != '\n'); // clear input buffer
            return value;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            while(getchar() != '\n'); // clear input buffer
        }
    }
}

//ensuring a valid scale input is obtained from the user, prompting them until a valid one is provided --giving the options to choose from each time
char get_valid_scale_input(const char *prompt, const char *options) {
    char choice;
    while (1) {
        printf("%s", prompt);
        scanf(" %c", &choice);
        while(getchar() != '\n'); // clear input buffer
        choice = tolower(choice);
        if (strchr(options, choice) != NULL) {
            return choice;
        } else {
            printf("Invalid input. Please choose from %s.\n", options);
        }
    }
}

int main() {
    //header
    printf("Temperature Conversion Utility\n");

    //temperature value from user
    float temp_value = get_valid_temperature_input("Enter the temperature: ");

    //input scale from user
    char scales[] = "123";
    char input_scale = get_valid_scale_input("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ", scales);

    //conversion target scale from user
    char target_scale = get_valid_scale_input("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ", scales);

    //checking is user entered same temperature method from both 
    if (input_scale == target_scale) {
        printf("No conversion necessary. You chose the same scale.\n");
        return 0;
    }

    //performing the conversions according to the input and target scale obtained from user 
    float converted_temp;
    if (input_scale == '1') {
        if (target_scale == '2') {
            converted_temp = celsius_to_fahrenheit(temp_value); //convert celsius to fahrenheit
        } else {
            if (temp_value < -273.15) {
                printf("Error: Invalid temperature. Kelvin cannot be negative.\n"); //ensuring kelvin temp is not negative 
                return 0;
            }
            converted_temp = celsius_to_kelvin(temp_value); //convert celsius to kelvin
        }
    } else if (input_scale == '2') {
        if (target_scale == '1') {
            converted_temp = fahrenheit_to_celsius(temp_value); //convert fahrenheit to celsius
        } else {
            converted_temp = fahrenheit_to_kelvin(temp_value); //convert fahrenheit to kelvin
        }
    } else {
        if (temp_value < 0) {
            printf("Error: Invalid temperature. Kelvin cannot be negative.\n"); //ensuring kelvin is not negative 
            return 0;
        }
        if (target_scale == '1') {
            converted_temp = kelvin_to_celsius(temp_value); //convert kelvin to celsius
        } else {
            converted_temp = kelvin_to_fahrenheit(temp_value); //convert kelvin to fahrenheit 
        }
    }

    //displaying the converted temperature
    if (target_scale == '1') {
        printf("The converted temperature is: %.2f Celsius\n", converted_temp); //print temp in celsius
    } else if (target_scale == '2') {
        printf("The converted temperature is: %.2f Fahrenheit\n", converted_temp); //print temp in fahrenheit
    } else {
        printf("The converted temperature is: %.2f Kelvin\n", converted_temp); //print temp in kelvin
    }

    //categorizing based on Celsius because celsius is always needed for weather advisory check
    float celsius_value;
    if (target_scale == '1') {
        celsius_value = converted_temp;
    } else if (target_scale == '2') {
        celsius_value = fahrenheit_to_celsius(converted_temp); //convert to celsius
    } else {
        celsius_value = kelvin_to_celsius(converted_temp); //convert to celsius
    }

    //get catergory and advisory and print what is needed in respect to them
    const char *category;
    const char *advisory;
    categorize_temperature(celsius_value, &category, &advisory);
    printf("Category: %s\n", category);
    printf("Advisory: %s\n", advisory);

    return 0;
}
