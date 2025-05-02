# Math Quiz Console Application

This is a C++ console-based **Math Quiz Application** designed to help users practice basic arithmetic operations in a game-like format. The application generates math problems based on user-defined settings and evaluates the user's answers in real time.

## Features

- **Customizable Quiz**:
  - Choose the number of questions (1 to 50).
  - Select the difficulty level: Easy, Medium, Hard, or Mix.
  - Choose the operation type: Addition, Subtraction, Multiplication, Division, or Mixed operations.

- **Dynamic Question Generation**:
  - Questions are randomly generated based on the chosen difficulty and operation type.
  
- **Immediate Feedback**:
  - After each answer, the user is notified whether the answer is correct or incorrect.
  - The screen color changes: green for correct, red for incorrect.

- **Performance Summary**:
  - At the end of the quiz, the program displays:
    - The number of right and wrong answers
    - The difficulty and operation type used
    - Whether the user passed or failed the quiz

- **Repeat Option**:
  - Users can choose to take another quiz after finishing one.

## Note
- This program uses Windows-specific commands for clearing the screen and setting console colors, so it may not work as expected on non-Windows systems.
