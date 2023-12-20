// main.cpp
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cstdlib>

class Person {
private:
    std::string firstName;
    std::string surname;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    // Constructors, methods, and other members (same as before)...

    void calculateFinalGradeAverage() const {
        // Implementation (same as before)...
    }

    void calculateFinalGradeMedian() const {
        // Implementation (same as before)...
    }
};

// Function to generate random names and surnames
std::string generateRandomName(int index) {
    return "Name" + std::to_string(index + 1);
}

std::string generateRandomSurname(int index) {
    return "Surname" + std::to_string(index + 1);
}

// Functions to generate and write random student list
void generateRandomScores(Person& student) {
    // Implementation (same as before)...
}

void generateRandomStudentList(int numStudents, std::vector<Person>& students) {
    // Implementation (same as before)...
}

void writeStudentListToFile(const std::string& filename, const std::vector<Person>& students) {
    // Implementation (same as before)...
}

void readStudentListFromFile(const std::string& filename, std::vector<Person>& students) {
    // Implementation (same as before)...
}

// Function to measure execution time
template <typename Func>
double measureExecutionTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

// Strategies for categorizing students
// Strategy 1
template <typename Container>
void categorizeStudentsStrategy1(const Container& students, Container& passed, Container& failed) {
    // Implementation (same as before)...
}

// Strategy 2
template <typename Container>
void categorizeStudentsStrategy2(Container& students) {
    // Implementation (same as before)...
}

// Function to demonstrate categorization with a specific strategy and container type
template <typename Container>
void demonstrateCategorization(const std::string& strategyName, Container& students) {
    // Implementation (same as before)...
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Example usage
    const int numStudents = 10000;
    std::vector<Person> students;
    generateRandomStudentList(numStudents, students);

    // Demonstrate categorization with Strategy 1 using std::vector
    demonstrateCategorization("Strategy1", students);

    // Demonstrate categorization with Strategy 2 using std::vector
    demonstrateCategorization("Strategy2", students);

    // ... (similar demonstrations for std::list and std::deque)

    return 0;
}

// README.md
# Project Title

## Releases
- [v0.1](link - to - v0.1 - release) : Initial version with basic functionality.
- [v0.2](link - to - v0.2 - release) : Added random student list generation and file operations.
- [v0.25](link - to - v0.25 - release) : Implemented std::list and std::deque containers.
- [v1.0](link - to - v1.0 - release) : Optimized sorting and categorizing using different strategies and algorithms.

## Application Usage Guide
1. Clone the repository : `git clone <repository - url>`
2. Build the project :
-For Unix OS : `make`
- For any OS : `cmake . && make`
3. Run the executable : `. / main`

## Makefile(for Unix OS)
```make
all: main

main : main.cpp
g++ - std = c++11 main.cpp - o main

clean :
rm - f main
