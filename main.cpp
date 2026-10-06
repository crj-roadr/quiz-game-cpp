#include <iostream>

bool isAnswerCorrect(const std::string& userAnswer, const std::string& correctAnswer) {
    return userAnswer == correctAnswer;
}

int main() {
    std::string questions[] = {"1. How many books are in the Protestant Bible", "2. Who is the messiah in the Bible", "3. How do people obtain salvation?", "4. How many apostles did Jesus have?"};
    constexpr int lengthOfQuestionsArray = sizeof(questions)/sizeof(questions[0]);

    std::string multipleChoices[lengthOfQuestionsArray][4] = {{"66", "76", "81", "24"}, {"Moses", "John The Baptist", "Jesus Christ", "King David"}, {"Through Works", "Through Faith", "Through Prayer", "Through Destiny"}, {"15", "14", "13", "12"}};
    std::string correctAnswers[lengthOfQuestionsArray] = {"66", "Jesus Christ", "Through Faith", "12"};
    std::string userAnswers[lengthOfQuestionsArray];
    int userChoices[lengthOfQuestionsArray];

    int score = 0;

    std::cout << "*** Bible Quiz Game ***" << std::endl;
    std::cout << "\nWelcome to the Bible Quiz Game!\n" << std::endl;

    for (int i = 0; i < lengthOfQuestionsArray; i++) {
        std::cout << questions[i] << std::endl;
        for (int j = 0; j < 4; j++) {
            std::cout << j + 1 << ". " << multipleChoices[i][j] << std::endl;
        }
        std::cout << "Please answer the question by selecting the correct option (1-4): ";
        std::cin >> userChoices[i];
        userChoices[i]--; // Adjust for 0-based index

        // Validate user input
        while (userChoices[i] < 0 || userChoices[i] > 3) {
            std::cout << "Invalid choice. Please select a valid option (1-4): ";
            std::cin >> userChoices[i];
        }

        userAnswers[i] = multipleChoices[i][userChoices[i]];

        if (isAnswerCorrect(userAnswers[i], correctAnswers[i])) {
            std::cout << "Correct!\n" << std::endl;
            score++;
        } else {
            std::cout << "Incorrect. The correct answer is: " << correctAnswers[i] << "\n" << std::endl;
        }
    }
    
    std::cout << "Quiz completed! Your score is: " << score << "/" << lengthOfQuestionsArray << std::endl;

    return 0;
}