int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1, high = piles[0];
    for (int i = 1; i < pilesSize; i++) {
        if (piles[i] > high) high = piles[i]; // find max pile
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        long long hours = 0;

        for (int i = 0; i < pilesSize; i++) {
            hours += (piles[i] + mid - 1) / mid; // ceil division
        }

        if (hours <= h) {
            high = mid;   // valid speed, try smaller
        } else {
            low = mid + 1; // too slow, increase speed
        }
    }
    return low;
}