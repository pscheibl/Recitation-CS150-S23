## Recitation 3 Algorithm
1. Declare constants for planet weight conversion factors

| Planet  | Factor |
|---------|--------|
| Mercury | 0.4155 |
| Venus   | 0.8975 |
| Earth   | 1.0    |
| Mars    | 0.3507 |
| Jupiter | 2.5374 |
| Saturn  | 1.0677 |
| Uranus  | 0.8947 |
| Neptune | 1.1794 |
| Pluto   | 0.0899 |
2. Declare variables for weights and planet name
3. Prompt user for a weight on Earth
4. Read in weight
5. Prompt user for a planet name
6. Read in planet name
7. normalize planet name to title case
8. Check if the planet name is equal to a known planet. If so, use a conversion factor for that planet to get the new weight, Otherwise, Print an error message and terminate the program.
9. Print the newly converted weight to the console.