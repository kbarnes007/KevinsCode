/*
   Based on a recent exercise for a student I tutored. I've changed the "requirements" 
   to avoid colliding with the other teacher's material.

   Requirements:
       Create a program to grade student tests. The tests are multiple choice, with
	   choices of A, B, C, or D. There are 15 questions on the test, and the student
	   must get 12 correct to pass. 

	   The answer key is:
	   1. B   4. A   7. B   10. D   13. C
	   2. A   5. D   8. A   11. B   14. D
	   3. C   6. B   9. A   12. A   15. C

	   The program should:
	      - ask the user for input
		  - check the answers
		  - display the results
*/

#include <iostream>
using namespace std;

static const int TOTAL_NUM = 15;
static const int PASSING_NUM = 12;

void inputAnswers(char answers[])
{
	for (int i = 0; i < TOTAL_NUM; ++i) {
		bool valid = false;
		do {
			cout << "Enter answer for question " << i + 1 << ": ";
			cin >> answers[i];
			switch (answers[i]) {
			case 'A' : case 'B': case 'C': case 'D': 
				valid = true; 
				break;
			default: 
				cout << "You have entered an invalid grade. Please enter A, B, C, or D" << endl;
				valid = false;
				break;
			} 
		} while (!valid);
		cout << endl;
	}
}

int checkAnswers(char student_answer[])
{
	static const char correct_answer[] = { 'B', 'A', 'C', 'A', 'D', 'B', 'B', 'A', 'A', 'D', 'B', 'A', 'C', 'D', 'C' };
	int numCorrect = 0;
	for (int i = 0; i < TOTAL_NUM; ++i) {
		if (student_answer[i] == correct_answer[i])
			++numCorrect;
		else
			cout << "Answer " << i + 1 << " is incorrect" << endl;
	}
	return numCorrect;
}

void displayResult(int numCorrect) 
{
	cout << "You answered " << numCorrect << " correctly, and " << TOTAL_NUM - numCorrect << " incorrectly. ";
	if (numCorrect >= PASSING_NUM)
		cout << "You passed!";
	else
		cout << "You failed.";
	cout << endl;
}

int main()
{
	char answers[TOTAL_NUM];
	inputAnswers(answers);
	int numCorrect = checkAnswers(answers);
	displayResult(numCorrect);
	return 0;
}

