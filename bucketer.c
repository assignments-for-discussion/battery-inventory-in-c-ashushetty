#include <stdio.h>

// Function to calculate SoH
double calculateSoH(double present_capacity, double rated_capacity) {
    return (present_capacity / rated_capacity) * 100;
}

// Function to classify batteries and count them
void classifyBatteries(int num_batteries, double present_capacities[], int *healthy, int *exchange, int *failed) {
    double rated_capacity = 120.0;  // Rated capacity of a new battery

    for (int i = 0; i < num_batteries; i++) {
        double soh = calculateSoH(present_capacities[i], rated_capacity);

        // Classify batteries based on SoH
        if (soh > 80 && soh <= 100) {
            (*healthy)++;
        } else if (soh >= 62 && soh <= 80) {
            (*exchange)++;
        } else {
            (*failed)++;
        }
    }
}

int main() {
    int num_batteries = 6;
    double present_capacities[] = {105.0, 90.0, 75.0, 55.0, 100.0, 70.0};
    int healthy = 0, exchange = 0, failed = 0;

    // Classify batteries
    classifyBatteries(num_batteries, present_capacities, &healthy, &exchange, &failed);

    // Print the counts
    printf("Healthy: %d\n", healthy);
    printf("Exchange: %d\n", exchange);
    printf("Failed: %d\n", failed);

    return 0;
}
