from collections import Counter  # Import Counter to easily count occurrences of elements

# Define a class to calculate basic statistics
class StatisticsCalculator:
    def __init__(self, data):
        # Store a sorted copy of the data to simplify median and mode calculation
        self.data = sorted(data)

    # Method to calculate the mean (average)
    def mean(self):
        return sum(self.data) / len(self.data)  # Total sum divided by number of elements

    # Method to calculate the median (middle value)
    def median(self):
        n = len(self.data)     # Total number of elements
        mid = n // 2           # Index of the middle element
        if n % 2 == 0:
            # If even, return the average of the two middle numbers
            return (self.data[mid - 1] + self.data[mid]) / 2
        else:
            # If odd, return the middle number
            return self.data[mid]

    # Method to calculate the mode (most frequent value(s))
    def mode(self):
        freq = Counter(self.data)  # Count how many times each number appears
        max_count = max(freq.values())  # Find the highest frequency
        # Return all numbers that appear max_count times (in case of multiple modes)
        return [num for num, count in freq.items() if count == max_count]

# Main block to test the class
if __name__ == "__main__":
    nums = [1, 3, 3, 6, 7, 8, 9]  # Sample dataset
    calc = StatisticsCalculator(nums)  # Create a StatisticsCalculator object with the sample data
    print(f"Mean: {calc.mean():.2f}")    # Print mean rounded to 2 decimal places
    print(f"Median: {calc.median():.2f}")  # Print median rounded to 2 decimal places
    print(f"Mode: {calc.mode()}")       # Print mode as a list
