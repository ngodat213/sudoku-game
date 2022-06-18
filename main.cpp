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

void makePuzzle(string target, string puzzle){
	//Variable
	char cpuzzle[puzzle.length()];
	int i;
	int pointer = 0;
	//Loop function
	for(i = 0; i < sizeof(cpuzzle); ++i){
		cpuzzle[i] = puzzle[i];
		if(!(cpuzzle[i] == '.' || cpuzzle[i] == '|')){
			string sodokuNumber(1, cpuzzle[i]);
			if(target == "puzzle_layout"){
				sudokuPuzzle[pointer] = sodokuNumber;
			}else if(target == "highlight_layout"){
				sudokuHighlights[pointer] = sodokuNumber;
			}else if(target == "solution_layout"){
				sudokuSolution[i] = sodokuNumber;
			}
			pointer++;
		}
	}
	cout << endl << endl;
}

void mainGame(){
	//-- HEADER --//
	system("cls");
	colorSet(4);
		gamePart("line_small_left");
	colorSet(15);
		cout << "SUDOKU";
	colorSet(4);
		gamePart("line_small_right");
	//// LEVEL AND COLLECT  PARTS ////
	switch(level){
		case 1:
			colorSet(10);
			cout << setw(24) << right << "EASY LEVEL" << endl;
			break;
		case 2:
			colorSet(14);
			cout << setw(25) << right << "MEDIUM LEVEL" << endl;
			break;
		case 3:
			colorSet(12);
			cout << setw(24) << right << "HARD LEVEL" << endl;
			break;
	}
	//////////////////////////////////
	colorSet(4);
		gamePart("seperator");
		cout << endl;
	// -- HEADER -- //
	
	// -- TABLE GENERATOR -- //
	
	///////////////////////////
	// SET COLOR TABLE //
	int colorTable = 5;
	/////////////////////
	
	//IF PLAYER QUITS
	
		//SET SUDOKY PUZZLE SIZE
		sudokuPuzzleSize = (sizeof(sudokuPuzzle) / sizeof(sudokuPuzzle[0]));
		//FETH SOLUTION
		if(sudokuStatus == "quitted"){
			for(int checker = 0; checker < sudokuPuzzleSize; ++checker){
				sudokuPuzzle[checker] = sudokuSolution[checker];
			}
		}
	
	//BUILD SUDOKU TABLE
	sudokuBuildNumber = 0;
	for(int tpart = 1; tpart <= 182; ++tpart){
		if(tpart == 1 || tpart == 62 || tpart == 1 || tpart == 182){
			colorSet(colorTable);
			gamePart("sudoku_outer_border");
		}
		else if(tpart ==   2 || tpart ==   8 || tpart ==  14 || tpart ==  22 || tpart ==  28 || tpart ==  34 || 
				tpart ==  42 || tpart ==  49 || tpart ==  55 || tpart ==  63 || tpart ==  69 || tpart ==  75 ||
			 	tpart ==  83 || tpart ==  89 || tpart ==  95 || tpart == 103 || tpart == 109 || tpart == 115 ||
				tpart == 123 || tpart == 129 || tpart == 135 || tpart == 143 || tpart == 149 || tpart == 155 || 
				tpart == 164 || tpart == 169 || tpart == 175){
			colorSet(colorTable);
			gamePart("sudoku_outer_vertical_border_small");
		}
		//SUDOKU OUTER VERTICAL BORDER WITH NEXT LINE, PART BY PART
		else if(tpart ==  20 || tpart ==  40 || tpart ==  61 || tpart ==  81 || tpart == 101 || tpart == 121 || 
				tpart == 141 || tpart == 161 || tpart == 181){
			colorSet(colorTable);
			gamePart("sudoku_outer_vertical_border_next_line");
		}
		//SUDOKU NUMBER
		else if(tpart ==   3 || tpart ==   5 || tpart ==   7 || tpart ==   9 || tpart ==  11 || tpart ==  13 ||
				tpart ==  15 || tpart ==  17 || tpart ==  19 || tpart ==  23 || tpart ==  25 || tpart ==  27 ||
				tpart ==  29 || tpart ==  31 || tpart ==  33 || tpart ==  35 || tpart ==  37 || tpart ==  39 ||
				tpart ==  43 || tpart ==  45 || tpart ==  47 || tpart ==  50 || tpart ==  52 || tpart ==  54 ||
				tpart ==  56 || tpart ==  58 || tpart ==  60 || tpart ==  64 || tpart ==  66 || tpart ==  68 ||
				tpart ==  70 || tpart ==  72 || tpart ==  74 || tpart ==  76 || tpart ==  78 || tpart ==  80 ||
				tpart ==  84 || tpart ==  86 || tpart ==  88 || tpart ==  90 || tpart ==  92 || tpart ==  94 ||
				tpart ==  96 || tpart ==  98 || tpart == 100 || tpart == 104 || tpart == 106 || tpart == 108 ||
				tpart == 110 || tpart == 112 || tpart == 114 || tpart == 116 || tpart == 118 || tpart == 120 ||
				tpart == 124 || tpart == 126 || tpart == 128 || tpart == 130 || tpart == 132 || tpart == 134 ||
				tpart == 136 || tpart == 138 || tpart == 140 || tpart == 144 || tpart == 146 || tpart == 148 ||
				tpart == 150 || tpart == 152 || tpart == 154 || tpart == 156 || tpart == 158 || tpart == 160 ||
				tpart == 164 || tpart == 166 || tpart == 168 || tpart == 170 || tpart == 172 || tpart == 174 ||
				tpart == 176 || tpart == 178 || tpart == 180){
			colorSer(15);
			
			//COLOR
			if(sudokuHighlights[sudokuBuildNumber] == "0"){
				colorSet(15);
			}else if(sudokuHighlights[sudokuBuildNumber] == "F"){
				colorSet(14);
			}
			
			//DISPLAY POINTER OR NOT
			if(sudokuStatus == "quitted" || sudokuStatus == "finished"){
				//OUTPUT NUMBER
				cout << sudokuPuzzle[sudokuBuildNumber];
			}else{
				//POINTER
				if(sudokuBuildNumber == sudokuPointer){
					colorSet(10);
					if(sudokuHighlights[sudokuPointer] == "F"){
						colorSet(11);
						cout << sudokuPuzzle[sudokuBuildNumber];
					}else{
						if(sudokuPuzzle[sudokuBuildNumber] == "1" || sudokuPuzzle[sudokuBuildNumber] == "2" ||
						   sudokuPuzzle[sudokuBuildNumber] == "2" || sudokuPuzzle[sudokuBuildNumber] == "3" ||
						   sudokuPuzzle[sudokuBuildNumber] == "4" || sudokuPuzzle[sudokuBuildNumber] == "5 ||
						   sudokuPuzzle[sudokuBuildNumber] == "6" || sudokuPuzzle[sudokuBuildNumber] == "7" ||
						   sudokuPuzzle[sudokuBuildNumber] == "8" || sudokuPuzzle[sudokuBuildNumber] == "9"){
							cout << sudokuPuzzle[sudokuBuildNumber];
						}else{
							cout << "x";
						}
					}
				}else{
					//OUTPUT  NUMBER
					cout << sudokuPuzzle[sudokuBuildNumber];
				}
			}
			//ADD
			sudokuBuildNumber++;
		}
		//SUDOKU INNER VERTICAL BORDER, PART BY PART
		
	}
}
















