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

void setPuzzle(int level){
	// Varible
	string dot = ".";
	string puzzle, highlight, solution;
	
	// Condition
	
		//EASY
		if(level == 1){
			puzzle = (" .7.8|3.1. | . . " + dot
					+ " .4. | .2.6|5. . " + dot
					+ "6. . |9.4.7|8. .1" + dot
					
					+ "2. . | . . | .4. " + dot
					+ "5. . |7. .1| . .2" + dot
					+ " .1. | . . | . .3" + dot
					
					+ "4. .5| . . | . .9" + dot
					+ " . .1|4.5. | .2. " + dot
					+ " . . | .9.2|4.7. " + dot
					);
		 highlight = ("0.F.F|F.F.0|0.0.0" + dot
		 			+ "0.F.0|0.F.F|F.0.0" + dot
		 			+ "F.0.0|F.F.F|F.0.F" + dot
		 			
		 			+ "F.0.0|0.0.0|0.F.0" + dot
		 			+ "F.0.0|F.0.F|0.0.F" + dot
		 			+ "0.F.0|0.0.0|0.0.F" + dot
		 			
		 			+ "F.0.F|0.0.0|0.0.F" + dot
		 			+ "0.0.F|F.F.0|0.F.0" + dot
		 			+ "0.0.0|0.F.F|F.F.0" + dot
					);
		  solution = ("9.7.8|3.1.5|2.6.4" + dot
		  			+ "1.4.3|8.2.6|5.9.7" + dot
		  			+ "6.5.2|9.4.7|8.3.1" + dot
		  			
		  			+ "2.3.7|5.8.9|1.4.6" + dot
		  			+ "5.6.4|7.3.1|9.8.2" + dot
		  			+ "8.1.9|2.6.4|7.5.3" + dot
		  			
		  			+ "4.2.5|6.7.8|3.1.9" + dot
		  			+ "7.9.1|4.5.3|6.2.8" + dot
		  			+ "3.8.6|1.9.2|4.7.5" + dot
 		  			 );
 		// MEDIUM
		}else if(level == 2){
			puzzle = (" .7.8|3.1. | . . " + dot
					+ " .4. | .2.6|5. . " + dot
					+ "6. . |9.4.7|8. .1" + dot
					
					+ "2. . | . . | .4. " + dot
					+ "5. . |7. .1| . .2" + dot
					+ " .1. | . . | . .3" + dot
					
					+ "4. .5| . . | . .9" + dot
					+ " . .1|4.5. | .2. " + dot
					+ " . . | .9.2|4.7. " + dot
					);
		 highlight = ("0.F.F|F.F.0|0.0.0" + dot
		 			+ "0.F.0|0.F.F|F.0.0" + dot
		 			+ "F.0.0|F.F.F|F.0.F" + dot
		 			
		 			+ "F.0.0|0.0.0|0.F.0" + dot
		 			+ "F.0.0|F.0.F|0.0.F" + dot
		 			+ "0.F.0|0.0.0|0.0.F" + dot
		 			
		 			+ "F.0.F|0.0.0|0.0.F" + dot
		 			+ "0.0.F|F.F.0|0.F.0" + dot
		 			+ "0.0.0|0.F.F|F.F.0" + dot
					);
		  solution = ("9.7.8|3.1.5|2.6.4" + dot
		  			+ "1.4.3|8.2.6|5.9.7" + dot
		  			+ "6.5.2|9.4.7|8.3.1" + dot
		  			
		  			+ "2.3.7|5.8.9|1.4.6" + dot
		  			+ "5.6.4|7.3.1|9.8.2" + dot
		  			+ "8.1.9|2.6.4|7.5.3" + dot
		  			
		  			+ "4.2.5|6.7.8|3.1.9" + dot
		  			+ "7.9.1|4.5.3|6.2.8" + dot
		  			+ "3.8.6|1.9.2|4.7.5" + dot
 		  			 );
 		// HARD
		}else {
			puzzle = (" .7.8|3.1. | . . " + dot
					+ " .4. | .2.6|5. . " + dot
					+ "6. . |9.4.7|8. .1" + dot
					
					+ "2. . | . . | .4. " + dot
					+ "5. . |7. .1| . .2" + dot
					+ " .1. | . . | . .3" + dot
					
					+ "4. .5| . . | . .9" + dot
					+ " . .1|4.5. | .2. " + dot
					+ " . . | .9.2|4.7. " + dot
					);
		 highlight = ("0.F.F|F.F.0|0.0.0" + dot
		 			+ "0.F.0|0.F.F|F.0.0" + dot
		 			+ "F.0.0|F.F.F|F.0.F" + dot
		 			
		 			+ "F.0.0|0.0.0|0.F.0" + dot
		 			+ "F.0.0|F.0.F|0.0.F" + dot
		 			+ "0.F.0|0.0.0|0.0.F" + dot
		 			
		 			+ "F.0.F|0.0.0|0.0.F" + dot
		 			+ "0.0.F|F.F.0|0.F.0" + dot
		 			+ "0.0.0|0.F.F|F.F.0" + dot
					);
		  solution = ("9.7.8|3.1.5|2.6.4" + dot
		  			+ "1.4.3|8.2.6|5.9.7" + dot
		  			+ "6.5.2|9.4.7|8.3.1" + dot
		  			
		  			+ "2.3.7|5.8.9|1.4.6" + dot
		  			+ "5.6.4|7.3.1|9.8.2" + dot
		  			+ "8.1.9|2.6.4|7.5.3" + dot
		  			
		  			+ "4.2.5|6.7.8|3.1.9" + dot
		  			+ "7.9.1|4.5.3|6.2.8" + dot
		  			+ "3.8.6|1.9.2|4.7.5" + dot
 		  			 );
		}
	// CREATE THE PUZZLE
	makePuzzle("puzzle_layout", puzzle);
	makePuzzle("highlight_layout", highlight);
	makePuzzle("solution_layout", solution);
	
}
















