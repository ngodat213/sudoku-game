#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<cmath>
using namespace std;

// VOID FUNCTIONS
void playSudoku();
void exitMenu();
void checkGame();
void upKey();
void downKey();
void leftKey();
void rightKey();
void pauseGame();
void helpSudoku(string located);
void setPuzzle(int level);
void makePuzzle(string target, string puzzle);
void setNumberKey(string value);
void showProgressHardMode(double final_progress);
void hideCursor(bool condition);
void gotoMenu(char choice);
void colorSet(int tint);
void gamePart(string part);
void mainGame();

// OTHER FUNCTIONS
char gameLevel();

// GLOBAL VARIABLES
int level = 0;
int correct = 0;
int sudokuPointer = 0;
int sudokuPuzzleSize;
int sudokuBuildNumber;
double final_progress = 0.0;
string sudokuStatus;
string sudokuPuzzle[81];
string sudokuHighlights[81];
string sudokuSolution[81];

// MAIN PROGRAM
int main(){
	//HIDE CURSOR
	hideCursor(true);
	SetConsoleTitle(("Sudoku"));
	
	//VARIABLE
	int choice;
	
	//DISPLAY
	while(true){
		system("cls");
		colorSet(4); // DARK RED
			gamePart("line_small_left");
		colorSet(15);// WHITE
			cout << "SUDOKU";
		colorSet(4); // DARK RED
			gamePart("line_small_right");
		colorSet(15);// WHITE
			cout << "[1] ";
		colorSet(11);
			cout << "START" << endl;
		colorSet(15);// WHITE
			cout << "[2] ";
		colorSet(14);
			cout << "INSTRUCTIONS" << endl;
		colorSet(15);// WHITE
			cout << "[3] ";
		colorSet(12);// LIGHT RED
			cout << "EXIT" << endl;
		colorSet(4); // DARK RED
			gamePart("seperator");
		colorSet(7); // LIGHT GRAY
			cout << "(Press the number of your choice!)";
		colorSet(15); // WHITE
			
			// GET USER CHOICE
			char select = getch();
			if(!(select < '1' || select > '3')){
				choice = select;
				break;
			}
			
	}
	
	// GOTO MENU OF USER CHOICE
	gotoMenu(choice);
	return 0;
}

// MENU CENTRAL
void gotoMenu(char choice){
	if(choice == '1'){
		playSudoku(); // GO TO PLAY MENU
	}
	else if(choice == '2'){
		helpSudoku("main"); // GO TO INSTRUCTION MENU
	}
	else if(choice == '3'){
		exitMenu(); // GO TO EXIT MENU
	}
}

// PLAY
void playSudoku(){
	// GAME LEVEL
	char setLevel = gameLevel();
	
	// CONDITION LEVEL
	if(setLevel == '4'){
		// GO TO MAIN
		main();
	}else {
		// GAME START
		level = (int)setLevel - 84; //Initialize level
		setPuzzle(level);			//SET LEVEL
		sudokuStatus = "playing";	//SET STATUS
		sudokuPointer = 0;			//RESET POINTER
		checkGame();				//For progress
		mainGame();					//Enter the game
	}
	
	// PAUSE
	getch();
	// GO TO MAIN MENU
	main();
}

char gameLevel(){
	char choice;
	
	//DISPLAY 
	do{
		system("cls");
		colorSet(4); // DARK RED
		colorSet(15);// WHITE
			cout << "SUDOKU";
		colorSet(4); // DARK RED
			gamePart("line_small_right");
		colorSet(13);
			cout << setw(29) << right << "SELECT A DIFFICULTY" << endl;
		colorSet(4); // DARK RED
			gamePart("seperator");
		colorSet(15);// WHITE
			cout << "[1] ";
		colorSet(10);
			cout << "EASY" << endl;
		colorSet(15);// WHITE
			cout << "[2] ";
		colorSet(14);
			cout << "MEDIUM" << endl;
		colorSet(15);// WHITE
			cout << "[3] ";
		colorSet(12);
			cout << "HARD" << endl;
		colorSet(4); // DARK RED
			gamePart("seperator");
		colorSet(15);// WHITE
			cout << "[4] ";
		colorSet(11);
			cout << "BACK" << endl;
		colorSet(4);
			gamePart("seperator");
		colorSet(7);// LIGHT GRAY
			cout << "(Press the munber of your choice!)";
		colorSet(15);// WHITE
			
			// GET USER CHOICE
			char select = getch();
			if(!(select < '1' || select > '4')){
				choice = select;
				break;
			}		
	}while(true);
	
	return choice;
}

void showProgressHardMode(double final_progress){
	if(final_progress >= 69){
		if(final_progress >= 84){
			if(final_progress >= 94){
				cout << "Just a little bit!";
			}else{
				cout << "Almost there!";
			}
		}else{
			cout << "Half-way there!";
		}
	}else{
		cout << "Unfinshed";
	}
}
















