#include <stdio.h>
#include <string.h>

// Define the outer structure
struct Student {
    char name[50];
    int age;
    
    // Define a nested structure
    struct Address {
        char city[50];
        int pin;
    } addr;
};

int main() {
    struct Student s1;

    // Assign values to outer structure
    strcpy(s1.name, "John Doe");
    s1.age = 20;

    // Assign values to nested structure
    strcpy(s1.addr.city, "New York");
    s1.addr.pin = 10001;

    // Print values
    printf("Student Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("City: %s\n", s1.addr.city);
    printf("PIN Code: %d\n", s1.addr.pin);

    return 0;
}
