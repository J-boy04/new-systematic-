// main.cpp
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <ctime>  // For random number generation
#include <cstdlib>  // For random number generation

class Person {
private:
    std::string firstName;
    std::string surname;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    Person() : exam(0), finalGrade(0.0) {}
    Person(const std::string& firstName, const std::string& surname)
        : firstName(firstName), surname(surname), exam(0), finalGrade(0.0) {}

    ~Person() {}

    Person& operator=(const Person& other) {
        if (this != &other) {
            firstName = other.firstName;
            surname = other.surname;
            homework = other.homework;
            exam = other.exam;
            finalGrade = other.finalGrade;
        }
        return *this;
    }

    Person(const Person& other) : Person() {
        *this = other;
    }

    void inputData() {
        std::cout << "Enter first name: ";
        std::cin >> firstName;
        std::cout << "Enter surname: ";
        std::cin >> surname;

        int numHomework;
        std::cout << "Enter the number of homework assignments: ";
        std::cin >> numHomework;

        homework.resize(numHomework);
        std::cout << "Enter homework scores:\n";
        for (int i = 0; i < numHomework; ++i) {
            std::cout << "Homework " << i + 1 << ": ";
            std::cin >> homework[i];
        }

        std::cout << "Enter exam score: ";
        std::cin >> exam;
    }

    void outputData(bool useMedian) const {
        std::cout << std::setw(10) << firstName << std::setw(15) << surname;

        if (useMedian) {
            calculateFinalGradeMedian();
            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << finalGrade;
        }
        else {
            calculateFinalGradeAverage();
            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << finalGrade;
        }

        std::cout << std::endl;
    }

    void calculateFinalGradeAverage() const {
        double sum = std::accumulate(homework.begin(), homework.end(), 0.0);
        finalGrade = (sum / homework.size() + exam) / 2.0;
    }

    void calculateFinalGradeMedian() const {
        std::vector<int> allScores = homework;
        allScores.push_back(exam);
        std::sort(allScores.begin(), allScores.end());

        if (allScores.size() % 2 == 0) {
            finalGrade = (allScores[allScores.size() / 2 - 1] + allScores[allScores.size() / 2]) / 2.0;
        }
        else {
            finalGrade = allScores[allScores.size() / 2];
        }
    }
};

// Function to generate random names and surnames
std::string generateRandomName(int index) {
    return "Name" + std::to_string(index + 1);
}

std::string generateRandomSurname(int index) {
    return "Surname" + std::to_string(index + 1);
}

void generateRandomScores(Person& student) {
    int numHomework = rand() % 5 + 5;  // Random number of homework assignments between 5 and 10
    student.homework.resize(numHomework);
    for (int i = 0; i < numHomework; ++i) {
        student.homework[i] = rand() % 11;  // Random homework scores between 0 and 10
    }
    student.exam = rand() % 11;  // Random exam score between 0 and 10
}

void generateRandomStudentList(int numStudents, std::vector<Person>& students) {
    students.clear();
    for (int i = 0; i < numStudents; ++i) {
        Person student(generateRandomName(i), generateRandomSurname(i));
        generateRandomScores(student);
        students.push_back(student);
    }
}

void writeStudentListToFile(const std::string& filename, const std::vector<Person>& students) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& student : students) {
            outputFile << student.outputData(false);  // Output using average
            outputFile << '\n';
        }
        outputFile.close();
    }
    else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}

void readStudentListFromFile(const std::string& filename, std::vector<Person>& students) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        students.clear();
        Person student;
        while (inputFile >> student) {
            students.push_back(student);
        }
        inputFile.close();
    }
    else {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));  // Seed for random number generation

    // Example usage
    const int numStudents = 2;
    std::vector<Person> students;

    // Read data from user input
    for (int i = 0; i < numStudents; ++i) {
        Person student;
        student.inputData();
        students.push_back(student);
    }

    // Output data using average
    std::cout << "Output using Average:\n";
    std::cout << std::setw(10) << "Name" << std::setw(15) << "Surname" << std::setw(20) << "Final (Avg.)\n";
    std::cout << "-----------------------------------------\n";

    for (const auto& student : students) {
        student.outputData(false);
    }

    // Output data using median
    std::cout << "\nOutput using Median:\n";
    std::cout << std::setw(10) << "Name" << std::setw(15) << "Surname" << std::setw(20) << "Final (Med.)\n";
    std::cout << "-----------------------------------------\n";

    for (const auto& student : students) {
        student.outputData(true);
    }

    // Generate random student list and write to file
    const int numRandomStudents = 10000;
    std::vector<Person> randomStudents;
    generateRandomStudentList(numRandomStudents, randomStudents);
    writeStudentListToFile("RandomStudents.txt", randomStudents);

    // Read and output data from file
    std::vector<Person> studentsFromFile;
    readStudentListFromFile("RandomStudents.txt", studentsFromFile);

    // Output data using average
    std::cout << "\nOutput from file using Average:\n";
    std::cout << std::setw(10) << "Name" << std::setw(15) << "Surname" << std::setw(20) << "Final (Avg.)\n";
    std::cout << "-----------------------------------------\n";

    for (const auto& student : studentsFromFile) {
        student.outputData(false);
    }

    // Output data using median
    std::cout << "\nOutput from file using Median:\n";
    std::cout << std::setw(10) << "Name" << std::setw(15) << "Surname" << std::setw(20) << "Final (Med.)\n";
    std::cout << "-----------------------------------------\n";

    for (const auto& student : studentsFromFile) {
        student.outputData(true);
    }

    return 0;
}
