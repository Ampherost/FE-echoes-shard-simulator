#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

int main() {
    // Define the 12 items
    string items[] = {
        "aquarius", "pisces", "aries", "taurus", "gemini",
        "cancer", "leo", "virgo", "libra", "scorpio",
        "saggitarius", "capricorn"
    };

    // Seed the random number generator with the current time
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 11);

    unordered_set<string> collectedItems;
    int numRuns = 0;

    while (collectedItems.size() < 12) {
        // Generate a random index to pick an item
        int randomIndex = dis(gen);

        // Add the item to the set of collected items
        collectedItems.insert(items[randomIndex]);

        numRuns++;
    }

    cout << "It took " << numRuns << " runs to get a full set of items." << endl;

    return 0;
}
