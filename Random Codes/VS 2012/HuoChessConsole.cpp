#include "stdafx.h"

using namespace System;
using namespace System::IO;
// UNCOMMENT TO USE THREADS
// using namespace System::Threading;

ref class HuoChess_main {
	public:
		static bool danger_penalty;
		static int Destination_Piece_Value;
        static int Moving_Piece_Value;
	// UNCOMMENT TO SHOW THINKING TIME!
	// (this line, as well the other lines that record that time with the help of variable 'start'...)
	// public: static int start; 

	// the chessboard (=skakiera in Greek)
	static array<String^, 2>^ Skakiera = gcnew array<String^, 2>(8,8);
	static int number_of_moves_analyzed;
	// Variable to note if the computer moves its piece to a square threatened by a pawn
	bool knight_pawn_threat;
	bool bishop_pawn_threat;
	bool rook_pawn_threat;
	bool queen_pawn_threat;
	bool checked_for_pawn_threats;

	// Variable which determines of the program will show the inner
	// thinking process of the AI. Good for educational purposes!!!
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//bool huo_debug;

	// Arrays to use in ComputerMove function
	// Changed in version 0.5
	// Penalty for moving the only piece that defends a square to that square (thus leavind the defender
	// alone in the square he once defended, defenceless!)
	// This penalty is also used to indicate that the computer loses its Queen with the move analyzed
	bool Danger_penalty;
	//bool LoseQueen_penalty;
	// Penalty for moving your piece to a square that the human opponent can hit with more power than the computer.
	bool Attackers_penalty;
	// Penalty if the pieces of the human defending a square in which the computer movies in, have much less
	// value than the pieces the computer has to support the attack on that square
	bool Defenders_value_penalty;

	String^ m_PlayerColor;   
	String^ m_ComputerLevel; 
	String^ m_WhoPlays;      
	String^ m_WhichColorPlays; 
	String^ MovingPiece;      

	// variable to store temporarily the piece that is moving
	String^ ProsorinoKommati; 
	String^ ProsorinoKommati_KingCheck; 

	// variables to check the legality of the move
	static bool exit_elegxos_nomimothtas = false;
	int h;
	int p;
	int how_to_move_Rank;
	int how_to_move_Column;
	int hhh;

	// NEW
	int kopa;
	bool KingCheck;

	// coordinates of the starting square of the move
	String^ m_StartingColumn;
	int m_StartingRank;
	String^ m_FinishingColumn;
	int m_FinishingRank;

	// variable for en passant moves
	bool enpassant_occured;

	// move number
	int Move;

	// variable to show if promotion of a pawn occured
	static bool Promotion_Occured = false;

	// variable to show if castrling occured
	static bool Castling_Occured = false;

	// variables to help find out if it is legal for the computer to perform castling
	static bool White_King_Moved = false;
	static bool Black_King_Moved = false;
	static bool White_Rook_a1_Moved = false;
	static bool White_Rook_h1_Moved = false;
	static bool Black_Rook_a8_Moved = false;
	static bool Black_Rook_h8_Moved = false;
	static bool Can_Castle_Big_White;
	static bool Can_Castle_Big_Black;
	static bool Can_Castle_Small_White;
	static bool Can_Castle_Small_Black;
	
	// variables to show where the kings are in the chessboard
	int WhiteKingColumn;      
    int WhiteKingRank;        
	int BlackKingColumn;      
    int BlackKingRank;        

	// variables to show if king is in check
	bool WhiteKingCheck;
	bool BlackKingCheck;

	// variables to show if there is a possibility for mate
	bool WhiteMate;
	bool BlackMate;
	bool Mate;

	// variable to show if a move is found for the hy to do
	bool Best_Move_Found;

	// variables to help find if a king is under check.
	// (see CheckForWhiteCheck and CheckForBlackCheck functions)
	bool DangerFromRight;
	bool DangerFromLeft;
	bool DangerFromUp;
	bool DangerFromDown;
	bool DangerFromUpRight;
	bool DangerFromDownRight;
	bool DangerFromUpLeft;
	bool DangerFromDownLeft;

	// initial coordinates of the two kings
	// (see CheckForWhiteCheck and CheckForBlackCheck functions)
	int StartingWhiteKingColumn;
	int StartingWhiteKingRank;
	int StartingBlackKingColumn;
	int StartingBlackKingRank;

	// column number inserted by the user
	int m_StartingColumnNumber;
	int m_FinishingColumnNumber;

	///////////////////////////////////////////////////////////////////////////////////////////////////
	// Μεταβλητές για τον έλεγχο της "ορθότητας" και της "νομιμότητας" μιας κίνησης του χρήστη
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// variable for the correctness of the move
	bool m_OrthotitaKinisis;           
	// variable for the legality of the move
	bool m_NomimotitaKinisis;         
	// has the user entered a wrong column?
	bool m_WrongColumn;                

	// variables for 'For' loops
	int i;
	int j;

	int ApophasiXristi;

	//////////////////////////////////////
	// Computer Thought
	//////////////////////////////////////
	// Chessboards used for the computer throught
	static array<String^, 2>^ Skakiera_Move_0 = gcnew array<String^, 2>(8,8);  // Δήλωση πίνακα που αντιπροσωπεύει τη σκακιέρα
	static array<String^, 2>^ Skakiera_Move_After = gcnew array<String^, 2>(8,8);  // Δήλωση πίνακα που αντιπροσωπεύει τη σκακιέρα
	static array<String^, 2>^ Skakiera_Thinking = gcnew array<String^, 2>(8,8);  // Δήλωση πίνακα που χρησιμοποιείται στη σκέψη του υπολογιστή.
	// rest of variables used for computer thought
	double Best_Move_Score;
	double Current_Move_Score;
	int Best_Move_StartingColumnNumber;
	int Best_Move_FinishingColumnNumber;
	int Best_Move_StartingRank;
	int Best_Move_FinishingRank;
	int Move_Analyzed;
	bool Stop_Analyzing;
	int Thinking_Depth;
	int m_StartingColumnNumber_HY;
	int m_FinishingColumnNumber_HY;
	int m_StartingRank_HY;
	int m_FinishingRank_HY;
	bool First_Call;
	String^ Who_Is_Analyzed;
	String^ MovingPiece_HY;

	// for writing the computer move
	String^ HY_Starting_Column_Text;
	String^ HY_Finishing_Column_Text;

	// chessboard to store the chessboard squares where it is dangerous
	// for the HY to move a piece
	// SEE function ComputerMove!
	//static array<String^, 2>^ Skakiera_Dangerous_Squares = gcnew array<String^, 2>(8,8);  // Δήλωση πίνακα που αντιπροσωπεύει τη σκακιέρα

	// variables which help find the best move of the human-opponent
	// during the HY thought analysis
	static array<String^, 2>^ Skakiera_Human_Move_0 = gcnew array<String^, 2>(8,8);
	static array<String^, 2>^ Skakiera_Human_Thinking = gcnew array<String^, 2>(8,8);
	bool First_Call_Human_Thought;

	// 2009 version 1 change
	//int iii_Human;
	//int jjj_Human;

	String^ MovingPiece_Human;
	int m_StartingColumnNumber_Human;
	int m_FinishingColumnNumber_Human;
	int m_StartingRank_Human;
	int m_FinishingRank_Human;
	double Current_Human_Move_Score;
	double Best_Human_Move_Score;
	int Best_Move_Human_StartingColumnNumber;
	int Best_Move_Human_FinishingColumnNumber;
	int Best_Move_Human_StartingRank;
	int Best_Move_Human_FinishingRank;
	bool Best_Human_Move_Found;

	// does the HY eats the queen of his opponent with the move it analyzes?
	// Changed in version 0.5
	bool eat_queen;

	// where the player can perform en passant
	int enpassant_possible_target_rank;
	int enpassant_possible_target_column;

	// is there a possible mate?
	bool Human_is_in_check;
	bool Possible_mate;

	// does the HY moves its King with the move it is analyzing?
	bool moving_the_king;

	int choise_of_user;

	///////////////////////////////////////////////////////////////////////////////////////////////////
	// END OF VARIABLES DECLARATION
	///////////////////////////////////////////////////////////////////////////////////////////////////

void Game() {
	/////////////////////
	// Setup game
	/////////////////////
	Console::Write("Choose color (w/b): ");
	String^ the_choise_of_user = Console::ReadLine();

	if((the_choise_of_user->CompareTo("w") == 0)||(the_choise_of_user->CompareTo("W") == 0))
	{
		m_PlayerColor = "White";
		m_WhoPlays = "Human";
	}
	else if((the_choise_of_user->CompareTo("b") == 0)||(the_choise_of_user->CompareTo("B") == 0))
	{
		m_PlayerColor = "Black";
		m_WhoPlays = "HY";
	}

	/////////////////////////////////////////////////////////////////////////
	// UNCOMMENT THE FOLLOWING TO HAVE MORE THINKING DEPTHS
	// BUT REMEMBER TO ALSO UNCOMMENT ComputerMove4,6,8 functions and
	// the respective part in HumanMove function that calls them!
	/////////////////////////////////////////////////////////////////////////
	// ΠΡΟΣΟΧΗ: Αν βάλω τον υπολογιστή να σκεφτεί σε βάθος 1 κίνησης
	// (ήτοι Thinking_Depth = 0), τότε ΔΕΝ σκέφτεται σωστά! Αυτό συμβαίνει
	// διότι η HumanMove πρέπει να κληθεί τουλάχιστον μία φορά για να
	// ολοκληρωθεί σωστά τουλάχιστον ένας πλήρης κύκλος σκέψης του ΗΥ.
	/////////////////////////////////////////////////////////////////////////
	//Console::Write("Enter level (1-4) : ");
	//choise_of_user = Int32::Parse(Console::ReadLine());

	//switch(choise_of_user)
	//{
	//case 1:
		//m_ComputerLevel = "M";
	//	Thinking_Depth = 2;
	//	break;

	//case 2:
		//m_ComputerLevel = "GM";
	//	Thinking_Depth = 4;
	//	break;

	//case 3:
		//m_ComputerLevel = "World Champion";
	//	Thinking_Depth = 6;
	//	break;

	//case 4:
		//m_ComputerLevel = "Spiros Kakos";
	//	Thinking_Depth = 8;
	//	break;

	        /////////////////////
            // 2009 v4 change
            /////////////////////
            Thinking_Depth = 20;
            /////////////////////
            // 2009 v4 change
            /////////////////////

	//default:
		//m_ComputerLevel = "";
	//	break;
	//};

	////////////////////////////////////////////////////////////
	// SHOW THE INNER THINKING PROCESS OF THE COMPUTER?
	// GOOD FOR EDUCATIONAL PURPOSES!
	// SET huo_debug to TRUE to show inner thinking process!
	////////////////////////////////////////////////////////////
	//Console::Write("Show thinking process (y/n)? ");
	//the_choise_of_user = Console::ReadLine();
	//if((the_choise_of_user->CompareTo("y") == 0)||(the_choise_of_user->CompareTo("Y") == 0))
	//	huo_debug = true;
	//else if((the_choise_of_user->CompareTo("n") == 0)||(the_choise_of_user->CompareTo("N") == 0))
	//	huo_debug = false;

	Console::WriteLine( "\nHuo Chess v0.81 by Spiros I.Kakos (huo) [2009]" );

	// initial values
	White_King_Moved = false;
	Black_King_Moved = false;
	White_Rook_a1_Moved = false;
	White_Rook_h1_Moved = false;
	Black_Rook_a8_Moved = false;
	Black_Rook_h8_Moved = false;
	Can_Castle_Big_White = true;
	Can_Castle_Big_Black = true;
	Can_Castle_Small_White = true;
	Can_Castle_Small_Black = true;
	Move = 0;
	m_WhichColorPlays = "White";

	// fix startup position
	this->Starting_position();

	// if it is the turn of HY to play, then call the respective function
	// to implement HY thought

	bool exit_game = false;

	do
	{

	if ( m_WhoPlays->CompareTo("HY") == 0 )
	{
		// call HY Thought function
		Move = 0;

		if( Move == 0 )
		{
			Console::WriteLine("");
			Console::WriteLine("Thinking...");
		}

		Move_Analyzed = 0;
		Stop_Analyzing = false;
		First_Call = true;
		Best_Move_Found = false;
		Who_Is_Analyzed = "HY";
		ComputerMove(Skakiera);
	}
	else if ( m_WhoPlays->CompareTo("Human") == 0 )
	{
		////////////////////////////
		// Human enters his move
		////////////////////////////
		Console::WriteLine("");
		Console::Write("Starting column (A to H)...");
		m_StartingColumn = Console::ReadLine()->ToUpper();

		Console::Write("Starting rank (1 to 8).....");
		m_StartingRank = Int32::Parse(Console::ReadLine());

		Console::Write("Finishing column (A to H)...");
		m_FinishingColumn = Console::ReadLine()->ToUpper();

		Console::Write("Finishing rank (1 to 8).....");
		m_FinishingRank = Int32::Parse(Console::ReadLine());

		// show the move entered

		String^ Move = String::Concat("Your move: ", m_StartingColumn, m_StartingRank.ToString(), " --> " );
		Move = String::Concat( Move, m_FinishingColumn, m_FinishingRank.ToString() );
		Console::WriteLine( Move );

		//StreamWriter^ huo_sw = gcnew StreamWriter("game.txt", true);
		//huo_sw->WriteLine(Move);
		//huo_sw->Close();

		Console::WriteLine("");
		Console::WriteLine("Thinking...");

		// check the move entered by the human for correctness (='Orthotita' in Greek)
		// and legality (='Nomimotita' in Greek)
		this->Enter_move();
	}

	}while(exit_game == false);

	}



bool CheckForBlackCheck(array<String^, 2>^ BCSkakiera)                    
{      
	// TODO: Add your control notification handler code here

	bool KingCheck;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Εύρεση των συντεταγμένων του βασιλιά.
	// Αν σε κάποιο τετράγωνο βρεθεί ότι υπάρχει ένας βασιλιάς, τότε απλά καταγράφεται η τιμή του εν λόγω
	// τετραγώνου στις αντίστοιχες μεταβλητές που δηλώνουν τη στήλη και τη γραμμή στην οποία υπάρχει μαύρος
	// βασιλιάς.
	// ΠΡΟΣΟΧΗ: Γράφω (i+1) αντί για i και (j+1) αντί για j γιατί το πρώτο στοιχείο του πίνακα BCSkakiera[(8),(8)]
	// είναι το BCSkakiera[(0),(0)] και ΟΧΙ το BCSkakiera[(1),(1)]!
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{

			if (BCSkakiera[(i),(j)]->CompareTo("Black King") == 0)
			{
				BlackKingColumn = (i+1);
				BlackKingRank = (j+1);
			}

		}
	}

	///////////////////////////////////////////////////////////////
	// Έλεγχος του αν ο μαύρος βασιλιάς υφίσταται "σαχ"
	///////////////////////////////////////////////////////////////

	KingCheck = false;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Ελέγχουμε αρχικά αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΤΑ ΔΕΞΙΑ ΤΟΥ. Για να μην βγούμε έξω από τα
	// όρια της BCSkakiera[(8),(8)] έχουμε προσθέσει τον έλεγχο (BlackKingColumn + 1) <= 8 στο "if". Αρχικά ο "κίνδυνος"
	// από τα "δεξιά" είναι υπαρκτός, άρα DangerFromRight = true. Ωστόσο αν βρεθεί ότι στα δεξιά του μαύρου βασι-
	// λιά υπάρχει κάποιο μαύρο κομμάτι, τότε δεν είναι δυνατόν ο εν λόγω βασιλιάς να υφίσταται σαχ από τα δεξιά
	// του (αφού θα "προστατεύεται" από το κομμάτι ιδίου χρώματος), οπότε η DangerFromRight = false και ο έλεγχος
	// για απειλές από τα δεξιά σταματάει (για αυτό και έχω προσθέσει την προϋπόθεση (DangerFromRight == true) στα
	// "if" που κάνουν αυτόν τον έλεγχο).
	// Αν όμως δεν υπάρχει κανένα μαύρο κομμάτι δεξιά του βασιλιά για να τον προστατεύει, τότε συνεχίζει να
	// υπάρχει πιθανότητα να απειλείται ο βασιλιάς από τα δεξιά του, οπότε ο έλεγχος συνεχίζεται.
	// Σημείωση: Ο έλεγχος γίνεται για πιθανό σαχ από πύργο ή βασίλισσα αντίθετου χρώματος.
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromRight = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingColumn + klopa) <= 8) && (DangerFromRight == true) )
	{
		if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Queen") == 0))
			DangerFromRight = false;
		else if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - 1)]->CompareTo("White King") == 0))
			DangerFromRight = false;
	}
	}



	///////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΤΑ ΑΡΙΣΤΕΡΑ ΤΟΥ (από πύργο ή βασίλισσα).
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromLeft = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingColumn - klopa) >= 1) && (DangerFromLeft == true) )
	{
		if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("Black Queen") == 0))
			DangerFromLeft = false;
		else if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - 1)]->CompareTo("White King") == 0))
			DangerFromLeft = false;
	}
	}



	///////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΠΑΝΩ (από πύργο ή βασίλισσα).
	///////////////////////////////////////////////////////////////////////////////////////////////////////


	DangerFromUp = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingRank + klopa) <= 8) && (DangerFromUp == true) )
	{
		if ((BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa- 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa- 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa- 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa- 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa- 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa- 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa- 1)]->CompareTo("Black Queen") == 0))
			DangerFromUp = false;
		else if ((BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank + klopa - 1)]->CompareTo("White King") == 0))
			DangerFromUp = false;
	}
	}



	///////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΚΑΤΩ (από πύργο ή βασίλισσα).
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromDown = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingRank - klopa) >= 1) && (DangerFromDown == true) )
	{
		if ((BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa- 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa- 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa- 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa- 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa- 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa- 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa- 1)]->CompareTo("Black Queen") == 0))
			DangerFromDown = false;
		else if ((BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn - 1),(BlackKingRank - klopa - 1)]->CompareTo("White King") == 0))
			DangerFromDown = false;
	}
	}



	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΠΑΝΩ-ΔΕΞΙΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromUpRight = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingColumn + klopa) <= 8) && ((BlackKingRank + klopa) <= 8) && (DangerFromUpRight == true) )
	{
		if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Queen") == 0))
			DangerFromUpRight = false;
		else if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White King") == 0))
			DangerFromUpRight = false;
	}
	}



	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΚΑΤΩ-ΑΡΙΣΤΕΡΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromDownLeft = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingColumn - klopa) >= 1) && ((BlackKingRank - klopa) >= 1) && (DangerFromDownLeft == true) )
	{
		if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Queen") == 0))
			DangerFromDownLeft = false;
		else if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White King") == 0))
			DangerFromDownLeft = false;
	}
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΚΑΤΩ-ΔΕΞΙΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromDownRight = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingColumn + klopa) <= 8) && ((BlackKingRank - klopa) >= 1) && (DangerFromDownRight == true) )
	{
		if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("Black Queen") == 0))
			DangerFromDownRight = false;
		else if ((BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn + klopa - 1),(BlackKingRank - klopa - 1)]->CompareTo("White King") == 0))
			DangerFromDownRight = false;
	}
	}



	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το μαύρο βασιλιά ΑΠΟ ΠΑΝΩ-ΑΡΙΣΤΕΡΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromUpLeft = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((BlackKingColumn - klopa) >= 1) && ((BlackKingRank + klopa) <= 8) && (DangerFromUpLeft == true) )
	{
		if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Bishop") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Queen") == 0))
			KingCheck = true;
		else if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Pawn") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Rook") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Knight") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Bishop") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("Black Queen") == 0))
			DangerFromUpLeft = false;
		else if ((BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Pawn") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Rook") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White Knight") == 0)||(BCSkakiera[(BlackKingColumn - klopa - 1),(BlackKingRank + klopa - 1)]->CompareTo("White King") == 0))
			DangerFromUpLeft = false;
	}
	}


	//////////////////////////////////////////////////////////////////////////
	// Έλεγχος για το αν ο μαύρος βασιλιάς απειλείται από πιόνι.
	//////////////////////////////////////////////////////////////////////////

	if (((BlackKingColumn + 1) <= 8) && ((BlackKingRank - 1) >= 1))
	{
		if (BCSkakiera[(BlackKingColumn + 1 - 1),(BlackKingRank - 1 - 1)]->CompareTo("White Pawn") == 0)
		{
			KingCheck = true;
		}
	}


	if (((BlackKingColumn - 1) >= 1) && ((BlackKingRank - 1) >= 1))
	{
		if (BCSkakiera[(BlackKingColumn - 1 - 1),(BlackKingRank - 1 - 1)]->CompareTo("White Pawn") == 0) 
		{
			KingCheck = true;
		}
	}


	///////////////////////////////////////////////////////////////////////
	// Έλεγχος για το αν ο μαύρος βασιλιάς απειλείται από ίππο.
	///////////////////////////////////////////////////////////////////////
	
	if (((BlackKingColumn + 1) <= 8) && ((BlackKingRank + 2) <= 8))
		if (BCSkakiera[(BlackKingColumn + 1 - 1),(BlackKingRank + 2 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;
	
	if (((BlackKingColumn + 2) <= 8) && ((BlackKingRank - 1) >= 1))
		if (BCSkakiera[(BlackKingColumn + 2 - 1),(BlackKingRank - 1 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;
	
	if (((BlackKingColumn + 1) <= 8) && ((BlackKingRank - 2) >= 1))
		if (BCSkakiera[(BlackKingColumn + 1 - 1),(BlackKingRank - 2 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;

	if (((BlackKingColumn - 1) >= 1) && ((BlackKingRank - 2) >= 1))
		if (BCSkakiera[(BlackKingColumn - 1 - 1),(BlackKingRank - 2 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;

	if (((BlackKingColumn - 2) >= 1) && ((BlackKingRank - 1) >= 1))
		if (BCSkakiera[(BlackKingColumn - 2 - 1),(BlackKingRank - 1 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;

	if (((BlackKingColumn - 2) >= 1) && ((BlackKingRank + 1) <= 8))
		if (BCSkakiera[(BlackKingColumn - 2 - 1),(BlackKingRank + 1 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;
	
	if (((BlackKingColumn - 1) >= 1) && ((BlackKingRank + 2) <= 8))
		if (BCSkakiera[(BlackKingColumn - 1 - 1),(BlackKingRank + 2 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;

	if (((BlackKingColumn + 2) <= 8) && ((BlackKingRank + 1) <= 8))
		if (BCSkakiera[(BlackKingColumn + 2 - 1),(BlackKingRank + 1 - 1)]->CompareTo("White Knight") == 0)
			KingCheck = true;

	return KingCheck;
	}


		
bool CheckForBlackMate(array<String^, 2>^ BMSkakiera)                   
{														      
	// TODO: Add your control notification handler code here

	bool Mate;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Μεταβλητή που χρησιμεύει στον έλεγχο για το αν υπάρχει ματ (βλ. συναρτήσεις CheckForWhiteMate() και
	// CheckForBlackMate()).
	// Αναλυτικότερα, το πρόγραμμα ελέγχει αν αρχικά υπάρχει σαχ και, αν υπάρχει, ελέγχει αν αυτό το
	// σαχ μπορεί να αποφευχθεί με τη μετακίνηση του υπό απειλή βασιλιά σε κάποιο γειτονικό τετράγωνο.
	// Η μεταβλητή καταγράφει το αν συνεχίζει να υπάρχει πιθανότητα να υπάρχει ματ στη σκακιέρα.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool DangerForMate;

	////////////////////////////////////////////////////////////
	// Έλεγχος του αν υπάρχει "ματ" στον μαύρο βασιλιά
	////////////////////////////////////////////////////////////

	Mate = false;
	DangerForMate = true;    // Αρχικά, προφανώς υπάρχει πιθανότητα να υπάρχει ματ στη σκακιέρα.
	                         // Αν, ωστόσο, κάποια στιγμή βρεθεί ότι αν ο βασιλιάς μπορεί να μετακινηθεί
						     // σε ένα διπλανό τετράγωνο και να πάψει να υφίσταται σαχ, τότε παύει να
							 // υπάρχει πιθανότητα να υπάρχει ματ (προφανώς) και η μεταβλητή παίρνει την
							 // τιμή false.


	//////////////////////////////////////////////////////////////
	// Εύρεση των αρχικών συντεταγμένων του βασιλιά
	//////////////////////////////////////////////////////////////

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			
			if (BMSkakiera[(i),(j)]->CompareTo("Black King") == 0)
			{
				StartingBlackKingColumn = (i+1);
				StartingBlackKingRank = (j+1);
			}

		}
	}


	//////////////////////////////////////////////////
	// Έλεγχος αν ο μαύρος βασιλιάς είναι ματ
	//////////////////////////////////////////////////


	if (m_WhichColorPlays->CompareTo("Black") == 0)
	{

	////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει σαχ αυτή τη στιγμή
	////////////////////////////////////////////////

	BlackKingCheck = CheckForBlackCheck(BMSkakiera);

	if ( BlackKingCheck == false )     // Αν αυτή τη στιγμή δεν υφίσταται σαχ, τότε να μη συνεχιστεί ο έλεγχος
		DangerForMate = false;         // καθώς ΔΕΝ συνεχίζει να υφίσταται πιθανότητα να υπάρχει ματ.

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα πάνω
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingBlackKingRank < 8)
	{
		MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
		ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1 + 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingRank - 1 + 1)<=7) )
	{
	
	// (Προσωρινή) μετακίνηση του βασιλιά προς τα πάνω και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.
	// Ο έλεγχος γίνεται μόνο αν στο τετράγωνο που μετακινείται προσωρινά ο βασιλιάς δεν υπάρχει άλλο κομμάτι
	// του ίδιου χρώματος που να τον εμποδίζει και αν, φυσικά, ο βασιλιάς δεν βγαίνει έξω από τη σκακιέρα με
	// αυτή του την κίνηση και αν, προφανώς, συνεχίζει να υπάρχει πιθανότητα να ύπάρχει ματ (καθώς αν δεν
	// υπάρχει τέτοια πιθανότητα, τότε ο έλεγχος είναι άχρηστος).
		
		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1 + 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1 + 1)] = ProsorinoKommati;

	}

	}

	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα πάνω-δεξιά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingBlackKingColumn < 8)&&(StartingBlackKingRank < 8))
	{

	MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
	ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1 + 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingRank - 1 + 1)<=7)&&((StartingBlackKingColumn - 1 + 1)<=7) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1 + 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1 + 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα δεξιά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingBlackKingColumn < 8)
	{

	MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
	ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingColumn - 1 + 1)<=7) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα κάτω-δεξιά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingBlackKingColumn < 8)&&(StartingBlackKingRank > 1))
	{

	MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
	ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1 - 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingRank - 1 - 1)>=0)&&((StartingBlackKingColumn - 1 + 1)<=7) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1 - 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1 + 1),(StartingBlackKingRank - 1 - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα κάτω
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingBlackKingRank > 1)
	{

	MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
	ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1 - 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingRank - 1 - 1)>=0) )
	{
	
		// (Προσωρινή) μετακίνηση του βασιλιά προς τα πάνω και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.
		
		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1 - 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1 - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα κάτω-αριστερά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingBlackKingColumn > 1)&&(StartingBlackKingRank > 1))
	{

	MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
	ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1 - 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingRank - 1 - 1)>=0)&&((StartingBlackKingColumn - 1 - 1)>=0) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1 - 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1 - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα αριστερά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingBlackKingColumn > 1)
	{

	MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
	ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingColumn - 1 - 1)>=0) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο μαύρος βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα πάνω-αριστερά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingBlackKingColumn > 1)&&(StartingBlackKingRank < 8))
	{

	MovingPiece = BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)];
	ProsorinoKommati = BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1 + 1)];

	if ( (ProsorinoKommati->CompareTo("Black Queen")==1)&&(ProsorinoKommati->CompareTo("Black Rook")==1)&&(ProsorinoKommati->CompareTo("Black Knight")==1)&&(ProsorinoKommati->CompareTo("Black Bishop")==1)&&(ProsorinoKommati->CompareTo("Black Pawn")==1)&&(DangerForMate == true)&&((StartingBlackKingRank - 1 + 1)<=7)&&((StartingBlackKingColumn - 1 - 1)>=0) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = "";
		BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1 + 1)] = MovingPiece;
		BlackKingCheck = CheckForBlackCheck(BMSkakiera);

		if (BlackKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		BMSkakiera[(StartingBlackKingColumn - 1),(StartingBlackKingRank - 1)] = MovingPiece;
		BMSkakiera[(StartingBlackKingColumn - 1 - 1),(StartingBlackKingRank - 1 + 1)] = ProsorinoKommati;

	}

	}

	if (DangerForMate == true)
		Mate = true;

	}

	return Mate;
	}





	
bool CheckForWhiteCheck(array<String^, 2>^ WCSkakiera)               
{
                                       
													          
	// TODO: Add your control notification handler code here

	bool KingCheck;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Εύρεση των συντεταγμένων του βασιλιά.
	// Αν σε κάποιο τετράγωνο βρεθεί ότι υπάρχει ένας βασιλιάς, τότε απλά καταγράφεται η τιμή του εν λόγω
	// τετραγώνου στις αντίστοιχες μεταβλητές που δηλώνουν τη στήλη και τη γραμμή στην οποία υπάρχει λευκός
	// βασιλιάς.
	// ΠΡΟΣΟΧΗ: Γράφω (i+1) αντί για i και (j+1) αντί για j γιατί το πρώτο στοιχείο του πίνακα WCWCSkakiera[(8),(8)]
	// είναι το WCSkakiera[(0),(0)] και ΟΧΙ το WCSkakiera[(1),(1)]!
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			
			if (WCSkakiera[(i),(j)]->CompareTo("White King") == 0)
			{
				WhiteKingColumn = (i+1);
				WhiteKingRank = (j+1);
			}

		}
	}

	///////////////////////////////////////////////////////////////
	// Έλεγχος του αν ο λευκός βασιλιάς υφίσταται "σαχ"
	///////////////////////////////////////////////////////////////

	KingCheck = false;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Ελέγχουμε αρχικά αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΤΑ ΔΕΞΙΑ ΤΟΥ. Για να μην βγούμε έξω από τα
	// όρια της WCSkakiera[(8),(8)] έχουμε προσθέσει τον έλεγχο (WhiteKingColumn + 1) <= 8 στο "if". Αρχικά ο "κίνδυνος"
	// από τα "δεξιά" είναι υπαρκτός, άρα DangerFromRight = true. Ωστόσο αν βρεθεί ότι στα δεξιά του λευκού βασι-
	// λιά υπάρχει κάποιο λευκό κομμάτι, τότε δεν είναι δυνατόν ο εν λόγω βασιλιάς να υφίσταται σαχ από τα δεξιά
	// του (αφού θα "προστατεύεται" από το κομμάτι ιδίου χρώματος), οπότε η DangerFromRight = false και ο έλεγχος
	// για απειλές από τα δεξιά σταματάει (για αυτό και έχω προσθέσει την προϋπόθεση (DangerFromRight == true) στα
	// "if" που κάνουν αυτόν τον έλεγχο).
	// Αν όμως δεν υπάρχει κανένα λευκό κομμάτι δεξιά του βασιλιά για να τον προστατεύει, τότε συνεχίζει να
	// υπάρχει πιθανότητα να απειλείται ο βασιλιάς από τα δεξιά του, οπότε ο έλεγχος συνεχίζεται.
	// Σημείωση: Ο έλεγχος γίνεται για πιθανό σαχ από πύργο ή βασίλισσα αντίθετου χρώματος.
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromRight = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingColumn + klopa) <= 8) && (DangerFromRight == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Queen") == 0))
			DangerFromRight = false;
		else if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black King") == 0))
			DangerFromRight = false;
	}
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΤΑ ΑΡΙΣΤΕΡΑ ΤΟΥ (από πύργο ή βασίλισσα).
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromLeft = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingColumn - klopa) >= 1) && (DangerFromLeft == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("White Queen") == 0))
			DangerFromLeft = false;
		else if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - 1)]->CompareTo("Black King") == 0))
			DangerFromLeft = false;
	}
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΠΑΝΩ (από πύργο ή βασίλισσα).
	///////////////////////////////////////////////////////////////////////////////////////////////////////


	DangerFromUp = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingRank + klopa) <= 8) && (DangerFromUp == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa- 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa- 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa- 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa- 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa- 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa- 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa- 1)]->CompareTo("White Queen") == 0))
			DangerFromUp = false;
		else if ((WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black King") == 0))
			DangerFromUp = false;
	}
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΚΑΤΩ (από πύργο ή βασίλισσα).
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromDown = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingRank - klopa) >= 1) && (DangerFromDown == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa- 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa- 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa- 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa- 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa- 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa- 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa- 1)]->CompareTo("White Queen") == 0))
			DangerFromDown = false;
		else if ((WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black King") == 0))
			DangerFromDown = false;
	}
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΠΑΝΩ-ΔΕΞΙΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromUpRight = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingColumn + klopa) <= 8) && ((WhiteKingRank + klopa) <= 8) && (DangerFromUpRight == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Queen") == 0))
			DangerFromUpRight = false;
		else if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black King") == 0))
			DangerFromUpRight = false;
	}
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΚΑΤΩ-ΑΡΙΣΤΕΡΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromDownLeft = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingColumn - klopa) >= 1) && ((WhiteKingRank - klopa) >= 1) && (DangerFromDownLeft == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Queen") == 0))
			DangerFromDownLeft = false;
		else if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black King") == 0))
			DangerFromDownLeft = false;
	}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΚΑΤΩ-ΔΕΞΙΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromDownRight = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingColumn + klopa) <= 8) && ((WhiteKingRank - klopa) >= 1) && (DangerFromDownRight == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("White Queen") == 0))
			DangerFromDownRight = false;
		else if ((WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn + klopa - 1),(WhiteKingRank - klopa - 1)]->CompareTo("Black King") == 0))
			DangerFromDownRight = false;
	}
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει κίνδυνος για το λευκό βασιλιά ΑΠΟ ΠΑΝΩ-ΑΡΙΣΤΕΡΑ ΤΟΥ (από βασίλισσα ή αξιωματικό).
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DangerFromUpLeft = true;

	for(int klopa = 1; klopa<=7;klopa++)
	{
	if ( ((WhiteKingColumn - klopa) >= 1) && ((WhiteKingRank + klopa) <= 8) && (DangerFromUpLeft == true) )
	{
		if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Queen") == 0))
			KingCheck = true;
		else if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Rook") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Knight") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Bishop") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("White Queen") == 0))
			DangerFromUpLeft = false;
		else if ((WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Pawn") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Rook") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black Knight") == 0)||(WCSkakiera[(WhiteKingColumn - klopa - 1),(WhiteKingRank + klopa - 1)]->CompareTo("Black King") == 0))
			DangerFromUpLeft = false;
	}
	}



	//////////////////////////////////////////////////////////////////////////
	// Έλεγχος για το αν ο λευκός βασιλιάς απειλείται από πιόνι.
	//////////////////////////////////////////////////////////////////////////

	if (((WhiteKingColumn + 1) <= 8) && ((WhiteKingRank + 1) <= 8))
	{
		if (WCSkakiera[(WhiteKingColumn + 1 - 1),(WhiteKingRank + 1 - 1)]->CompareTo("Black Pawn") == 0)
		{
			KingCheck = true;
		}
	}


	if (((WhiteKingColumn - 1) >= 1) && ((WhiteKingRank + 1) <= 8))
	{
		if (WCSkakiera[(WhiteKingColumn - 1 - 1),(WhiteKingRank + 1 - 1)]->CompareTo("Black Pawn") == 0)
		{
			KingCheck = true;
		}
	}


	///////////////////////////////////////////////////////////////////////
	// Έλεγχος για το αν ο λευκός βασιλιάς απειλείται από ίππο.
	///////////////////////////////////////////////////////////////////////
	
	if (((WhiteKingColumn + 1) <= 8) && ((WhiteKingRank + 2) <= 8))
        if (WCSkakiera[(WhiteKingColumn + 1 - 1),(WhiteKingRank + 2 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;
	
	if (((WhiteKingColumn + 2) <= 8) && ((WhiteKingRank - 1) >= 1))
		if (WCSkakiera[(WhiteKingColumn + 2 - 1),(WhiteKingRank - 1 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;
	
	if (((WhiteKingColumn + 1) <= 8) && ((WhiteKingRank - 2) >= 1))
		if (WCSkakiera[(WhiteKingColumn + 1 - 1),(WhiteKingRank - 2 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;

	if (((WhiteKingColumn - 1) >= 1) && ((WhiteKingRank - 2) >= 1))
		if (WCSkakiera[(WhiteKingColumn - 1 - 1),(WhiteKingRank - 2 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;

	if (((WhiteKingColumn - 2) >= 1) && ((WhiteKingRank - 1) >= 1))
		if (WCSkakiera[(WhiteKingColumn - 2 - 1),(WhiteKingRank - 1 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;

	if (((WhiteKingColumn - 2) >= 1) && ((WhiteKingRank + 1) <= 8))
		if (WCSkakiera[(WhiteKingColumn - 2 - 1),(WhiteKingRank + 1 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;

	if (((WhiteKingColumn - 1) >= 1) && ((WhiteKingRank + 2) <= 8))
		if (WCSkakiera[(WhiteKingColumn - 1 - 1),(WhiteKingRank + 2 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;

	if (((WhiteKingColumn + 2) <= 8) && ((WhiteKingRank + 1) <= 8))
		if (WCSkakiera[(WhiteKingColumn + 2 - 1),(WhiteKingRank + 1 - 1)]->CompareTo("Black Knight") == 0)
			KingCheck = true;

	return KingCheck;
	}



	
bool CheckForWhiteMate(array<String^, 2>^ WMSkakiera)                   
	{                         
	// TODO: Add your control notification handler code here

	bool Mate;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Μεταβλητή που χρησιμεύει στον έλεγχο για το αν υπάρχει ματ (βλ. συναρτήσεις CheckForWhiteMate() και
	// CheckForBlackMate()).
	// Αναλυτικότερα, το πρόγραμμα ελέγχει αν αρχικά υπάρχει σαχ και, αν υπάρχει, ελέγχει αν αυτό το
	// σαχ μπορεί να αποφευχθεί με τη μετακίνηση του υπό απειλή βασιλιά σε κάποιο γειτονικό τετράγωνο.
	// Η μεταβλητή καταγράφει το αν συνεχίζει να υπάρχει πιθανότητα να υπάρχει ματ στη σκακιέρα.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool DangerForMate;

	////////////////////////////////////////////////////////////
	// Έλεγχος του αν υπάρχει "ματ" στον λευκό βασιλιά
	////////////////////////////////////////////////////////////

	Mate = false;
	DangerForMate = true;    // Αρχικά, προφανώς υπάρχει πιθανότητα να υπάρχει ματ στη σκακιέρα.
	                         // Αν, ωστόσο, κάποια στιγμή βρεθεί ότι αν ο βασιλιάς μπορεί να μετακινηθεί
						     // σε ένα διπλανό τετράγωνο και να πάψει να υφίσταται σαχ, τότε παύει να
							 // υπάρχει πιθανότητα να υπάρχει ματ (προφανώς) και η μεταβλητή παίρνει την
							 // τιμή false.


	//////////////////////////////////////////////////////////////
	// Εύρεση των αρχικών συντεταγμένων του βασιλιά
	//////////////////////////////////////////////////////////////

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			
			if (WMSkakiera[(i),(j)]->CompareTo("White King") == 0)
			{
				StartingWhiteKingColumn = (i+1);
				StartingWhiteKingRank = (j+1);
			}

		}
	}


	//////////////////////////////////////////////////
	// Έλεγχος αν ο λευκός βασιλιάς είναι ματ
	//////////////////////////////////////////////////


	if (m_WhichColorPlays->CompareTo("White") == 0)
	{

	////////////////////////////////////////////////
	// Έλεγχος αν υπάρχει σαχ αυτή τη στιγμή
	////////////////////////////////////////////////

	WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

	if ( WhiteKingCheck == false )     // Αν αυτή τη στιγμή δεν υφίσταται σαχ, τότε να μη συνεχιστεί ο έλεγχος
		DangerForMate = false;         // καθώς ΔΕΝ συνεχίζει να υφίσταται πιθανότητα να υπάρχει ματ.

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα πάνω
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingWhiteKingRank < 8)
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1 + 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingRank - 1 + 1)<=7) )
	{
	
	// (Προσωρινή) μετακίνηση του βασιλιά προς τα πάνω και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.
	// Ο έλεγχος γίνεται μόνο αν στο τετράγωνο που μετακινείται προσωρινά ο βασιλιάς δεν υπάρχει άλλο κομμάτι
	// του ίδιου χρώματος που να τον εμποδίζει και αν, φυσικά, ο βασιλιάς δεν βγαίνει έξω από τη σκακιέρα με
	// αυτή του την κίνηση και αν, προφανώς, συνεχίζει να υπάρχει πιθανότητα να ύπάρχει ματ (καθώς αν δεν
	// υπάρχει τέτοια πιθανότητα, τότε ο έλεγχος είναι άχρηστος).
		
		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1 + 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1 + 1)] = ProsorinoKommati;

	}

	}

	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα πάνω-δεξιά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingWhiteKingColumn < 8)&&(StartingWhiteKingRank < 8))
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1 + 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingRank - 1 + 1)<=7)&&((StartingWhiteKingColumn - 1 + 1)<=7) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1 + 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1 + 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα δεξιά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingWhiteKingColumn < 8)
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingColumn - 1 + 1)<=7) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα κάτω-δεξιά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingWhiteKingColumn < 8)&&(StartingWhiteKingRank > 1))
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1 - 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingRank - 1 - 1)>=0)&&((StartingWhiteKingColumn - 1 + 1)<=7) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1 - 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1 + 1),(StartingWhiteKingRank - 1 - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα κάτω
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingWhiteKingRank > 1)
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1 - 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingRank - 1 - 1)>=0) )
	{
	
		// (Προσωρινή) μετακίνηση του βασιλιά προς τα πάνω και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.
		
		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1 - 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1 - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα κάτω-αριστερά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingWhiteKingColumn > 1)&&(StartingWhiteKingRank > 1))
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1 - 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingRank - 1 - 1)>=0)&&((StartingWhiteKingColumn - 1 - 1)>=0) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1 - 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1 - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα αριστερά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (StartingWhiteKingColumn > 1)
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingColumn - 1 - 1)>=0) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1)] = ProsorinoKommati;

	}

	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος του αν θα συνεχίσει να υπάρχει σαχ αν ο λευκός βασιλιάς προσπαθήσει να διαφύγει μετακινούμενος
	// προς τα πάνω-αριστερά
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((StartingWhiteKingColumn > 1)&&(StartingWhiteKingRank < 8))
	{

	MovingPiece = WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)];
	ProsorinoKommati = WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1 + 1)];

	if ( (ProsorinoKommati->CompareTo("White Queen")==1)&&(ProsorinoKommati->CompareTo("White Rook")==1)&&(ProsorinoKommati->CompareTo("White Knight")==1)&&(ProsorinoKommati->CompareTo("White Bishop")==1)&&(ProsorinoKommati->CompareTo("White Pawn")==1)&&(DangerForMate == true)&&((StartingWhiteKingRank - 1 + 1)<=7)&&((StartingWhiteKingColumn - 1 - 1)>=0) )
	{
		
		// (Προσωρινή) μετακίνηση του βασιλιά και έλεγχος του αν συνεχίζει τότε να υπάρχει σαχ.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = "";
		WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1 + 1)] = MovingPiece;
		WhiteKingCheck = CheckForWhiteCheck(WMSkakiera);

		if (WhiteKingCheck == false)
			DangerForMate = false;

		// Επαναφορά της σκακιέρας στην κατάσταση στην οποία βρισκόταν πριν μετακινηθεί ο βασιλιάς για τους
		// σκοπούς του ελέγχου.

		WMSkakiera[(StartingWhiteKingColumn - 1),(StartingWhiteKingRank - 1)] = MovingPiece;
		WMSkakiera[(StartingWhiteKingColumn - 1 - 1),(StartingWhiteKingRank - 1 + 1)] = ProsorinoKommati;

	}

	}

	if (DangerForMate == true)
		Mate = true;

	}

	return Mate;
	}


		
void CheckMove(array<String^, 2>^ CMSkakiera)               
	{    
	number_of_moves_analyzed++;

	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("CheckMove called");
	//	Console::ReadKey();
	//}
	// Assign values to m_WhoPlays and m_WrongColumn variables,
	// which are necessary for the proper function of ElegxosNomimotitas and ElegxosOrthotitas
	m_WhoPlays = "Human";
	m_WrongColumn = false;
	MovingPiece = CMSkakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)];

	// Check correctness of move
	m_OrthotitaKinisis = ElegxosOrthotitas(CMSkakiera);
	// if move is correct, then check the legality also
	if( m_OrthotitaKinisis == true )
		m_NomimotitaKinisis = ElegxosNomimotitas(CMSkakiera);

	// restore the normal value of the m_WhoPlays
	m_WhoPlays = "HY";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CHECK FOR MATE
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (((m_OrthotitaKinisis == true)&&(m_NomimotitaKinisis == true))&&(Move_Analyzed == 0))
	{

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// temporarily move the piece to see if the king will continue to be under check
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	CMSkakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = "";
	ProsorinoKommati = CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)];   // Προσωρινή αποθήκευση του
																					 // κομματιού που βρίσκεται στο
	                                                                                 // τετράγωνο προορισμού
	                                                                                 // (βλ. μετά για τη χρησιμότητα
	                                                                                 // του, εκεί που γίνεται έλεγ-
	                                                                                 // χος για το αν συνεχίζει να
	                                                                                 // υφίσταται σαχ).

	CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = MovingPiece;


	//////////////////////////////////////////////////////////////////////////
	// is the king still under check?
	//////////////////////////////////////////////////////////////////////////
	
	WhiteKingCheck = CheckForWhiteCheck(CMSkakiera);

	if ( (m_WhichColorPlays->CompareTo("White") == 0) && (WhiteKingCheck == true) )
	{
		m_NomimotitaKinisis = false;
	}


	///////////////////////////////////////////////////////////////////////////
	// is the black king under check?
	///////////////////////////////////////////////////////////////////////////

	BlackKingCheck = CheckForBlackCheck(CMSkakiera);

	if ( (m_WhichColorPlays->CompareTo("Black") == 0) && (BlackKingCheck == true) )
	{
		m_NomimotitaKinisis = false;
	}


	// restore pieces to their initial positions
	CMSkakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = MovingPiece;
	CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = ProsorinoKommati;

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// end of checking in the king is still under check!
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// restore the normal value of m_WhoPlays
	m_WhoPlays = "HY";


	// check if HY moves the king next to the king of the opponent
	// (this case is not controlled in the lines above)
	if( MovingPiece->CompareTo("White King") == 0 )
	{
		if( ((m_FinishingColumnNumber - 1 + 1) >= 0) && ((m_FinishingColumnNumber - 1 + 1) <= 7) && ((m_FinishingRank - 1 + 1) >= 0) && ((m_FinishingRank - 1 + 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 + 1),(m_FinishingRank - 1 + 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1) >= 0) && ((m_FinishingColumnNumber - 1) <= 7) && ((m_FinishingRank - 1 + 1) >= 0) && ((m_FinishingRank - 1 + 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 + 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 - 1) >= 0) && ((m_FinishingColumnNumber - 1 - 1) <= 7) && ((m_FinishingRank - 1 + 1) >= 0) && ((m_FinishingRank - 1 + 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 - 1),(m_FinishingRank - 1 + 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 - 1) >= 0) && ((m_FinishingColumnNumber - 1 - 1) <= 7) && ((m_FinishingRank - 1) >= 0) && ((m_FinishingRank - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 - 1),(m_FinishingRank - 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 - 1) >= 0) && ((m_FinishingColumnNumber - 1 - 1) <= 7) && ((m_FinishingRank - 1 - 1) >= 0) && ((m_FinishingRank - 1 - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 - 1),(m_FinishingRank - 1 - 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1) >= 0) && ((m_FinishingColumnNumber - 1) <= 7) && ((m_FinishingRank - 1 - 1) >= 0) && ((m_FinishingRank - 1 - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 - 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 + 1) >= 0) && ((m_FinishingColumnNumber - 1 + 1) <= 7) && ((m_FinishingRank - 1 - 1) >= 0) && ((m_FinishingRank - 1 - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 + 1),(m_FinishingRank - 1 - 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 + 1) >= 0) && ((m_FinishingColumnNumber - 1 + 1) <= 7) && ((m_FinishingRank - 1) >= 0) && ((m_FinishingRank - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 + 1),(m_FinishingRank - 1)]->CompareTo("Black King") == 0)
				m_NomimotitaKinisis = false;
		}
	}


	if( MovingPiece->CompareTo("Black King") == 0 )
	{
		if( ((m_FinishingColumnNumber - 1 + 1) >= 0) && ((m_FinishingColumnNumber - 1 + 1) <= 7) && ((m_FinishingRank - 1 + 1) >= 0) && ((m_FinishingRank - 1 + 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 + 1),(m_FinishingRank - 1 + 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1) >= 0) && ((m_FinishingColumnNumber - 1) <= 7) && ((m_FinishingRank - 1 + 1) >= 0) && ((m_FinishingRank - 1 + 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 + 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 - 1) >= 0) && ((m_FinishingColumnNumber - 1 - 1) <= 7) && ((m_FinishingRank - 1 + 1) >= 0) && ((m_FinishingRank - 1 + 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 - 1),(m_FinishingRank - 1 + 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 - 1) >= 0) && ((m_FinishingColumnNumber - 1 - 1) <= 7) && ((m_FinishingRank - 1) >= 0) && ((m_FinishingRank - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 - 1),(m_FinishingRank - 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 - 1) >= 0) && ((m_FinishingColumnNumber - 1 - 1) <= 7) && ((m_FinishingRank - 1 - 1) >= 0) && ((m_FinishingRank - 1 - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 - 1),(m_FinishingRank - 1 - 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1) >= 0) && ((m_FinishingColumnNumber - 1) <= 7) && ((m_FinishingRank - 1 - 1) >= 0) && ((m_FinishingRank - 1 - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 - 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 + 1) >= 0) && ((m_FinishingColumnNumber - 1 + 1) <= 7) && ((m_FinishingRank - 1 - 1) >= 0) && ((m_FinishingRank - 1 - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 + 1),(m_FinishingRank - 1 - 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}

		if( ((m_FinishingColumnNumber - 1 + 1) >= 0) && ((m_FinishingColumnNumber - 1 + 1) <= 7) && ((m_FinishingRank - 1) >= 0) && ((m_FinishingRank - 1) <= 7) )
		{
			if(CMSkakiera[(m_FinishingColumnNumber - 1 + 1),(m_FinishingRank - 1)]->CompareTo("White King") == 0)
				m_NomimotitaKinisis = false;
		}
	}

	
	// if the move under analysis is correct and legal, then do it and measure its score

	if ((m_OrthotitaKinisis == true)&&(m_NomimotitaKinisis == true))
	{
		// temporarily perform the move
		ProsorinoKommati = CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)];
		CMSkakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = "";
		CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = MovingPiece;


		// check is there is a pawn promotion
		if (m_FinishingRank == 8)
		{
			CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = "White Queen";
			Promotion_Occured = true;
		}
		else if (m_FinishingRank == 1)
		{
			CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = "Black Queen";
			Promotion_Occured = true;
		}


		// store the move to ***_HY variables (because after continuous calls of ComputerMove the initial move under analysis will be lost...)
		if ( (Move_Analyzed == 0) && ( ((m_PlayerColor->CompareTo("White") == 0) && ((MovingPiece->CompareTo("Black Pawn") == 0)||(MovingPiece->CompareTo("Black Rook") == 0)||(MovingPiece->CompareTo("Black Knight") == 0)||(MovingPiece->CompareTo("Black Bishop") == 0)||(MovingPiece->CompareTo("Black Queen") == 0)||(MovingPiece->CompareTo("Black King") == 0)))     ||     ((m_PlayerColor->CompareTo("Black") == 0) && ((MovingPiece->CompareTo("White Pawn") == 0)||(MovingPiece->CompareTo("White Rook") == 0)||(MovingPiece->CompareTo("White Knight") == 0)||(MovingPiece->CompareTo("White Bishop") == 0)||(MovingPiece->CompareTo("White Queen") == 0)||(MovingPiece->CompareTo("White King") == 0))) ) )
		{
			// CHECK IF THE COMPUTER MOVES THE PIECE TO A SQUARE THAT IS THREATENED BY A PAWN
			this->rook_pawn_threat = false;
			this->queen_pawn_threat = false;
			this->knight_pawn_threat = false;
			this->bishop_pawn_threat = false;
			this->checked_for_pawn_threats = false;
			CountScore(CMSkakiera);

			// check is HY eats the opponents queen
			// (so it is preferable to do so...)
			// Changed in version 0.5
			if(( ProsorinoKommati->CompareTo("White Queen") == 0) || ( ProsorinoKommati->CompareTo("Black Queen") == 0))
				this->eat_queen = true;
			else
				this->eat_queen = false;

			MovingPiece_HY = MovingPiece;
			m_StartingColumnNumber_HY = m_StartingColumnNumber;
			m_FinishingColumnNumber_HY = m_FinishingColumnNumber;
			m_StartingRank_HY = m_StartingRank;
			m_FinishingRank_HY = m_FinishingRank;
		}

		// if the HY moves its king in the initial moves, then there is a penalty
		if( (MovingPiece_HY->CompareTo("White King") == 0) || (MovingPiece_HY->CompareTo("Black King") == 0) )
			moving_the_king = true;
		else
			moving_the_king = false;

		if ((First_Call == true)&&(Move_Analyzed == this->Thinking_Depth))
		{
			Best_Move_StartingColumnNumber = m_StartingColumnNumber_HY;
			Best_Move_FinishingColumnNumber = m_FinishingColumnNumber_HY;
			Best_Move_StartingRank = m_StartingRank_HY;
			Best_Move_FinishingRank = m_FinishingRank_HY;

			// Measure the move score
			CountScore(CMSkakiera);
			Best_Move_Score = Current_Move_Score;
			
			First_Call = false;
			Best_Move_Found = true;
		}

		if (Move_Analyzed == Thinking_Depth)
		{
		// Measure the move score
		CountScore(CMSkakiera);

		// HUO DEBUG
		// If the computer loses its queen...then penalty!
		//if(this->LoseQueen_penalty == true)
		//{
			//Console::WriteLine("Danger penalty noted!");
		//	if(m_PlayerColor->CompareTo("White") == 0)
		//		Current_Move_Score = Current_Move_Score + 50;
		//	else if(m_PlayerColor->CompareTo("Black") == 0)
		//		Current_Move_Score = Current_Move_Score - 50;
		//}

		// record the score as the best move score, if it is the best
		// move score!
		// HUO DEBUG
		//if(this->LoseQueen_penalty == false)
		//{
		//Console::WriteLine("Checked move...");
		if ( ((m_PlayerColor->CompareTo("Black") == 0)&&(Current_Move_Score > Best_Move_Score)) || ((m_PlayerColor->CompareTo("White") == 0)&&(Current_Move_Score < Best_Move_Score)) )
		{
			// HUO DEBUG
			//StreamWriter^ swer = gcnew StreamWriter("BestMoves.txt",true);
			//swer->WriteLine(String::Concat((m_StartingColumnNumber_HY).ToString(),(m_StartingRank_HY).ToString(),(m_FinishingColumnNumber_HY).ToString(),(m_FinishingRank_HY).ToString(),"  : Best Move Found!"));
			//swer->Close();

			Best_Move_StartingColumnNumber = m_StartingColumnNumber_HY;
			Best_Move_FinishingColumnNumber = m_FinishingColumnNumber_HY;
			Best_Move_StartingRank = m_StartingRank_HY;
			Best_Move_FinishingRank = m_FinishingRank_HY;
			Best_Move_Score = Current_Move_Score;
		}
		else if ( ( Current_Move_Score == Best_Move_Score ) && ( ((m_PlayerColor->CompareTo("White") == 0) && ((MovingPiece->CompareTo("Black Pawn") == 0)||(MovingPiece->CompareTo("Black Rook") == 0)||(MovingPiece->CompareTo("Black Knight") == 0)||(MovingPiece->CompareTo("Black Bishop") == 0)||(MovingPiece->CompareTo("Black Queen") == 0)||(MovingPiece->CompareTo("Black King") == 0)))     ||     ((m_PlayerColor->CompareTo("Black") == 0) && ((MovingPiece->CompareTo("White Pawn") == 0)||(MovingPiece->CompareTo("White Rook") == 0)||(MovingPiece->CompareTo("White Knight") == 0)||(MovingPiece->CompareTo("White Bishop") == 0)||(MovingPiece->CompareTo("White Queen") == 0)||(MovingPiece->CompareTo("White King") == 0))) ) )
		{
			// if score of move analyzed is equal to so-far best move score, then
			// let chance ('Τυχη' in Greek) decide to which move will be kept as best move
			// (target: maximize variety of computer game)
			// REMOVE THIS PART TO MAXIMIZE THE STABILITY OF COMPUTER GAME PLAY
			// Αν το σκορ της κίνησης που αναλύεται είναι ΙΣΟ με το σκορ της έως τώρα καλύτερης κίνησης, τότε
			// αφήνουμε να αποφασίσει η τύχη για το αν η κίνηση αυτή θα αντικαταστήσει την έως τώρα καλύτερη.
			// Στόχος: Η εισαγωγή της ποικιλίας στο παιχνίδι του υπολογιστή.

			Random^ random_number = gcnew Random();
			int Arithmos = random_number->Next(1, 20);

			if (Arithmos > 13)
			{
			Best_Move_StartingColumnNumber = m_StartingColumnNumber_HY;
			Best_Move_FinishingColumnNumber = m_FinishingColumnNumber_HY;
			Best_Move_StartingRank = m_StartingRank_HY;
			Best_Move_FinishingRank = m_FinishingRank_HY;
			Best_Move_Score = Current_Move_Score;
			}
		}
		//}

		////////////////////////////////////////////////////////////////////////
		// restore the pieces to their initial positions
		////////////////////////////////////////////////////////////////////////
		for (i = 0; i <= 7; i++)
		{
			for (j = 0; j <= 7; j++)
			{
				Skakiera[(i),(j)] = Skakiera_Move_0[(i),(j)];
			}
		}

		// restore promoted pawn (if exists)
		if ((m_FinishingRank == 8) && (Promotion_Occured == true))
		{
			CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = "White Pawn";
			Promotion_Occured = false;
		}
		else if ((m_FinishingColumnNumber == 1) && (Promotion_Occured == true))
		{
			CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = "Black Pawn";
			Promotion_Occured = false;
		}

		// restore pieces
		CMSkakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = MovingPiece;
		CMSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = ProsorinoKommati;
		}

	///////////////////////////////////////////////////////////////////////////////////////
	// NOW CHECK FOR POSSIBLE ANSWERS BY THE OPPONENT
	///////////////////////////////////////////////////////////////////////////////////////

	if (Move_Analyzed < Thinking_Depth)
	{
		//////////////////////////////////////////////////////////////
		// is human's king in check?
		//////////////////////////////////////////////////////////////
		Human_is_in_check = false;
		
		WhiteKingCheck = CheckForWhiteCheck(CMSkakiera);
		if ( (this->m_PlayerColor->CompareTo("White") == 0) && (WhiteKingCheck == true) )
			Human_is_in_check = true;

		BlackKingCheck = CheckForBlackCheck(CMSkakiera);
		if ( (this->m_PlayerColor->CompareTo("Black") == 0) && (BlackKingCheck == true) )
			Human_is_in_check = true;

		Move_Analyzed = Move_Analyzed + 1;

		for (i = 0; i <= 7; i++)
		{
			for (j = 0; j <= 7; j++)
			{
				Skakiera_Move_After[(i),(j)] = CMSkakiera[(i),(j)];
			}
		}

		Who_Is_Analyzed = "Human";
		First_Call_Human_Thought = true;
		
		// check human move (to find the best possible answer of the human
		// to the move currently analyzed by the HY Thought process)
		HumanMove(Skakiera_Move_After);
		// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
		//if(huo_debug == true)
		//{
		//	Console::WriteLine("RETURNED TO CheckMove");
		//	Console::ReadKey();
		//}
	}

	} 
	}


		
void ComputerMove(array<String^, 2>^ Skakiera_Thinking_init)              
{   
	// UNCOMMENT TO SHOW THINKING TIME!
	// start = Environment::TickCount;

	// Uncomment to have the program record the start and stop time to a log .txt file
	//StreamWriter^ huo_sw = gcnew StreamWriter("game.txt",true);
	//Console::WriteLine(String::Concat("Started thinking at: ", DateTime::Now.ToString("hh:mm:ss.fffffff")));
	//huo_sw->WriteLine(String::Concat("Started thinking at: ", DateTime::Now.ToString("hh:mm:ss.fffffff")));
	//huo_sw->Close();

	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove called");
	//	Console::ReadKey();
	//}
	// set mate=false, to avoid false alarms for mate.
	// if the program finds out in a next step that mate exists,
	// then it will tell it to you, don't worry! :)
	Mate = false;

	int iii;
	int jjj;

	if (First_Call == true)
	{
			// store the initial position in the chessboard
			for (iii = 0; iii <= 7; iii++)
			{
				for (jjj = 0; jjj <= 7; jjj++)
				{
					Skakiera_Thinking[iii,jjj] = Skakiera_Thinking_init[(iii),(jjj)];
					Skakiera_Move_0[(iii),(jjj)] = Skakiera_Thinking_init[(iii),(jjj)];
				}
			}
	}


	// check is computer has thought as far as the ThinkingDepth dictates
	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;

	////////////////////////////////////////////////////////////////////////
	// CHECK IF POSITION IS IN THE OPENING BOOK
	////////////////////////////////////////////////////////////////////////

	int op_iii;
	int op_jjj;

	int opening = 1;

	bool exit_opening_loop = false;
	// Μεταβλητή που καταδεικνύει το αν υπάρχει ταίριασμα της παρούσας θέσης με κάποια από τις θέσεις που υπάρχουν αποθηκευμένες στο βιβλίο ανοιγμάτων του ΗΥ
	bool match_found;

	String^ line_in_opening_book;

	do
	{
		if( File::Exists(String::Concat("Huo Chess Opening Book\\",opening.ToString(),".txt")) )
		{
			// ’νοιγμα των αρχείων .txt που περιέχει η βάση δεδομένων του ΗΥ
			StreamReader^ sr = gcnew StreamReader(String::Concat("Huo Chess Opening Book\\",opening.ToString(),".txt"));
			match_found = true;

			for (op_iii = 0; op_iii <= 7; op_iii++)
			{
				for (op_jjj = 0; op_jjj <= 7; op_jjj++)
				{
					line_in_opening_book = sr->ReadLine();
					if(Skakiera_Thinking[op_iii,op_jjj]->CompareTo(line_in_opening_book) != 0)
						match_found = false;
				}
			}

			// Αν βρέθηκε μια θέση που είναι αποθηκευμένη στο βιβλίο ανοιγμάτων,
			// τότε διάβασε και τις επόμενες σειρές στο αρχείο text οι οποίες περιέχουν
			// την κίνηση που πρέπει να κάνει ο ΗΥ στην παρούσα θέση.

			if( match_found == true )
			{
				// Αφού βρέθηκε θέση, τότε δεν χρειάζεται περαιτέρω ανάλυση.
				exit_opening_loop = true;

				// Αφού βρέθηκε θέση, τότε ο ΗΥ δεν χρειάζεται να σκεφτεί για την κίνηση του, την έχει βρει έτοιμη!
				Stop_Analyzing = true;

				// Διάβασμα της κενής γραμμής που υπάρχει στο αρχείο.
				line_in_opening_book = sr->ReadLine();

				line_in_opening_book = sr->ReadLine();
				Best_Move_StartingColumnNumber = Int32::Parse(line_in_opening_book);
				line_in_opening_book = sr->ReadLine();
				Best_Move_StartingRank = Int32::Parse(line_in_opening_book);

				line_in_opening_book = sr->ReadLine();
				Best_Move_FinishingColumnNumber = Int32::Parse(line_in_opening_book);
				line_in_opening_book = sr->ReadLine();
				Best_Move_FinishingRank = Int32::Parse(line_in_opening_book);
			}
		}
		else
		{
			exit_opening_loop = true;
		}

		opening = opening + 1;
	}while(exit_opening_loop == false);

	//////////////////////////////////////
	// END OF OPENING BOOK CHECK
	//////////////////////////////////////

	if (Stop_Analyzing == false)
	{
	array<String^, 2>^ Skakiera_Dangerous_Squares = gcnew array<String^, 2>(8,8);
	array<int, 2>^ Number_of_defenders = gcnew array<int,2>(8,8);
	array<int, 2>^ Number_of_attackers = gcnew array<int,2>(8,8);
	array<int, 2>^ Value_of_defenders = gcnew array<int,2>(8,8);
	array<int, 2>^ Value_of_attackers = gcnew array<int,2>(8,8);
	array<int, 2>^ Exception_defender_column = gcnew array<int,2>(8,8);
	array<int, 2>^ Exception_defender_rank = gcnew array<int,2>(8,8); 

	// Scan the chessboard -> if a piece of HY is found -> check all
	// possible destinations in the chessboard -> check correctness of
	// the move analyzed -> check legality of the move analyzed -> if
	// correct and legal, then do the move.
	// NOTE: In all column and rank numbers I add +1, because I must transform
	// them from the 0...7 'measure system' of the chessboard (='Skakiera' in Greek) table
	// to the 1...8 'measure system' of the chessboard.

	// find the dangerous squares in the chessboard, where if the HY
	// moves its piece, will immediately loose it.
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
			Skakiera_Dangerous_Squares[i,j] = "";
		}
	}

	// Changed in version 0.5
	// Initialize variables for finfind the dangerous squares
	for(int di=0;di<=7;di++)
	{
		for(int dj=0;dj<=7;dj++)
		{
			Number_of_attackers[di,dj] = 0;
			Number_of_defenders[di,dj] = 0;
			Value_of_attackers[di,dj] = 0;
			Value_of_defenders[di,dj] = 0;
			Exception_defender_column[di,dj] = -9;
			Exception_defender_rank[di,dj] = -9;
		}
	}

	for (int iii2 = 0; iii2 <= 7; iii2++)
	{
		for (int jjj2 = 0; jjj2 <= 7; jjj2++)
		{
	if ( (( ( ((Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("White King") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("Black King") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking[(iii2),(jjj2)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) )  )
	{
	
	// find squares where the human opponent can hit
		for( int w2=0; w2<=7; w2++)
		{
			for( int r2=0; r2<=7; r2++)
			{
				MovingPiece = Skakiera_Thinking[(iii2),(jjj2)];
				m_StartingColumnNumber = iii2+1;
				m_FinishingColumnNumber = w2+1;
				m_StartingRank = jjj2+1;
				m_FinishingRank = r2+1;

				// check the move
				m_WhoPlays = "Human";
				m_WrongColumn = false;
				m_OrthotitaKinisis = ElegxosOrthotitas(Skakiera_Thinking);
				if( m_OrthotitaKinisis == true )
					m_NomimotitaKinisis = ElegxosNomimotitas(Skakiera_Thinking);
				// restore normal value of m_whoplays
				m_WhoPlays = "HY";
				if(( m_OrthotitaKinisis == true )&&(m_NomimotitaKinisis == true))
				{
					// Another attacker on that square found!
					Number_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Number_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 1;
					Skakiera_Dangerous_Squares[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = "Danger";
					
					//if(Skakiera_Dangerous_Squares[(m_FinishingColumnNumber-1),(m_FinishingRank-1)]->ToString()->Equals("Danger") == true)
					//	Console::WriteLine("Added new dangerous square!");

					// Calculate the value (total value) of the attackers
					if ((MovingPiece->CompareTo("White Rook") == 0)||(MovingPiece->CompareTo("Black Rook") == 0))
						Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 5;
					else if ((MovingPiece->CompareTo("White Bishop") == 0)||(MovingPiece->CompareTo("Black Bishop") == 0))
						Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 3;
					else if ((MovingPiece->CompareTo("White Knight") == 0)||(MovingPiece->CompareTo("Black Knight") == 0))
						Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 3;
					else if ((MovingPiece->CompareTo("White Queen") == 0)||(MovingPiece->CompareTo("Black Queen") == 0))
						Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 9;
					else if ((MovingPiece->CompareTo("White Pawn") == 0)||(MovingPiece->CompareTo("Black Pawn") == 0))
						Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_attackers[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 1;
				}
			}
		}
	}
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////
	// ΑΠΟΘΗΚΕΥΣΗ ΤΩΝ ΕΠΙΚΙΝΔΥΝΩΝ ΤΕΤΡΑΓΩΝΩΝ
	// USE FOR DEBUGGING PURPOSES ONLY!
	//StreamWriter^ srw = gcnew StreamWriter(String::Concat("log1.txt"));
	//srw->WriteLine(String::Concat("Move: ",this->Move.ToString()));
	//srw->WriteLine("*************************************");
	//for (iii = 0; iii <= 7; iii++)
	//{
	//	for (jjj = 0; jjj <= 7; jjj++)
	//	{
	//		if(Skakiera_Dangerous_Squares[(iii),(jjj)]->ToString()->Equals("Danger") == true)
	//			srw->WriteLine(String::Concat(iii.ToString(),jjj.ToString()," DANGER!"));
	//		else if(Skakiera_Dangerous_Squares[(iii),(jjj)]->ToString()->Equals("") == true)
	//			srw->WriteLine(String::Concat(iii.ToString(),jjj.ToString()," No danger...Χαλαρά!"));
	//		else
	//			srw->WriteLine(String::Concat(iii.ToString(),jjj.ToString()));
	//	}
	//}
	//srw->WriteLine("**********************************");
	//srw->Close();
	/////////////////////////////////////////////////////////////////////////////////////////


	// Find squares that are also 'protected' by a piece of the HY.
	// If protected, then the square is not really dangerous

	// Changed in version 0.5
	// Initialize all variables used to find exceptions in the non-dangerous squares.
	// Exceptions definition: If human can hit a square and the computer defends it with its pieces, then the
	// square is not dangerous. However, if the computer has only one (1) piece to defend that square, then
	// it cannot move that specific piece to that square (because then the square would have no defenders and
	// would become again a dangerous square!).

	for (int iii3 = 0; iii3 <= 7; iii3++)
	{
		for (int jjj3 = 0; jjj3 <= 7; jjj3++)
		{
	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("White King") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("Black King") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking[(iii3),(jjj3)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) )
	{
		for( int w1=0; w1<=7; w1++)
		{
			for( int r1=0; r1<=7; r1++)
			{
				MovingPiece = Skakiera_Thinking[(iii3),(jjj3)];
				m_StartingColumnNumber = iii3+1;
				m_FinishingColumnNumber = w1+1;
				m_StartingRank = jjj3+1;
				m_FinishingRank = r1+1;

				// Έλεγχος της κίνησης
				// Απόδοση τιμών στις μεταβλητές m_WhoPlays και m_WrongColumn, οι οποίες είναι απαραίτητες για να λειτουργήσει σωστά οι συναρτήσεις ElegxosNomimotitas και ElegxosOrthotitas
				m_WhoPlays = "Human";
				m_WrongColumn = false;
				m_OrthotitaKinisis = ElegxosOrthotitas(Skakiera_Thinking);
				if( m_OrthotitaKinisis == true )
					m_NomimotitaKinisis = ElegxosNomimotitas(Skakiera_Thinking);

	            // NEW
                // You can count for all moves that "defend" a square,
                // except the move of a pawn forward! :)
                if ((MovingPiece->CompareTo("White Pawn") == 0) || (MovingPiece->CompareTo("Black Pawn") == 0))
                {
                  if (m_FinishingColumnNumber == m_StartingColumnNumber)
                       m_OrthotitaKinisis = false;
                }
                // NEW

				// Επαναφορά της κανονικής τιμής της m_WhoPlays
				m_WhoPlays = "HY";
				if(( m_OrthotitaKinisis == true )&&(m_NomimotitaKinisis == true))
				{
					// Changed in version 0.5
					// A new defender for that square is found!
					Number_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Number_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 1;
					
					// Calculate the value (total value) of the defenders
					if ((MovingPiece->CompareTo("White Rook") == 0)||(MovingPiece->CompareTo("Black Rook") == 0))
						Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 5;
					else if ((MovingPiece->CompareTo("White Bishop") == 0)||(MovingPiece->CompareTo("Black Bishop") == 0))
						Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 3;
					else if ((MovingPiece->CompareTo("White Knight") == 0)||(MovingPiece->CompareTo("Black Knight") == 0))
						Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 3;
					else if ((MovingPiece->CompareTo("White Queen") == 0)||(MovingPiece->CompareTo("Black Queen") == 0))
						Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 9;
					else if ((MovingPiece->CompareTo("White Pawn") == 0)||(MovingPiece->CompareTo("Black Pawn") == 0))
						Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = Value_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] + 1;

					// Record the coordinates of the defender.
					// If the defender found is the only one, then that defender cannot move to that square,
					// since then the square would be again dangerous (since its only defender would have moved into it!)
					// If more than one defenders is found, then no exceptions exist.
					if( Number_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] == 1 )
					{
					Exception_defender_column[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = (m_StartingColumnNumber - 1);
					Exception_defender_rank[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = (m_StartingRank - 1);	
					}
					// PLAYING: Change 1 to 2 ???
					if( Number_of_defenders[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] > 1 )
					{
					Exception_defender_column[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = -99;
					Exception_defender_rank[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = -99;	
					}
					
					//if(Skakiera_Dangerous_Squares[(m_FinishingColumnNumber-1),(m_FinishingRank-1)]->CompareTo("Danger")==0)
					//{
					//	Skakiera_Dangerous_Squares[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] = "";				
					//}
				}
			}
		}
	}
		}
	}
	///////////////////////////////////////////////////////////////
	//***********************************************************//
	///////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////////
	// ΑΠΟΘΗΚΕΥΣΗ ΤΩΝ ΕΠΙΚΙΝΔΥΝΩΝ ΤΕΤΡΑΓΩΝΩΝ
	// USE FOR DEBUGGING PURPOSES ONLY!
	//StreamWriter^ srw2 = gcnew StreamWriter(String::Concat("log2.txt"));
	//srw2->WriteLine("AFTER CHECKING THE COMPUTER DEFENDERS");
	//srw2->WriteLine(String::Concat("Move: ",this->Move.ToString()));
	//srw2->WriteLine("*************************************");
	//for (iii = 0; iii <= 7; iii++)
	//{
	//	for (jjj = 0; jjj <= 7; jjj++)
	//	{
	//		if(Skakiera_Dangerous_Squares[(iii),(jjj)]->ToString()->Equals("Danger") == true)
	//			srw2->WriteLine(String::Concat(iii.ToString(),jjj.ToString()," DANGER!"));
	//		else
	//			srw2->WriteLine(String::Concat(iii.ToString(),jjj.ToString()));
	//	}
	//}
	//srw2->WriteLine("**********************************");
	//srw2->Close();
	////////////////////////////////////////////////////////////////////////////////////////


	            /////////////////////////////
                // 2009 v4 change
                /////////////////////////////
                int Value_of_piece_in_square;
                int Piece_in_danger_rank = 0;
                int Piece_in_danger_column = 0;
                bool Danger_for_piece;
                Danger_for_piece = false;

                for (int y = 0; y < 8; y++)
                {
                    for (int u = 0; u < 8; u++)
                    {
                        // Find value of piece in Skakiera(y,u)
                        Value_of_piece_in_square = 0;
                        if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Rook") == 0) || (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Rook") == 0))
                            Value_of_piece_in_square = 5;
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Bishop") == 0) || (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Bishop") == 0))
                            Value_of_piece_in_square = 3;
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Knight") == 0) || (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Knight") == 0))
                            Value_of_piece_in_square = 3;
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Queen") == 0) || (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Queen") == 0))
                            Value_of_piece_in_square = 9;
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Pawn") == 0) || (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Pawn") == 0))
                            Value_of_piece_in_square = 1;

                        //if((Value_of_defenders[(y), (u)] + Value_of_piece_in_square) > Value_of_attackers[(y), (u)])
                        //{
                        //    Skakiera_Dangerous_Squares[(y), (u)] = "Danger";
                        //}

                        if ((Number_of_defenders[(y), (u)] <= Number_of_attackers[(y), (u)]) && ((Value_of_defenders[(y), (u)]) > Value_of_attackers[(y), (u)]))
                        {
                            Skakiera_Dangerous_Squares[(y), (u)] = "Danger";
                        }
                        else
                        {
                            Skakiera_Dangerous_Squares[(y), (u)] = "";
                        }

                        if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Queen") == 0) && (m_PlayerColor->CompareTo("Black") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Queen") == 0) && (m_PlayerColor->CompareTo("White") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Rook") == 0) && (m_PlayerColor->CompareTo("Black") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Rook") == 0) && (m_PlayerColor->CompareTo("White") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Knight") == 0) && (m_PlayerColor->CompareTo("Black") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Knight") == 0) && (m_PlayerColor->CompareTo("White") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("White Bishop") == 0) && (m_PlayerColor->CompareTo("Black") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }
                        else if ((Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Danger") == 0) && (Skakiera_Dangerous_Squares[(y), (u)]->CompareTo("Black Bishop") == 0) && (m_PlayerColor->CompareTo("White") == 0))
                        {
                            Danger_for_piece = true;
                            Piece_in_danger_rank = u;
                            Piece_in_danger_column = y;
                        }

                        //if ((Number_of_defenders[(y), (u)] > Number_of_attackers[(y), (u)]) && ((Value_of_defenders[(y), (u)] + Value_of_piece_in_square) > Value_of_attackers[(y), (u)]))
                        //{
                        //    Skakiera_Dangerous_Squares[(y), (u)] = "Danger";
                        //}
                    }
                }
                /////////////////////////////
                // 2009 v4 change
                /////////////////////////////

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{
	
		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				// Changed in version 0.5
				this->Danger_penalty = false;
				this->Attackers_penalty = false;
				this->Defenders_value_penalty = false;

				MovingPiece = Skakiera_Thinking[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				            Moving_Piece_Value = 0;
                            Destination_Piece_Value = 0;

                            // Calculate the value (total value) of the moving piece
                            if ((MovingPiece->CompareTo("White Rook") == 0) || (MovingPiece->CompareTo("Black Rook") == 0))
                                Moving_Piece_Value = 5;
                            else if ((MovingPiece->CompareTo("White Bishop") == 0) || (MovingPiece->CompareTo("Black Bishop") == 0))
                                Moving_Piece_Value = 3;
                            else if ((MovingPiece->CompareTo("White Knight") == 0) || (MovingPiece->CompareTo("Black Knight") == 0))
                                Moving_Piece_Value = 3;
                            else if ((MovingPiece->CompareTo("White Queen") == 0) || (MovingPiece->CompareTo("Black Queen") == 0))
                                Moving_Piece_Value = 9;
                            else if ((MovingPiece->CompareTo("White Pawn") == 0) || (MovingPiece->CompareTo("Black Pawn") == 0))
                                Moving_Piece_Value = 1;

                            // Find the value of the piece in the destination square
                            if ((Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("Black Rook") == 0))
                                Destination_Piece_Value = 5;
                            else if ((Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("White Bishop") == 0) || (Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("Black Bishop") == 0))
                                Destination_Piece_Value = 3;
                            else if ((Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("Black Knight") == 0))
                                Destination_Piece_Value = 3;
                            else if ((Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("Black Queen") == 0))
                                Destination_Piece_Value = 9;
                            else if ((Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("White Pawn") == 0) || (Skakiera_Thinking[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("Black Pawn") == 0))
                                Destination_Piece_Value = 1;

				// check move, ONLY if the destination square is not
				// one of the dangerous squares found above.
                                    /////////////////////////////
                                    // 2009 v4 change
                                    /////////////////////////////
                                    danger_penalty = false;

                                    // check move, ONLY if the destination square is not
                                    // one of the dangerous squares found above.
                                    if ((Skakiera_Dangerous_Squares[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)]->CompareTo("Danger") == 0))
                                        danger_penalty = true;
                                    
                                    if((Exception_defender_column[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] == (m_StartingColumnNumber-1)) && (Exception_defender_rank[(m_FinishingColumnNumber-1),(m_FinishingRank-1)] == (m_StartingRank-1)))
                                        danger_penalty = true;

                                    if (Danger_for_piece == true)
                                    {
                                        //if ((Skakiera_Dangerous_Squares[(m_StartingColumnNumber - 1), (m_StartingRank - 1)]->CompareTo("Danger") == 0))
                                        if(((m_StartingColumnNumber-1)!=Piece_in_danger_column)||((m_StartingRank-1)!=Piece_in_danger_rank))
                                        {
                                            danger_penalty = true;
                                        }
                                    }

                                    // Penalty for moving your piece to a square that the human opponent can hit with more power than the computer.
                                    //    if (Number_of_attackers[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] > Number_of_defenders[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)])
                                    //    { Attackers_penalty = true; }

                                        // Penalty if the pieces of the human defending a square in which the computer movies in, have much less
                                        // value than the pieces the computer has to support the attack on that square
                                        //if (Value_of_attackers[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] > Value_of_defenders[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)])
                                        //{ Defenders_value_penalty = true; }

                                        // Penalty for moving the only piece that defends a square to that square (thus leavind the defender
                                        // alone in the square he once defended, defenceless!)
                                        //if ((Exception_defender_column[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] == (m_StartingColumnNumber - 1)) && (Exception_defender_rank[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] == (m_StartingRank - 1)))
                                        //    danger_penalty = false;

                                        // HUO DEBUG
                                        //LoseQueen_penalty = false;

                                        //if (danger_penalty == true)
                                        //{
                                            CheckMove(Skakiera_Thinking);
                                        //}
                                        // UNCOMMENT TO SHOW INNER THINKING MECHANISM!
                                        //if(huo_debug == true)
                                        //{
                                        //	Console.WriteLine("RETURNED TO ComputerMove");
                                        //	Console.ReadKey();
                                        //}
                                        //}

                                    /////////////////////////////
                                    // 2009 v4 change
                                    /////////////////////////////
					
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// find if there is mate
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is MATE!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is MATE!");
		}

	}


	// DO THE BEST MOVE FOUND

	if (Move_Analyzed == 0)
	{
	// Επαναφορά της τιμής της Stop_Analyzing (βλ. πιο πάνω)
	this->Stop_Analyzing = false;

	/////////////////////////////////////////////////////////////////////////////////////////////////
	// REDRAW THE CHESSBOARD
	/////////////////////////////////////////////////////////////////////////////////////////////////

		// erase the initial square
		
		for (iii = 0; iii <= 7; iii++)
		{
			for (jjj = 0; jjj <= 7; jjj++)
			{
				Skakiera[(iii),(jjj)] = Skakiera_Move_0[(iii),(jjj)];
			}
		}

		MovingPiece = Skakiera[(Best_Move_StartingColumnNumber - 1),(Best_Move_StartingRank - 1)];
		Skakiera[(Best_Move_StartingColumnNumber - 1),(Best_Move_StartingRank - 1)] = "";

		if (Best_Move_StartingColumnNumber == 1)
			this->HY_Starting_Column_Text = "a";
		else if (Best_Move_StartingColumnNumber == 2)
			this->HY_Starting_Column_Text = "b";
		else if (Best_Move_StartingColumnNumber == 3)
			this->HY_Starting_Column_Text = "c";
		else if (Best_Move_StartingColumnNumber == 4)
			this->HY_Starting_Column_Text = "d";
		else if (Best_Move_StartingColumnNumber == 5)
			this->HY_Starting_Column_Text = "e";
		else if (Best_Move_StartingColumnNumber == 6)
			this->HY_Starting_Column_Text = "f";
		else if (Best_Move_StartingColumnNumber == 7)
			this->HY_Starting_Column_Text = "g";
		else if (Best_Move_StartingColumnNumber == 8)
			this->HY_Starting_Column_Text = "h";

		// position piece to the square of destination

		Skakiera[(Best_Move_FinishingColumnNumber - 1),(Best_Move_FinishingRank - 1)] = MovingPiece;

		if (Best_Move_FinishingColumnNumber == 1)
			this->HY_Finishing_Column_Text = "a";
		else if (Best_Move_FinishingColumnNumber == 2)
			this->HY_Finishing_Column_Text = "b";
		else if (Best_Move_FinishingColumnNumber == 3)
			this->HY_Finishing_Column_Text = "c";
		else if (Best_Move_FinishingColumnNumber == 4)
			this->HY_Finishing_Column_Text = "d";
		else if (Best_Move_FinishingColumnNumber == 5)
			this->HY_Finishing_Column_Text = "e";
		else if (Best_Move_FinishingColumnNumber == 6)
			this->HY_Finishing_Column_Text = "f";
		else if (Best_Move_FinishingColumnNumber == 7)
			this->HY_Finishing_Column_Text = "g";
		else if (Best_Move_FinishingColumnNumber == 8)
			this->HY_Finishing_Column_Text = "h";

		// if king is moved, no castling can occur
		if (MovingPiece->CompareTo("White King") == 0)
			White_King_Moved = true;
		else if (MovingPiece->CompareTo("Black King") == 0)
			Black_King_Moved = false;
		else if (MovingPiece->CompareTo("White Rook") == 0)
		{
            if ((Best_Move_StartingColumnNumber == 1) && (Best_Move_StartingRank == 1))
				White_Rook_a1_Moved = false;
			else if ((Best_Move_StartingColumnNumber == 8) && (Best_Move_StartingRank == 1))
				White_Rook_h1_Moved = false;
		}
		else if (MovingPiece->CompareTo("Black Rook") == 0)
		{
			if ((Best_Move_StartingColumnNumber == 1) && (Best_Move_StartingRank == 8))
				Black_Rook_a8_Moved = false;
			else if ((Best_Move_StartingColumnNumber == 8) && (Best_Move_StartingRank == 8))
				Black_Rook_h8_Moved = false;
		}
			
		// is there a pawn to promote?
		if ( ( (MovingPiece->CompareTo("White Pawn") == 0) || (MovingPiece->CompareTo("Black Pawn") == 0) ) && (m_WhoPlays->CompareTo("HY") == 0) )
		{

			if (Best_Move_FinishingRank == 8)
			{
				Skakiera[(Best_Move_FinishingColumnNumber - 1),(Best_Move_FinishingRank - 1)] = "White Queen";
				Console::WriteLine( "Κάνω βασίλισσα!" );
			}
			else if (Best_Move_FinishingRank == 1)
			{
				Skakiera[(Best_Move_FinishingColumnNumber - 1),(Best_Move_FinishingRank - 1)] = "Black Queen";
				Console::WriteLine( "Κάνω βασίλισσα!" );
			}

		}


	//////////////////////////////////////////////////////////////////////
	// show HY move
	//////////////////////////////////////////////////////////////////////

	// UNCOMMENT TO SHOW THINKING TIME!
	// Uncomment to have the program record the start and stop time to a log .txt file
	//StreamWriter^ huo_sw = gcnew StreamWriter("game.txt", true);
	//Console::WriteLine(String::Concat("Stoped thinking at: ", DateTime::Now.ToString("hh:mm:ss.fffffff")));
	//huo_sw->WriteLine(String::Concat("Stoped thinking at: ", DateTime::Now.ToString("hh:mm:ss.fffffff")));
	//Console::WriteLine(String::Concat("Number of moves analyzed: ", number_of_moves_analyzed.ToString()));
	//huo_sw->WriteLine(String::Concat("Number of moves analyzed: ", number_of_moves_analyzed.ToString()));

	String^ NextLine= String::Concat( HY_Starting_Column_Text, Best_Move_StartingRank.ToString(), " -> ", HY_Finishing_Column_Text, Best_Move_FinishingRank.ToString() );
	Console::WriteLine(String::Concat("My move is: ", NextLine));
	//huo_sw->WriteLine(String::Concat("My move is: ", NextLine));
	// UNCOMMENT TO SHOW THINKING TIME!
	//Console::WriteLine("Computer thought for {0} seconds", 0.001 * (Environment::TickCount - start));

	//huo_sw->WriteLine("");
	//huo_sw->Close();
	number_of_moves_analyzed = 0;

	// Αν ο υπολογιστής παίζει με τα λευκά, τότε αυξάνεται τώρα το νούμερο της κίνησης.
	if(this->m_PlayerColor->CompareTo("Black") == 0)
		Move = Move + 1;

	// now it is the other color's turn to play
	if (m_PlayerColor->CompareTo("Black") == 0)
		m_WhichColorPlays = "Black";
	else if (m_PlayerColor->CompareTo("White") == 0)
		m_WhichColorPlays = "White";

	// now it is the human's turn to play
	m_WhoPlays = "Human";

	}
	else
	{
		Move_Analyzed = Move_Analyzed - 2;
		Who_Is_Analyzed = "HY";
		for (i = 0; i <= 7; i++)
		{
			for (j = 0; j <= 7; j++)
			{
				Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
			}
		}
	}
}

void CountScore(array<String^, 2>^ CSSkakiera)             
	{      
	// Changed in version 0.5
	// white pieces: positive score
	// black pieces: negative score

	Current_Move_Score = 0;

	if (Destination_Piece_Value > Moving_Piece_Value)
    {
            if (m_PlayerColor->CompareTo("White") == 0)
                Current_Move_Score = Current_Move_Score - 100 * (Destination_Piece_Value - Moving_Piece_Value);
            else if (m_PlayerColor->CompareTo("Black") == 0)
                Current_Move_Score = Current_Move_Score + 100 * (Destination_Piece_Value - Moving_Piece_Value);
    }

		// Changed in version 0.5
	// PENALTIES SECTION
	// (see ComputerMove for explanation of the Dangerous Squares)

	            /////////////////////////////
            // 2009 v4 change
            /////////////////////////////
            // Changed in version 0.5
            // PENALTIES SECTION
            // (see ComputerMove for explanation of the Dangerous Squares)


//	if(this->Danger_penalty == true)
//	{
//		if(this->m_PlayerColor->CompareTo("White") == 0)
//			Current_Move_Score = Current_Move_Score + 5;
//		else if(this->m_PlayerColor->CompareTo("Black") == 0)
//			Current_Move_Score = Current_Move_Score - 5;
//	}

//	if(this->Attackers_penalty == true)
//	{
//		if(this->m_PlayerColor->CompareTo("White") == 0)
//			Current_Move_Score = Current_Move_Score + 4;
//		else if(this->m_PlayerColor->CompareTo("Black") == 0)
//			Current_Move_Score = Current_Move_Score - 4;
//	}

//	if(Defenders_value_penalty == true)
//	{
//		if(this->m_PlayerColor->CompareTo("White") == 0)
//			Current_Move_Score = Current_Move_Score + 4;
//		else if(this->m_PlayerColor->CompareTo("Black") == 0)
//			Current_Move_Score = Current_Move_Score - 4;
//	}

	        /////////////////////////////
            // 2009 v4 change
            /////////////////////////////



	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			if (CSSkakiera[(i),(j)]->CompareTo("White Pawn") == 0)
				Current_Move_Score = Current_Move_Score + 1;
			else if (CSSkakiera[(i),(j)]->CompareTo("White Rook") == 0)
			{
				Current_Move_Score = Current_Move_Score + 5;

				// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("Black")==0)
				{
					if(((i+1)<=7)&&((j+1)<=7))
					{
						if(CSSkakiera[(i+1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->rook_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j+1)<=7))
					{
						if(CSSkakiera[(i-1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->rook_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("White Knight") == 0)
			{
				Current_Move_Score = Current_Move_Score + 3;

				// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("Black")==0)
				{
					if(((i+1)<=7)&&((j+1)<=7))
					{
						if(CSSkakiera[(i+1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->knight_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j+1)<=7))
					{
						if(CSSkakiera[(i-1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->knight_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("White Bishop") == 0)
			{
				Current_Move_Score = Current_Move_Score + 3;

				// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("Black")==0)
				{
					if(((i+1)<=7)&&((j+1)<=7))
					{
						if(CSSkakiera[(i+1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->bishop_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j+1)<=7))
					{
						if(CSSkakiera[(i-1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->bishop_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("White Queen") == 0)
			{
				Current_Move_Score = Current_Move_Score + 9;

				// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("Black")==0)
				{
					if(((i+1)<=7)&&((j+1)<=7))
					{
						if(CSSkakiera[(i+1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->queen_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j+1)<=7))
					{
						if(CSSkakiera[(i-1),(j+1)]->CompareTo("Black Pawn") == 0)
							this->queen_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("White King") == 0)
			{
				Current_Move_Score = Current_Move_Score + 15;
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Pawn") == 0)
				Current_Move_Score = Current_Move_Score - 1;
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Rook") == 0)
			{
				Current_Move_Score = Current_Move_Score - 5;

				// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("White")==0)
				{
					if(((i+1)<=7)&&((j-1)>=0))
					{
						if(CSSkakiera[(i+1),(j-1)]->CompareTo("White Pawn") == 0)
							this->rook_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j-1)>=0))
					{
						if(CSSkakiera[(i-1),(j-1)]->CompareTo("White Pawn") == 0)
							this->rook_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Knight") == 0)
			{
				Current_Move_Score = Current_Move_Score - 3;

				// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("White")==0)
				{
					if(((i+1)<=7)&&((j-1)>=0))
					{
						if(CSSkakiera[(i+1),(j-1)]->CompareTo("White Pawn") == 0)
							this->knight_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j-1)>=0))
					{
						if(CSSkakiera[(i-1),(j-1)]->CompareTo("White Pawn") == 0)
							this->knight_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Bishop") == 0)
			{
				Current_Move_Score = Current_Move_Score - 3;

								// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("White")==0)
				{
					if(((i+1)<=7)&&((j-1)>=0))
					{
						if(CSSkakiera[(i+1),(j-1)]->CompareTo("White Pawn") == 0)
							this->bishop_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j-1)>=0))
					{
						if(CSSkakiera[(i-1),(j-1)]->CompareTo("White Pawn") == 0)
							this->bishop_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Queen") == 0)
			{
					Current_Move_Score = Current_Move_Score - 9;

									// Penalty if the piece of the computer is threatened by a pawn (see CheckMove)
				if(checked_for_pawn_threats == false)
				{
				if(this->m_PlayerColor->CompareTo("White")==0)
				{
					if(((i+1)<=7)&&((j-1)>=0))
					{
						if(CSSkakiera[(i+1),(j-1)]->CompareTo("White Pawn") == 0)
							this->queen_pawn_threat = true;
					}

					if(((i-1)>=0)&&((j-1)>=0))
					{
						if(CSSkakiera[(i-1),(j-1)]->CompareTo("White Pawn") == 0)
							this->queen_pawn_threat = true;
					}
				}
				}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("Black King") == 0)
			{
				Current_Move_Score = Current_Move_Score + 15;
			}

		}
	}


	        /////////////////////////////
            // 2009 v4 change
            /////////////////////////////


		// Pawn threat penalties: if the computer moves its piece at a square where it is
	// threatened by an opponent's pawn, there is a penalty (see CheckMove and CountScore).
	// ADDED IN VERSION 0.6
	if(this->rook_pawn_threat == true)
	{
		if(this->m_PlayerColor->CompareTo("Black") == 0)
			Current_Move_Score = Current_Move_Score - 10;
		else if(this->m_PlayerColor->CompareTo("White") == 0)
			Current_Move_Score = Current_Move_Score + 10;
	}

	if(this->knight_pawn_threat == true)
	{
		if(this->m_PlayerColor->CompareTo("Black") == 0)
			Current_Move_Score = Current_Move_Score - 6;
		else if(this->m_PlayerColor->CompareTo("White") == 0)
			Current_Move_Score = Current_Move_Score + 6;
	}

	if(this->bishop_pawn_threat == true)
	{
		if(this->m_PlayerColor->CompareTo("Black") == 0)
			Current_Move_Score = Current_Move_Score - 6;
		else if(this->m_PlayerColor->CompareTo("White") == 0)
			Current_Move_Score = Current_Move_Score + 6;
	}

	if(this->queen_pawn_threat == true)
	{
		if(this->m_PlayerColor->CompareTo("Black") == 0)
			Current_Move_Score = Current_Move_Score - 20;
		else if(this->m_PlayerColor->CompareTo("White") == 0)
			Current_Move_Score = Current_Move_Score + 20;
	}

	if (danger_penalty == true)
    {
        if (m_PlayerColor->CompareTo("Black") == 0)
            Current_Move_Score = Current_Move_Score - 20;
        else if (m_PlayerColor->CompareTo("White") == 0)
            Current_Move_Score = Current_Move_Score + 20;
    }

            /////////////////////////////
            // 2009 v4 change
            /////////////////////////////

	// if we are in the beginning of the game, it is not good to move
	// your queen, king, rooks etc...

	if (Move < 11)
	{

	// control the center with your pawns

	if (CSSkakiera[3,2]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;
		
	if (CSSkakiera[3,3]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;
		
	if (CSSkakiera[4,2]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;
	
	if (CSSkakiera[4,3]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;
		
	if (CSSkakiera[3,5]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.4;
		
	if (CSSkakiera[3,4]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.4;
		
	if (CSSkakiera[4,5]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.4;
		
	if (CSSkakiera[4,4]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.4;

	// don't play a4, h4, etc

	if (CSSkakiera[0,3]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.2;

	if (CSSkakiera[1,3]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.2;

	if (CSSkakiera[6,3]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.2;

	if (CSSkakiera[7,3]->CompareTo("White Pawn") == 0)
		Current_Move_Score = Current_Move_Score - 0.2;

	if (CSSkakiera[0,4]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;

	if (CSSkakiera[1,4]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;

	if (CSSkakiera[6,4]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;

	if (CSSkakiera[7,4]->CompareTo("Black Pawn") == 0)
		Current_Move_Score = Current_Move_Score + 0.4;

	// don't play the rook

	if (CSSkakiera[0,0]->CompareTo("") == 0)
		Current_Move_Score = Current_Move_Score - 0.1;

	if (CSSkakiera[7,0]->CompareTo("") == 0)
		Current_Move_Score = Current_Move_Score - 0.1;

	if (CSSkakiera[0,7]->CompareTo("") == 0)
		Current_Move_Score = Current_Move_Score + 0.1;

	if (CSSkakiera[7,7]->CompareTo("") == 0)
		Current_Move_Score = Current_Move_Score + 0.1;

	// Μην παίζεις τους ίππους στη γωνία

	if (CSSkakiera[0,2]->CompareTo("White Knight") == 0)
		Current_Move_Score = Current_Move_Score - 0.1;

	if (CSSkakiera[7,2]->CompareTo("White Knight") == 0)
		Current_Move_Score = Current_Move_Score - 0.1;

	if (CSSkakiera[0,5]->CompareTo("Black Knight") == 0)
		Current_Move_Score = Current_Move_Score + 0.1;

	if (CSSkakiera[7,5]->CompareTo("Black Knight") == 0)
		Current_Move_Score = Current_Move_Score + 0.1;
	} 

	if (Move < 10)
	{
		// Μην κινείς τη βασίλισσα νωρίς

		if(this->m_PlayerColor->CompareTo("Black") == 0)
		{
			if (CSSkakiera[3,0]->CompareTo("") == 0)
				Current_Move_Score = Current_Move_Score - 10.9;
		}

		if(this->m_PlayerColor->CompareTo("White") == 0)
		{
			if (CSSkakiera[3,7]->CompareTo("") == 0)
				Current_Move_Score = Current_Move_Score + 10.9;
		}
	}

	if (Move < 8)
	{
		// Μην κινείς το βασιλιά νωρίς

		if ( (CSSkakiera[4,0]->CompareTo("") == 0) && (this->m_PlayerColor->CompareTo("Black") == 0) )
			Current_Move_Score = Current_Move_Score - 3;

		if ( (CSSkakiera[4,7]->CompareTo("") == 0) && (this->m_PlayerColor->CompareTo("White") == 0) )
			Current_Move_Score = Current_Move_Score + 3;
	}

//	if( Move < 7 )
//	{
//		// don't go to check too early!
//
//		if(this->m_PlayerColor->CompareTo("Black") == 0)
//		{
//			this->CheckForBlackCheck(CSSkakiera);
//			if (this->BlackKingCheck == true)
//				Current_Move_Score = Current_Move_Score - 3;
//		}
//
//		if(this->m_PlayerColor->CompareTo("White") == 0)
//		{
//			this->CheckForWhiteCheck(CSSkakiera);
//			if (this->WhiteKingCheck == true)
//				Current_Move_Score = Current_Move_Score + 3;
//		}
//	}

	// HY likes to eat the opponent's queen, so as to simplify the game!
	if( this->eat_queen == true )
	{
		if( this->m_PlayerColor->CompareTo("White") == 0 )
			Current_Move_Score = Current_Move_Score - 1;
		else if( this->m_PlayerColor->CompareTo("Black") == 0 )
			Current_Move_Score = Current_Move_Score + 1;
	}

	// if mate is possible, go for it!
	//if( Possible_mate == true )
	//{
	//	if( this->m_PlayerColor->CompareTo("White") == 0 )
	//		Current_Move_Score = Current_Move_Score - 0.2;
	//	else if( this->m_PlayerColor->CompareTo("Black") == 0 )
	//		Current_Move_Score = Current_Move_Score + 0.2;
	//}

	// don't move the king early in the game!
	//if( (moving_the_king == true) && (Move < 10) )
	//{
	//	if( this->m_PlayerColor->CompareTo("White") == 0 )
	//		Current_Move_Score = Current_Move_Score + 0.4;
	//	else if( this->m_PlayerColor->CompareTo("Black") == 0 )
	//		Current_Move_Score = Current_Move_Score - 0.4;
	//}


	}


void CountScore_Human(array<String^, 2>^ CSSkakiera)             
	{      
	// count score for human moves analyzed
	// SEE RESPECTIVE CountScore funtion for analytical comments in English!
	// All pieces values here are increased by +2 relatively to the respective values
	// in CountScore. This is to show/emphasize to the computer that its human opponent
	// will aim at killing his pieces!
	Current_Human_Move_Score = 0;

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			if (CSSkakiera[(i),(j)]->CompareTo("White Pawn") == 0)
			{
				Current_Human_Move_Score = Current_Human_Move_Score + 1;

				// Αν το πιόνι πάει να βγει βασίλισσα.
				// Ο έλεγχος γίνεται μόνο για τα πιόνια του αντιπάλου,
				// αλλιώς ο ΗΥ θα προωθούσε συνεχώς τα πιόνια του
				// no matter what!
				//if( this->m_PlayerColor->CompareTo("White") == 0 )
				//{
				//	if( j == 5 )
				//		Current_Human_Move_Score = Current_Human_Move_Score + 1;
				//	else if( j == 6 )
				//		Current_Human_Move_Score = Current_Human_Move_Score + 1.1;
				//	else if( j == 7 )
				//		Current_Human_Move_Score = Current_Human_Move_Score + 1.2;
				//}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("White Rook") == 0)
				Current_Human_Move_Score = Current_Human_Move_Score + 7;
			else if (CSSkakiera[(i),(j)]->CompareTo("White Knight") == 0)
				Current_Human_Move_Score = Current_Human_Move_Score + 5;
			else if (CSSkakiera[(i),(j)]->CompareTo("White Bishop") == 0)
				Current_Human_Move_Score = Current_Human_Move_Score + 5;
			else if (CSSkakiera[(i),(j)]->CompareTo("White Queen") == 0)
					Current_Human_Move_Score = Current_Human_Move_Score + 11;
			else if (CSSkakiera[(i),(j)]->CompareTo("White King") == 0)
			{
				// Ο (λευκός) βασιλιάς έχει πολύ μικρό σκορ.
				// Αυτό γίνεται διότι εάν ο λευκός βασιλιάς είχε π.χ.
				// σκορ 100 (ήτοι πολύ μεγάλο), τότε ο μαύρος
				// υπολογιστής θα κινούσε όλα τα κομμάτια του
				// με μοναδικό στόχο να φάει το βασιλιά του αντιπάλου,
				// άρα θα έκανε τρομερές βλακείες.
				// Π.χ. αν στο τέλος των 5 κινήσεων που βλέπει σε βάθος
				// ο υπολογιστής έβλεπε ότι θα έτρωγε τον αντίπαλο βασιλιά,
				// τότε μπορεί να έπαιζε ακόμα και τη βασίλισσα του πολύ
				// νωρίς στο παιχνίδι ή να αγνοούσε ένα πιθανό ματ που θα
				// του έκανε ο αντίπαλος 1 κίνηση πριν (αφού στο τέλος όλων
				// των κινήσεων θα μετρούσε το τελικό σκορ της θέσης και
				// θα έβισκε ότι θα ήταν μια χαρά: το +100 του λευκού βασιλιά
				// θα αντισταθμιζόταν από το -100 του μαύρου και όλα θα
				// "φαινόντουσαν" καλα!
				// Το αντίστοιχο συμβαίνει με τον μαύρο βασιλιά.
				Current_Human_Move_Score = Current_Human_Move_Score + 17;
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Pawn") == 0)
			{
				Current_Human_Move_Score = Current_Human_Move_Score - 1;

				// Αν το πιόνι πάει να βγει βασίλισσα.
				// Ο έλεγχος γίνεται μόνο για τα πιόνια του αντιπάλου,
				// αλλιώς ο ΗΥ θα προωθούσε συνεχώς τα πιόνια του
				// no matter what!
				//if( this->m_PlayerColor->CompareTo("Black") == 0 )
				//{
					//if( j == 2 )
						Current_Human_Move_Score = Current_Human_Move_Score - 1;
					//else if( j == 1 )
					//	Current_Human_Move_Score = Current_Human_Move_Score - 1.1;
					//else if( j == 0 )
					//	Current_Human_Move_Score = Current_Human_Move_Score - 1.2;
				//}
			}
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Rook") == 0)
				Current_Human_Move_Score = Current_Human_Move_Score - 7;
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Knight") == 0)
				Current_Human_Move_Score = Current_Human_Move_Score - 5;
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Bishop") == 0)
				Current_Human_Move_Score = Current_Human_Move_Score - 5;
			else if (CSSkakiera[(i),(j)]->CompareTo("Black Queen") == 0)
					Current_Human_Move_Score = Current_Human_Move_Score - 11;
			else if (CSSkakiera[(i),(j)]->CompareTo("Black King") == 0)
				Current_Human_Move_Score = Current_Human_Move_Score - 17;

		}
	}

	}


// FUNCTION TO CHECK THE LEGALITY (='Nomimotita' in Greek) OF A MOVE
// (i.e. if between the initial and the destination square lies another
// piece, then the move is not legal).
bool ElegxosNomimotitas(array<String^, 2>^ ENSkakiera)              
	{												         
	// TODO: Add your control notification handler code here

	bool Nomimotita;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Έλεγχος της "ΝΟΜΙΜΟΤΗΤΑΣ" της κίνησης. Αν π.χ. ο χρήστης έχει επιλέξει να κινήσει έναν πύργο από
	// το α2 στο α5, αλλά στο α4 υπάρχει κάποιο πιόνι του, τότε η Nomimotita έχει τιμή false.
	// Η συνάρτηση "επιστρέφει" τη boolean μεταβλητή Nomimotita.
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Nomimotita = true;

	if( ((m_FinishingRank-1) > 7) || ((m_FinishingRank-1) < 0) || ((m_FinishingColumnNumber-1) > 7) || ((m_FinishingColumnNumber-1) < 0) )
		Nomimotita = false;

	// if a piece of the same colout is in the destination square...
	if ( (MovingPiece->CompareTo("White King") == 0) || (MovingPiece->CompareTo("White Queen") == 0) || (MovingPiece->CompareTo("White Rook") == 0) || (MovingPiece->CompareTo("White Knight") == 0) || (MovingPiece->CompareTo("White Bishop") == 0)  || (MovingPiece->CompareTo("White Pawn") == 0) )
	{
		if ( (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("White King") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("White Queen") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("White Rook") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("White Knight") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("White Bishop") == 0)  || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("White Pawn") == 0) )
		{
			Nomimotita = false;
		}
	}
	else if ( (MovingPiece->CompareTo("Black King") == 0) || (MovingPiece->CompareTo("Black Queen") == 0) || (MovingPiece->CompareTo("Black Rook") == 0) || (MovingPiece->CompareTo("Black Knight") == 0) || (MovingPiece->CompareTo("Black Bishop") == 0)  || (MovingPiece->CompareTo("Black Pawn") == 0) )
	{
		if ( (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("Black King") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("Black Queen") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("Black Rook") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("Black Knight") == 0) || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("Black Bishop") == 0)  || (ENSkakiera[((m_FinishingColumnNumber-1)),((m_FinishingRank-1))]->CompareTo("Black Pawn") == 0) )
			Nomimotita = false;
	}

	if (MovingPiece->CompareTo("White King") == 0)
	{
		/////////////////////////
		// white king
		/////////////////////////
		// is the king threatened in the destination square?
		// temporarily move king
		ENSkakiera[(m_StartingColumnNumber - 1), (m_StartingRank - 1)] = "";
		ProsorinoKommati_KingCheck = ENSkakiera[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)];
		ENSkakiera[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] = "White King";

		WhiteKingCheck = CheckForWhiteCheck(ENSkakiera);

		if (WhiteKingCheck == true)
			Nomimotita = false;

		// restore pieces
		ENSkakiera[(m_StartingColumnNumber - 1), (m_StartingRank - 1)] = "White King";
		ENSkakiera[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] = ProsorinoKommati_KingCheck;

	}
	else if (MovingPiece->CompareTo("Black King") == 0)
	{
		///////////////////////////
		// black king
		///////////////////////////
		// is the black king threatened in the destination square?
		// temporarily move king
		ENSkakiera[(m_StartingColumnNumber - 1), (m_StartingRank - 1)] = "";
		ProsorinoKommati_KingCheck = ENSkakiera[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)];
		ENSkakiera[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] = "Black King";

		BlackKingCheck = CheckForBlackCheck(ENSkakiera);

		if (BlackKingCheck == true)
			Nomimotita = false;

		// restore pieces
		ENSkakiera[(m_StartingColumnNumber - 1), (m_StartingRank - 1)] = "Black King";
		ENSkakiera[(m_FinishingColumnNumber - 1), (m_FinishingRank - 1)] = ProsorinoKommati_KingCheck;

	}
	else if (MovingPiece->CompareTo("White Pawn") == 0)
	{
		/////////////////////
		// white pawn
		/////////////////////

		// move forward

		if ( (m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber) )
		{
			if (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 1)
					Nomimotita = false;
		}

		// move forward for 2 squares
		else if ((m_FinishingRank == (m_StartingRank + 2)) && (m_FinishingColumnNumber == m_StartingColumnNumber))
		{
			if (m_StartingRank == 2)
			{
				if ((ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 1)|| (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 - 1)]->CompareTo("") == 1))
						Nomimotita = false;
			}
		}

		// eat forward to the right

		else if ((m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber + 1))
		{
			if( enpassant_occured == false )
			{
				if (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 0)
						Nomimotita = false;
			}
			else
			{
				if((m_FinishingRank != enpassant_possible_target_rank) || (m_FinishingColumnNumber != enpassant_possible_target_column))
					Nomimotita = false;
			}
		}

		// eat forward to the left

		else if ((m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber - 1))
		{
			if( enpassant_occured == false )
			{
				if (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 0)
						Nomimotita = false;
			}
			else
			{
				if((m_FinishingRank != enpassant_possible_target_rank) || (m_FinishingColumnNumber != enpassant_possible_target_column))
					Nomimotita = false;
			}
		}

	}
	else if (MovingPiece->CompareTo("Black Pawn") == 0)
	{
		/////////////////////
		// black pawn
		/////////////////////

		// move forward

		if ( (m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber) )
		{
			if (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 1)
					Nomimotita = false;
		}

		// move forward for 2 squares
		else if ((m_FinishingRank == (m_StartingRank - 2)) && (m_FinishingColumnNumber == m_StartingColumnNumber))
		{
			if (m_StartingRank == 7)
			{
				if ((ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 1)|| (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank + 1 - 1)]->CompareTo("") == 1))
						Nomimotita = false;
			}
		}

		// eat forward to the right

		else if ((m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber + 1))
		{
			if( enpassant_occured == false )
			{
			if (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 0)
					Nomimotita = false;
			}
			else
			{
				if((m_FinishingRank != enpassant_possible_target_rank) || (m_FinishingColumnNumber != enpassant_possible_target_column))
					Nomimotita = false;
			}
		}

		// eat forward to the left

		else if ((m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber - 1))
		{
			if( enpassant_occured == false )
			{
			if (ENSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("") == 0)
					Nomimotita = false;
			}
			else
			{
				if((m_FinishingRank != enpassant_possible_target_rank) || (m_FinishingColumnNumber != enpassant_possible_target_column))
					Nomimotita = false;
			}
		}

	}
	else if( (MovingPiece->CompareTo("White Rook") == 0) || (MovingPiece->CompareTo("White Queen") == 0) || (MovingPiece->CompareTo("White Bishop") == 0) || (MovingPiece->CompareTo("Black Rook") == 0) || (MovingPiece->CompareTo("Black Queen") == 0) || (MovingPiece->CompareTo("Black Bishop") == 0) )
	{
		h = 0;
		p = 0;
		hhh = 0;
		how_to_move_Rank = 0;
		how_to_move_Column = 0;

		if(((m_FinishingRank-1) > (m_StartingRank-1)) || ((m_FinishingRank-1) < (m_StartingRank-1)))
			how_to_move_Rank = ((m_FinishingRank-1) - (m_StartingRank-1))/System::Math::Abs((m_FinishingRank-1) - (m_StartingRank-1));
			
		if(((m_FinishingColumnNumber-1) > (m_StartingColumnNumber-1)) || ((m_FinishingColumnNumber-1) < (m_StartingColumnNumber-1)) )
			how_to_move_Column = ((m_FinishingColumnNumber-1) - (m_StartingColumnNumber-1))/System::Math::Abs((m_FinishingColumnNumber-1) - (m_StartingColumnNumber-1));

		exit_elegxos_nomimothtas = false;

		do
		{
			h = h + how_to_move_Rank;
			p = p + how_to_move_Column;

			if( (((m_StartingRank-1) + h) == (m_FinishingRank-1)) && ((((m_StartingColumnNumber-1) + p)) == (m_FinishingColumnNumber-1)) )
				exit_elegxos_nomimothtas = true;

			if((m_StartingColumnNumber - 1 + p)<0)
				exit_elegxos_nomimothtas = true;
			else if((m_StartingRank - 1 + h)<0)
				exit_elegxos_nomimothtas = true;
			else if((m_StartingColumnNumber - 1 + p)>7)
				exit_elegxos_nomimothtas = true;
			else if((m_StartingRank - 1 + h)>7)
				exit_elegxos_nomimothtas = true;

			// if a piece exists between the initial and the destination square,
			// then the move is illegal!
			if( exit_elegxos_nomimothtas == false )
			{
				if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("White Rook") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("White Knight") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("White Bishop") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("White Queen") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("White King") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("White Pawn") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				
				if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("Black Rook") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("Black Knight") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("Black Bishop") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("Black Queen") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("Black King") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
				else if(ENSkakiera[(m_StartingColumnNumber - 1 + p),(m_StartingRank - 1 + h)]->CompareTo("Black Pawn") == 0)
				{
					Nomimotita = false;
					exit_elegxos_nomimothtas = true;
				}
			}
		}while(exit_elegxos_nomimothtas == false);
	}
	return Nomimotita;
	}


// FUNCTION TO CHECK THE CORRECTNESS (='Orthotita' in Greek) OF THE MOVE
// (i.e. a Bishop can only move in diagonals, rooks in lines and columns etc)
bool ElegxosOrthotitas(array<String^, 2>^ EOSkakiera)        
	{      
	// TODO: Add your control notification handler code here

	bool Orthotita;
	Orthotita = false;
	enpassant_occured = false;

	if ( (m_WhoPlays->CompareTo("Human") == 0) && (m_WrongColumn == false) && (MovingPiece->CompareTo("") == 1) )    // Αν ο χρήστης έχει γράψει μία έγκυρη στήλη και έχει
	{                                                         // επιλέξει να κινήσει ένα κομμάτι (και δεν έχει επι-
		                                                      // λέξει να κινήσει ένα "κενό" τετράγωνο) και είναι η σειρά του να παίξει, τότε να γί-
		                                                      // νει έλεγχος της ορθότητας της κίνησης. 

	// ROOK

	if ( (MovingPiece->CompareTo("White Rook") == 0)||(MovingPiece->CompareTo("Black Rook") == 0) )
	{
		if ( (m_FinishingColumnNumber != m_StartingColumnNumber)&&(m_FinishingRank == m_StartingRank) )       // Κίνηση σε στήλη
			Orthotita = true;
		else if ( (m_FinishingRank != m_StartingRank)&&(m_FinishingColumnNumber == m_StartingColumnNumber) )  // Κίνηση σε γραμμή
			Orthotita = true;
	}

	// horse (with knight...)

	if ( (MovingPiece->CompareTo("White Knight") == 0)||(MovingPiece->CompareTo("Black Knight") == 0) )
	{
		if ( (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) && (m_FinishingRank == (m_StartingRank + 2)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber + 2)) && (m_FinishingRank == (m_StartingRank - 1)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) && (m_FinishingRank == (m_StartingRank - 2)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) && (m_FinishingRank == (m_StartingRank - 2)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber - 2)) && (m_FinishingRank == (m_StartingRank - 1)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber - 2)) && (m_FinishingRank == (m_StartingRank + 1)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) && (m_FinishingRank == (m_StartingRank + 2)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber + 2)) && (m_FinishingRank == (m_StartingRank + 1)) )
			Orthotita = true;
	}

	// bishop

	if ( (MovingPiece->CompareTo("White Bishop") == 0)||(MovingPiece->CompareTo("Black Bishop") == 0) )
	{
		            ////////////////////
                    // 2009 v4 change
                    ////////////////////
		//if((Math::Abs(m_FinishingColumnNumber-m_StartingColumnNumber))==(Math::Abs(m_FinishingRank-m_StartingRank)))
		//	Orthotita = true;
		if (((Math::Abs(m_FinishingColumnNumber - m_StartingColumnNumber)) == (Math::Abs(m_FinishingRank - m_StartingRank))) && (m_FinishingColumnNumber != m_StartingColumnNumber) && (m_FinishingRank != m_StartingRank))
            Orthotita = true;
                    ////////////////////
                    // 2009 v4 change
                    ////////////////////
	}

	// queen

	if ( (MovingPiece->CompareTo("White Queen") == 0)||(MovingPiece->CompareTo("Black Queen") == 0) )
	{
		if ( (m_FinishingColumnNumber != m_StartingColumnNumber)&&(m_FinishingRank == m_StartingRank) )       // Κίνηση σε στήλη
			Orthotita = true;
		else if ( (m_FinishingRank != m_StartingRank)&&(m_FinishingColumnNumber == m_StartingColumnNumber) )  // Κίνηση σε γραμμή
			Orthotita = true;

		// move in diagonals
		//if((Math::Abs(m_FinishingColumnNumber-m_StartingColumnNumber))==(Math::Abs(m_FinishingRank-m_StartingRank)))
		//	Orthotita = true;
				    ////////////////////
                    // 2009 v4 change
                    ////////////////////
		//if((Math::Abs(m_FinishingColumnNumber-m_StartingColumnNumber))==(Math::Abs(m_FinishingRank-m_StartingRank)))
		//	Orthotita = true;
		if (((Math::Abs(m_FinishingColumnNumber - m_StartingColumnNumber)) == (Math::Abs(m_FinishingRank - m_StartingRank))) && (m_FinishingColumnNumber != m_StartingColumnNumber) && (m_FinishingRank != m_StartingRank))
            Orthotita = true;
                    ////////////////////
                    // 2009 v4 change
                    ////////////////////
	}

	// king

	if ( (MovingPiece->CompareTo("White King") == 0)||(MovingPiece->CompareTo("Black King") == 0) )
	{
		// move in rows and columns

		if ( (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) && (m_FinishingRank == m_StartingRank) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) && (m_FinishingRank == m_StartingRank) )
			Orthotita = true;
		else if ( (m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber) )
			Orthotita = true;
		else if ( (m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber) )
			Orthotita = true;

		// move in diagonals

		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) && (m_FinishingRank == (m_StartingRank + 1)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) && (m_FinishingRank == (m_StartingRank - 1)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) && (m_FinishingRank == (m_StartingRank - 1)) )
			Orthotita = true;
		else if ( (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) && (m_FinishingRank == (m_StartingRank + 1)) )
			Orthotita = true;

	}

	// white pawn

	if (MovingPiece->CompareTo("White Pawn") == 0)
	{
		// move forward

		if ( (m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber) )
			Orthotita = true;

		// move forward for 2 squares
		else if ( (m_FinishingRank == (m_StartingRank + 2)) && (m_FinishingColumnNumber == m_StartingColumnNumber) && (m_StartingRank == 2) )
			Orthotita = true;

		// eat forward to the left
		else if ( (m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) && ((EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Pawn") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Rook") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Knight") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Bishop") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Queen") == 0) ))
			Orthotita = true;

		// eat forward to the right
		else if ( (m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) && ((EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Pawn") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Rook") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Knight") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Bishop") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("Black Queen") == 0) ))
			Orthotita = true;

		// En Passant eat forward to the left
		else if ( (m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) )
		{
			if((m_FinishingRank == 4) && (EOSkakiera[(m_FinishingColumnNumber - 1),(4)]->CompareTo("Black Pawn") == 0))
			{
			Orthotita = true;
			enpassant_occured = true;
			EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 - 1)] = "";
			}
			else
			{
			Orthotita = false;
			enpassant_occured = false;
			}
		}

		// En Passant eat forward to the right
		else if ( (m_FinishingRank == (m_StartingRank + 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) )
		{
			if((m_FinishingRank == 4) && (EOSkakiera[(m_FinishingColumnNumber - 1),(4)]->CompareTo("Black Pawn") == 0))
			{
			Orthotita = true;
			enpassant_occured = true;
			EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 - 1)] = "";
			}
			else
			{
			Orthotita = false;
			enpassant_occured = false;
			}
		}

	}


	// black pawn

	if (MovingPiece->CompareTo("Black Pawn") == 0)
	{
		// move forward

		if ( (m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == m_StartingColumnNumber) )
			Orthotita = true;

		// move forward for 2 squares
		else if ( (m_FinishingRank == (m_StartingRank - 2)) && (m_FinishingColumnNumber == m_StartingColumnNumber) && (m_StartingRank == 7) )
			Orthotita = true;

		// eat forward to the left
		else if ( (m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) && ((EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Pawn") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Rook") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Knight") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Bishop") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Queen") == 0) ))
			Orthotita = true;

		// eat forward to the right
		else if ( (m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) && ((EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Pawn") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Rook") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Knight") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Bishop") == 0) || (EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->CompareTo("White Queen") == 0) ))
			Orthotita = true;

		// En Passant eat forward to the left
		else if ( (m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber + 1)) )
		{
			if((m_FinishingRank == 3)&&(EOSkakiera[(m_FinishingColumnNumber - 1),(3)]->CompareTo("White Pawn") == 0))
			{
			Orthotita = true;
			enpassant_occured = true;
			EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank + 1 - 1)] = "";
			}
			else
			{
			Orthotita = false;
			enpassant_occured = false;
			}
		}

		// En Passant eat forward to the right
		else if ( (m_FinishingRank == (m_StartingRank - 1)) && (m_FinishingColumnNumber == (m_StartingColumnNumber - 1)) )
		{
			if((m_FinishingRank == 3)&&(EOSkakiera[(m_FinishingColumnNumber - 1),(3)]->CompareTo("White Pawn") == 0))
			{
			Orthotita = true;
			enpassant_occured = true;
			EOSkakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank + 1 - 1)] = "";
			}
			else
			{
			Orthotita = false;
			enpassant_occured = false;
			}
		}

	}

	}

	return Orthotita;
	}


		
void Enter_move(void)                       
	{                   
	// TODO: Add your control notification handler code here

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// show the move entered by the human player
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (m_StartingColumn->CompareTo("A") == 0)
		m_StartingColumnNumber = 1;
	else if (m_StartingColumn->CompareTo("B") == 0)
		m_StartingColumnNumber = 2;
	else if (m_StartingColumn->CompareTo("C") == 0)
		m_StartingColumnNumber = 3;
	else if (m_StartingColumn->CompareTo("D") == 0)
		m_StartingColumnNumber = 4;
	else if (m_StartingColumn->CompareTo("E") == 0)
		m_StartingColumnNumber = 5;
	else if (m_StartingColumn->CompareTo("F") == 0)
		m_StartingColumnNumber = 6;
	else if (m_StartingColumn->CompareTo("G") == 0)
		m_StartingColumnNumber = 7;
	else if (m_StartingColumn->CompareTo("H") == 0)
		m_StartingColumnNumber = 8;


	if (m_FinishingColumn->CompareTo("A") == 0)
		m_FinishingColumnNumber = 1;
	else if (m_FinishingColumn->CompareTo("B") == 0)
		m_FinishingColumnNumber = 2;
	else if (m_FinishingColumn->CompareTo("C") == 0)
		m_FinishingColumnNumber = 3;
	else if (m_FinishingColumn->CompareTo("D") == 0)
		m_FinishingColumnNumber = 4;
	else if (m_FinishingColumn->CompareTo("E") == 0)
		m_FinishingColumnNumber = 5;
	else if (m_FinishingColumn->CompareTo("F") == 0)
		m_FinishingColumnNumber = 6;
	else if (m_FinishingColumn->CompareTo("G") == 0)
		m_FinishingColumnNumber = 7;
	else if (m_FinishingColumn->CompareTo("H") == 0)
		m_FinishingColumnNumber = 8;


	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	// record which piece is moving
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////

	if (m_WhoPlays->CompareTo("HY") == 0)   // Αν είναι η σειρά του υπολογιστή να παίξει (και όχι του χρήστη), τότε άκυρο!!
		Console::WriteLine("It's not your turn.");

	// Αν χρήστης έχει εισάγει μία έγκυρη στήλη (π.χ. "ε" ή "ζ") και πάει να κινήσει ένα κομμάτι του σωστού
	// χρώματος (π.χ. έναν λευκό ίππο και είναι πράγματι η σειρά των λευκών να παίξουν) τότε να προχωρήσει το
	// πρόγραμμα σε ό,τι κάνει.
	// Δεν είναι απαραίτητο να γίνει και έλεγχος του αν ο χρήστης έχει γράψει σωστή γραμμή (ήτοι ένα
	// νούμερο από το 1 έως το 8), διότι αυτό απαγορεύεται από τη δήλωση των μεταβλητών m_StartingRank και
	// m_FinishingRank (οι οποίες έχουν δηλωθεί σαν ακέραιοι που παίρνουν τιμές από 1 έως 8).

	else if ( ((m_WhoPlays->CompareTo("Human") == 0)||(m_PlayerColor->CompareTo("Self") == 0)) && ( ((m_WhichColorPlays->CompareTo("White") == 0) && ((Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White Pawn") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White Rook") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White Knight") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White Bishop") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White Queen") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White King") == 0))) || ((m_WhichColorPlays->CompareTo("Black") == 0) && ((Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black Pawn") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black Rook") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black Knight") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black Bishop") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black Queen") == 0)||(Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black King") == 0))) ) )
	{

	m_WrongColumn = false;
	MovingPiece = "";

	// is the king under check?
	if (m_PlayerColor->CompareTo("White") == 0)
		WhiteKingCheck = CheckForWhiteCheck(Skakiera);
	else if (m_PlayerColor->CompareTo("Black") == 0)
		BlackKingCheck = CheckForBlackCheck(Skakiera);

	MovingPiece = Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)];
		
	// if he chooses to move a piece of different colour...
	if ( ((m_PlayerColor->CompareTo("White") == 0)||(m_PlayerColor->CompareTo("Self") == 0) && ((Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("White Rook") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("White Knight") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("White Bishop") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("White Queen") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("White King") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("White Pawn") == 0)))  ||  ( ((m_PlayerColor->CompareTo("Black") == 0)||(m_PlayerColor->CompareTo("Self") == 0)) && ((Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("Black Rook") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("Black Knight") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("Black Bishop") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("Black Queen") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("Black King") == 0) || (Skakiera[(m_StartingColumnNumber - 1),((m_StartingRank - 1))]->CompareTo("Black Pawn") == 0))))
	{
		Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = "";
	}

	}
	else
	{
		if (m_WhichColorPlays->CompareTo("White") == 0)
			Console::WriteLine("White plays.");
		else if (m_WhichColorPlays->CompareTo("Black") == 0)
			Console::WriteLine("Black plays.");

		m_WrongColumn = true;          // Η μεταβλητή αυτή τίθεται true για να βγει "μη ορθή" η κίνηση από
		                               // τη συνάρτηση που ακολουθεί ακριβώς από κάτω και ελέγχει την "ορθότητα"
		                               // της κίνησης.
	}

	// Check correctness of move entered
	m_OrthotitaKinisis = ElegxosOrthotitas(Skakiera);

	// check legality of move entered
	// (only if it is correct - so as to save time!)
	if( m_OrthotitaKinisis == true )
		m_NomimotitaKinisis = ElegxosNomimotitas(Skakiera);
	else
		m_NomimotitaKinisis = false;

	// check if the human's king is in check even after his move!
	// temporarily move the piece the user wants to move
	Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = "";
	ProsorinoKommati = Skakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)];
	Skakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = MovingPiece;

	// check if king is still under check
	WhiteKingCheck = CheckForWhiteCheck(Skakiera);

	if ( (m_WhichColorPlays->CompareTo("White") == 0) && (WhiteKingCheck == true) )
		m_NomimotitaKinisis = false;


	// check if black king is still under check
	BlackKingCheck = CheckForBlackCheck(Skakiera);

	if ( (m_WhichColorPlays->CompareTo("Black") == 0) && (BlackKingCheck == true) )
		m_NomimotitaKinisis = false;

	// restore all pieces to the initial state
	Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = MovingPiece;
	Skakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = ProsorinoKommati;

	///////////////////////////////////////////////////////////////////
	// CHECK IF THE HUMAN HAS ENTERED A CASTLING MOVE
	///////////////////////////////////////////////////////////////////

	///////////////////////////
	// WHITE CASTLING
	///////////////////////////

	// small castling

	if ((this->m_PlayerColor->CompareTo("White") == 0) && (m_StartingColumnNumber == 5) && (m_FinishingColumnNumber == 7) && (m_StartingRank == 1) && (m_FinishingRank == 1))
	{
		if ( (Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White King") == 0) && (Skakiera[(7),(0)]->CompareTo("White Rook") == 0) && (Skakiera[(5),(0)]->CompareTo("") == 0) && (Skakiera[(6),(0)]->CompareTo("") == 0) )
		{
			m_OrthotitaKinisis = true;
			m_NomimotitaKinisis = true;
			Castling_Occured = true;
		}
	}

	// big castling

	if ((this->m_PlayerColor->CompareTo("White") == 0) && (m_StartingColumnNumber == 5) && (m_FinishingColumnNumber == 3) && (m_StartingRank == 1) && (m_FinishingRank == 1))
	{
		if ( (Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("White King") == 0) && (Skakiera[(0),(0)]->CompareTo("White Rook") == 0) && (Skakiera[(1),(0)]->CompareTo("") == 0) && (Skakiera[(2),(0)]->CompareTo("") == 0) && (Skakiera[(3),(0)]->CompareTo("") == 0) )
		{
			m_OrthotitaKinisis = true;
			m_NomimotitaKinisis = true;
			Castling_Occured = true;
		}
	}


	///////////////////////////
	// black castling
	///////////////////////////

	// small castling

	if ((this->m_PlayerColor->CompareTo("Black") == 0) && (m_StartingColumnNumber == 5) && (m_FinishingColumnNumber == 7) && (m_StartingRank == 8) && (m_FinishingRank == 8))
	{
		if ( (Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black King") == 0) && (Skakiera[(7),(7)]->CompareTo("Black Rook") == 0) && (Skakiera[(5),(7)]->CompareTo("") == 0) && (Skakiera[(6),(7)]->CompareTo("") == 0) )
		{
			m_OrthotitaKinisis = true;
			m_NomimotitaKinisis = true;
			Castling_Occured = true;
		}
	}

	// big castling

	if ((this->m_PlayerColor->CompareTo("Black") == 0) && (m_StartingColumnNumber == 5) && (m_FinishingColumnNumber == 3) && (m_StartingRank == 8) && (m_FinishingRank == 8))
	{
		if ( (Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)]->CompareTo("Black King") == 0) && (Skakiera[(0),(7)]->CompareTo("Black Rook") == 0) && (Skakiera[(1),(7)]->CompareTo("") == 0) && (Skakiera[(2),(7)]->CompareTo("") == 0) && (Skakiera[(3),(7)]->CompareTo("") == 0) )
		{
			m_OrthotitaKinisis = true;
			m_NomimotitaKinisis = true;
			Castling_Occured = true;
		}
	}

	// redraw the chessboard
	if ( (m_OrthotitaKinisis == true) && (m_NomimotitaKinisis == true) )
	{

	// game moves on by 1 move (this happens only when the player plays,
	// so as to avoid increasing the game moves every half-move!)
	if(this->m_PlayerColor->CompareTo("White") == 0)
		Move = Move + 1;

	// erase initial square
	Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = "";

	// go to destination square
	Skakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = MovingPiece;


	//////////////////////////////////////////////////////////
	// check for en passant
	//////////////////////////////////////////////////////////
	if( enpassant_occured == true )
	{
		if( this->m_PlayerColor->CompareTo("White") == 0 )
			Skakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 - 1)] = "";
		else if( this->m_PlayerColor->CompareTo("Black") == 0 )
			Skakiera[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1 + 1)] = "";
	}


	////////////////////////////////////////////////////////////////////
	// record possible sqaure when the next one playing will
	// be able to perform en passant
	////////////////////////////////////////////////////////////////////
	if( (this->m_StartingRank == 2) && (this->m_FinishingRank == 4) )
	{
		enpassant_possible_target_rank = m_FinishingRank - 1;
		enpassant_possible_target_column = m_FinishingColumnNumber;
	}
	else if( (this->m_StartingRank == 7) && (this->m_FinishingRank == 5) )
	{
		enpassant_possible_target_rank = m_FinishingRank + 1;
		enpassant_possible_target_column = m_FinishingColumnNumber;
	}
	else
	{
		// invalid value for enpassant move (= enpassant not possible in the next move)
		enpassant_possible_target_rank = -9;
		enpassant_possible_target_column = -9;
	}

	// check if castling occured (so as to move the rook next to the
	// moving king)
	if (Castling_Occured == true)
	{
		
		if (m_PlayerColor->CompareTo("White") == 0)
		{
			if (Skakiera[(6),(0)]->CompareTo("White King") == 0)
			{
				Skakiera[(5),(0)] = "White Rook";
				Skakiera[(7),(0)] = "";
				//Console::WriteLine( "Ο λευκός κάνει μικρό ροκε." ); // Changed in version 0.5
			}
			else if (Skakiera[(2),(0)]->CompareTo("White King") == 0)
			{
				Skakiera[(3),(0)] = "White Rook";
				Skakiera[(0),(0)] = "";
				//Console::WriteLine( "Ο λευκός κάνει μεγάλο ροκε." ); // Changed in version 0.5
			}
		}
		else if (m_PlayerColor->CompareTo("Black") == 0)
		{
			if (Skakiera[(6),(7)]->CompareTo("Black King") == 0)
			{
				Skakiera[(5),(7)] = "Black Rook";
				Skakiera[(7),(7)] = "";
				//Console::WriteLine( "Ο μαύρος κάνει μικρό ροκε." ); // Changed in version 0.5
			}
			else if (Skakiera[(2),(7)]->CompareTo("Black King") == 0)
			{
				Skakiera[(3),(7)] = "Black Rook";
				Skakiera[(0),(7)] = "";
				//Console::WriteLine( "Ο μαύρος κάνει μεγάλο ροκε." ); // Changed in version 0.5
			}
		}

		// restore the Castling_Occured variable to false, so as to avoid false castlings in the future!
		Castling_Occured = false;

	}


	//////////////////////////////////////////////////////////
	// does a pawn needs promotion?
	//////////////////////////////////////////////////////////

	PawnPromotion();

	if ((m_PlayerColor->CompareTo("White") == 0) || (m_PlayerColor->CompareTo("Black") == 0))
		m_WhoPlays = "HY";                       

	// it is the other color's turn to play
	if (m_WhichColorPlays->CompareTo("White") == 0)   
		m_WhichColorPlays = "Black";                  
	else if (m_WhichColorPlays->CompareTo("Black") == 0)
		m_WhichColorPlays = "White";

	// restore variable values to initial values
	m_StartingColumn = "";
	m_FinishingColumn = "";
	m_StartingRank = 1;
	m_FinishingRank = 1;

	}
	
	else
	{
		Console::WriteLine("INVALID MOVE!");
		Skakiera[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = MovingPiece;
		MovingPiece = "";
		m_WhoPlays = "Human";
	}



	/////////////////////////////////////////////
	// CHECK MESSAGE
	/////////////////////////////////////////////

	WhiteKingCheck = CheckForWhiteCheck(Skakiera);
	BlackKingCheck = CheckForBlackCheck(Skakiera);

	if ((WhiteKingCheck==true)||(BlackKingCheck==true))
	{
		Console::WriteLine("CHECK!");
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// if it is the turn of the HY to play, then call the respective
	// HY Thought function
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (m_WhoPlays->CompareTo("HY") == 0)
	{
		Move_Analyzed = 0;
		Stop_Analyzing = false;
		First_Call = true;
		Best_Move_Found = false;
		Who_Is_Analyzed = "HY";
		ComputerMove(Skakiera);
	}



	}

		
void PawnPromotion(void)                     
{
	for (i = 0; i <= 7; i++)
	{
			
			if (Skakiera[(i),(0)]->CompareTo("Black Pawn") == 0)
			{

				if (m_WhoPlays->CompareTo("Human") == 0)
				{
					///////////////////////////
					// promote pawn
					///////////////////////////

					Console::WriteLine("");

					Console::WriteLine("Promote your pawn to: 1. Queen, 2. Rook, 3. Knight, 4. Bishop");
					Console::Write("CHOOSE (1-4): ");
					choise_of_user = Int32::Parse(Console::ReadLine());

					switch(choise_of_user)
					{
					case 1:
						Skakiera[(i),(0)] = "Black Queen";
						break;

					case 2:
						Skakiera[(i),(0)] = "Black Rook";
						break;

					case 3:
						Skakiera[(i),(0)] = "Black Knight";
						break;

					case 4:
						Skakiera[(i),(0)] = "Black Bishop";
						break;
					};
				}

			}

			if (Skakiera[(i),(7)]->CompareTo("White Pawn") == 0)
			{
				if (m_WhoPlays->CompareTo("Human") == 0)
				{
					///////////////////////////
					// promote pawn
					///////////////////////////

					Console::WriteLine("");

					Console::WriteLine("Promote your pawn to: 1. Queen, 2. Rook, 3. Knight, 4. Bishop");
					Console::Write("CHOOSE (1-4): ");
					choise_of_user = Int32::Parse(Console::ReadLine());

					switch(choise_of_user)
					{
					case 1:
						Skakiera[(i),(0)] = "White Queen";
						break;

					case 2:
						Skakiera[(i),(0)] = "White Rook";
						break;

					case 3:
						Skakiera[(i),(0)] = "White Knight";
						break;

					case 4:
						Skakiera[(i),(0)] = "White Bishop";
						break;
					};
				}

			}

	}
}

	
void Starting_position(void)                 
{  
		// TODO: Add your control notification handler code here

	for(int a=0;a<=7;a++)
	{
		for(int b=0;b<=7;b++)
		{
			Skakiera[(a),(b)] = "";
		}
	}

			Skakiera[(0),(0)] = "White Rook";
			Skakiera[(0),(1)] = "White Pawn";
			Skakiera[(0),(6)] = "Black Pawn";
			Skakiera[(0),(7)] = "Black Rook";
			Skakiera[(1),(0)] = "White Knight";
			Skakiera[(1),(1)] = "White Pawn";
			Skakiera[(1),(6)] = "Black Pawn";
			Skakiera[(1),(7)] = "Black Knight";
			Skakiera[(2),(0)] = "White Bishop";
			Skakiera[(2),(1)] = "White Pawn";
			Skakiera[(2),(6)] = "Black Pawn";
			Skakiera[(2),(7)] = "Black Bishop";
			Skakiera[(3),(0)] = "White Queen";
			Skakiera[(3),(1)] = "White Pawn";
			Skakiera[(3),(6)] = "Black Pawn";
			Skakiera[(3),(7)] = "Black Queen";
			Skakiera[(4),(0)] = "White King";
			Skakiera[(4),(1)] = "White Pawn";
			Skakiera[(4),(6)] = "Black Pawn";
			Skakiera[(4),(7)] = "Black King";
			Skakiera[(5),(0)] = "White Bishop";
			Skakiera[(5),(1)] = "White Pawn";
			Skakiera[(5),(6)] = "Black Pawn";
			Skakiera[(5),(7)] = "Black Bishop";
			Skakiera[(6),(0)] = "White Knight";
			Skakiera[(6),(1)] = "White Pawn";
			Skakiera[(6),(6)] = "Black Pawn";
			Skakiera[(6),(7)] = "Black Knight";
			Skakiera[(7),(0)] = "White Rook";
			Skakiera[(7),(1)] = "White Pawn";
			Skakiera[(7),(6)] = "Black Pawn";
			Skakiera[(7),(7)] = "Black Rook";

			m_WhichColorPlays = "White";
}


// 2009 version 1 change
void HumanMove(array<String^, 2>^ Skakiera_Human_Thinking) {
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("HumanMove called");
	//	Console::ReadKey();
	//}

	// 2009 version 1 change
	//if (First_Call_Human_Thought == true)
	//{
	//		// store initial chessboard position
	//		for (iii_Human = 0; iii_Human <= 7; iii_Human++)
	//		{
	//			for (jjj_Human = 0; jjj_Human <= 7; jjj_Human++)
	//			{
	//				Skakiera_Human_Thinking[(iii_Human),(jjj_Human)] = Skakiera_Human_Thinking_init[(iii_Human),(jjj_Human)];
	//				Skakiera_Human_Move_0[(iii_Human),(jjj_Human)] = Skakiera_Human_Thinking_init[(iii_Human),(jjj_Human)];
	//			}
	//		}
	//}
	
	
	// scan chessboard -> find a piece of the human player -> move to all
	// possible squares -> check correctness and legality of move -> if
	// all ok then measure the move's score -> do the best move and handle
	// over to the ComputerMove function to continue analysis in the next
	// move (deeper depth...)
	int ww;
	int rr;
	int www1;
	int rrr1;

	for (www1 = 0; www1 <= 7; www1++)
	{
		for (rrr1 = 0; rrr1 <= 7; rrr1++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("Black King") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("Black Queen") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("Black Rook") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("Black Knight") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("White King") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("White Queen") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("White Rook") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("White Knight") == 0) || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("White Bishop") == 0)  || (Skakiera_Human_Thinking[(www1),(rrr1)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) )
	{
		for( ww=0; ww<=7; ww++)
		{
			for( rr=0; rr<=7; rr++)
			{
				//try{

				// HUO DEBUG
				// Να αλλάξω το FinishingColumn / Rank έτσι ώστε να παίρνει όλες τις τιμές (-7 έως +7)!
				MovingPiece = Skakiera_Human_Thinking[(www1),(rrr1)];
				m_StartingColumnNumber = www1+1;
				m_FinishingColumnNumber = ww+1; //www1+ww;
				m_StartingRank = rrr1+1;
				m_FinishingRank = rr+1; // rrr1+rr;

				// HUO DEBUG
				//if((m_StartingColumnNumber == 4) && (m_StartingRank == 7))
				//{
				//	if((m_FinishingColumnNumber == 1) && (m_FinishingRank == 4))
				//	{
				//		Console::WriteLine("test ok!");
				//	}
				//}

				// check the move
				CheckHumanMove(Skakiera_Human_Thinking);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO HumanMove");
				//	Console::ReadKey();
				//}
			}
		}
	}

		}
	}

	// perform the best move of human opponent
	MovingPiece = Skakiera_Human_Thinking[(Best_Move_Human_StartingColumnNumber - 1),(Best_Move_Human_StartingRank - 1)];
	Skakiera_Human_Thinking[(Best_Move_Human_StartingColumnNumber - 1),(Best_Move_Human_StartingRank - 1)] = "";
	Skakiera_Human_Thinking[(Best_Move_Human_FinishingColumnNumber - 1),(Best_Move_Human_FinishingRank - 1)] = MovingPiece;

	// call ComputerMove for the HY throught process to continue
	Move_Analyzed = Move_Analyzed + 1;

	Who_Is_Analyzed = "HY";

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			Skakiera_Move_After[(i),(j)] = Skakiera_Human_Thinking[(i),(j)];
		}
	}

    //////////////////////////////////////////////////////////////////////////////
    // UNCOMMENT TO (TRY TO) USE THREADS...
    //////////////////////////////////////////////////////////////////////////////
    // Issues with threads: You must have a seperate ComputerMove function for each
    // level of thinking (that is why I have the ComputerMove2,4,6 and 8 functions).
    // If you try to have only one ComputerMove function and call it will the thread
    // calling code depicted below, you will end up calling a new ComputerMove function
    // every time you start a new thread, thus having the program not thinking! :)
    // HOWEVER, I have found out that the use of threads is not going to work after
    // all because each branch of thinking (e.g. for ThinkingDepth = 4: ComputerMove2,
    // HumanMove, ComputerMove4, HumanMove, found the best move for that variant, go
    // back to the loop of ComputerMove2, HumanMove, ComputerMove4, HumanMove, found
    // the best move for that variant etc) must be completed sequentially. If you
    // attempt to create a new thread each time the ComputerMove4 needs to be called,
    // then the computer will lose the proper order of thinking (which is controlled
    // by the ComputerMove4 "for" loop) and the program will not function correctly.
    /////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////
	// C# version
    //if (Move_Analyzed == 2)
    //{
    //    HuoChess_main newChess = new HuoChess_main();
    //    // Creating a Thread reference object in one line from a member method
    //    Thread thr2 = new Thread(new ParameterizedThreadStart(HuoChess_main.ComputerMove2));
    //    //HuoChess_main.ComputerMove2(Skakiera_Move_After);
    //    thr2.Start(Skakiera_Move_After);
    //    Console.WriteLine("New thread started (Move analyzed = 2)");
    //}
    //else if (Move_Analyzed == 4)
    //{
    //    HuoChess_main newChess = new HuoChess_main();
    //    // Creating a Thread reference object in one line from a member method
    //    Thread thr2 = new Thread(new ParameterizedThreadStart(HuoChess_main.ComputerMove2));
    //    //HuoChess_main.ComputerMove4(Skakiera_Move_After);
    //    thr2.Start(Skakiera_Move_After);
    //    Console.WriteLine("New thread started (Move analyzed = 4)");
    //}
	////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////
	// C++ version
	//HuoChess_main ^newChess = gcnew HuoChess_main();
	// Creating a Thread reference object in one line from a member method
	//Thread ^thr2 = gcnew Thread(gcnew ParameterizedThreadStart(newChess, &HuoChess_main::ComputerMove2));
	//thr2->Start(Skakiera_Move_After);
	//Console::WriteLine("New thread started");
	////////////////////////////////////////////////////////////////////////

            /////////////////////
            // 2009 v4 change
            /////////////////////
            if (Move_Analyzed == 2)
                ComputerMove2(Skakiera_Move_After);
            else if (Move_Analyzed == 4)
                ComputerMove4(Skakiera_Move_After);
            else if (Move_Analyzed == 6)
                ComputerMove6(Skakiera_Move_After);
            else if (Move_Analyzed == 8)
                ComputerMove8(Skakiera_Move_After);
            else if (Move_Analyzed == 10)
                ComputerMove10(Skakiera_Move_After);
            else if (Move_Analyzed == 12)
                ComputerMove12(Skakiera_Move_After);
            else if (Move_Analyzed == 14)
                ComputerMove14(Skakiera_Move_After);
            else if (Move_Analyzed == 16)
                ComputerMove16(Skakiera_Move_After);
            else if (Move_Analyzed == 18)
                ComputerMove18(Skakiera_Move_After);
            else if (Move_Analyzed == 20)
                ComputerMove20(Skakiera_Move_After);
            /////////////////////
            // 2009 v4 change
            /////////////////////

}


void CheckHumanMove(array<String^, 2>^ CMSkakiera_Human_Thinking) {
	number_of_moves_analyzed++;

	// Necessary values for variables for the ElegxosOrthotitas (check move correctness) and
	// ElegxosNomimotitas (check move legality) function to...function properly.
	m_WhoPlays = "Human";
	m_WrongColumn = false;
	MovingPiece = CMSkakiera_Human_Thinking[(m_StartingColumnNumber - 1),(m_StartingRank - 1)];

	m_OrthotitaKinisis = ElegxosOrthotitas(CMSkakiera_Human_Thinking);
	m_NomimotitaKinisis = ElegxosNomimotitas(CMSkakiera_Human_Thinking);

	// restore normal value of m_WhoPlays
	m_WhoPlays = "HY";

	// if all ok, then do the move and measure it
	if ((m_OrthotitaKinisis == true)&&(m_NomimotitaKinisis == true))
	{
		// HUO DEBUG
		// Added in version 0.5
		// If Human can eat the Queen of the computer, then the move has a penalty!
		//if(m_PlayerColor->CompareTo("White") == 0)
		//{
		//	if(CMSkakiera_Human_Thinking[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->Equals("Black Queen") == true)
		//		this->LoseQueen_penalty = true;
		//}
		//else if (m_PlayerColor->CompareTo("Black") == 0)
		//{
		//	if(CMSkakiera_Human_Thinking[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)]->Equals("White Queen") == true)
		//	{
		//		this->LoseQueen_penalty = true;
		//		Console::WriteLine("Found move that eats the queen!");
		//	}
		//}

		// HUO DEBUG
		//if((m_StartingColumnNumber == 4) && (m_StartingRank == 7))
		//{
		//	if((m_FinishingColumnNumber == 1) && (m_FinishingRank == 4))
		//	{
		//		int test;
		//		Console::WriteLine("test ok!");
		//	}
		//}

		// do the move
		ProsorinoKommati = CMSkakiera_Human_Thinking[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)];
		CMSkakiera_Human_Thinking[(m_StartingColumnNumber - 1),(m_StartingRank - 1)] = "";
		CMSkakiera_Human_Thinking[(m_FinishingColumnNumber - 1),(m_FinishingRank - 1)] = MovingPiece;

		///////////////////////////////////////////////////////////////////
		// is the king still under check? if yes, then we have mate!
		///////////////////////////////////////////////////////////////////
		Possible_mate = false;

		if( Human_is_in_check == true )
		{
		WhiteKingCheck = CheckForWhiteCheck(CMSkakiera_Human_Thinking);
		if ( (this->m_PlayerColor->CompareTo("White") == 0) && (WhiteKingCheck == true) )
			Possible_mate = true;

		BlackKingCheck = CheckForBlackCheck(CMSkakiera_Human_Thinking);
		if ( (this->m_PlayerColor->CompareTo("Black") == 0) && (BlackKingCheck == true) )
			Possible_mate = true;
		}


		// if this is the first time the function is called, then store
		// the move no matter how auful!
		if (First_Call_Human_Thought == true)
		{
			Best_Move_Human_StartingColumnNumber = m_StartingColumnNumber;
			Best_Move_Human_FinishingColumnNumber = m_FinishingColumnNumber;
			Best_Move_Human_StartingRank = m_StartingRank;
			Best_Move_Human_FinishingRank = m_FinishingRank;

			CountScore_Human(CMSkakiera_Human_Thinking);
			Best_Human_Move_Score = Current_Human_Move_Score;
			
			First_Call_Human_Thought = false;
			Best_Human_Move_Found = true;
		}

		// record the move with the best score
		CountScore_Human(CMSkakiera_Human_Thinking);
		if ( ((m_PlayerColor->CompareTo("Black") == 0)&&(Current_Human_Move_Score < Best_Human_Move_Score)) || ((m_PlayerColor->CompareTo("White") == 0)&&(Current_Human_Move_Score > Best_Human_Move_Score)) )
		{
			Best_Move_Human_StartingColumnNumber = m_StartingColumnNumber;
			Best_Move_Human_FinishingColumnNumber = m_FinishingColumnNumber;
			Best_Move_Human_StartingRank = m_StartingRank;
			Best_Move_Human_FinishingRank = m_FinishingRank;
			Best_Human_Move_Score = Current_Human_Move_Score;
		}

		////////////////////////////////////////////////////////////////////////
		// restore pieces in the initial position
		////////////////////////////////////////////////////////////////////////
        // 2009 version 1 change
		//for (i = 0; i <= 7; i++)
		//{
		//	for (j = 0; j <= 7; j++)
		//	{
		//		Skakiera_Human_Thinking[(i),(j)] = Skakiera_Human_Move_0[(i),(j)];
		//	}
		//}
		}

}


// HY Thought Process:
// Depth 0 (Move_Analyzed = 0): First half move analyzed - First HY half move analyzed
// Depth 1 (Move_Analyzed = 1): Second half move analyzed - First human half move analyzed
// Depth 2 (Move_Analyzed = 2): Thirf half move analyzed - Second HY half move analyzed
// etc

// Functions for analyzing the HY Thought in depth...
// ...of the 3rd half move (ComputerMove2)
// ...of the 5th half move (ComputerMove4)
// ...of the 7th half move (ComputerMove6)
// ...of the 9th half move (ComputerMove8)

void ComputerMove2(array<String^, 2>^ Skakiera_Thinking_2)              
{   
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove2 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	// UNCOMMENT THE try...catch block in case you attempt to use threads (see HumanMove code),
	// so as to find out the problems with that approach...
	//try{

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_2[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_2[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_2);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove2");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}

	//}
	//catch(Exception^ huo_exception)
	//{
	//	Console::WriteLine(String::Concat("Πρόβλημα: ", huo_exception->ToString(),"\nWho is analyzed: ", Who_Is_Analyzed, "\nSkakiera_Thinking_2[(iii),(jjj)]: ", Skakiera_Thinking_2[(iii),(jjj)]->ToString()));
	//	Console::ReadKey();
	//}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_2!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

////////////////////////////////////////////////////////////////////////////////////
// UNCOMMENT THE FOLLOWING (ComputerMove4, ComputerMove6 and ComputerMove8),
// along with the respective code that calls them at HumanMove to have extra
// thinking depths!
// Remember to also uncomment the part in the beginning that asks from the
// user to set a thinking depth!
////////////////////////////////////////////////////////////////////////////////////

void ComputerMove4(array<String^, 2>^ Skakiera_Thinking_4)              
{   
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove4 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_4[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_4[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_4);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove4");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_4!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove6(array<String^, 2>^ Skakiera_Thinking_6)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove6 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_6[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_6[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_6);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove6");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_6!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove8(array<String^, 2>^ Skakiera_Thinking_8)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove8 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_8[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_8[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_8);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove8");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_8!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove10(array<String^, 2>^ Skakiera_Thinking_10)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove10 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_10[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_10[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_10);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove10");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_10!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove12(array<String^, 2>^ Skakiera_Thinking_12)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove12 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_12[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_12[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_12);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove12");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_12!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove14(array<String^, 2>^ Skakiera_Thinking_14)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove14 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_14[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_14[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_14);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove14");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_14!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove16(array<String^, 2>^ Skakiera_Thinking_16)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove16 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_16[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_16[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_16);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove16");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_16!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove18(array<String^, 2>^ Skakiera_Thinking_18)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove18 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_18[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_18[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_18);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove18");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_18!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}

void ComputerMove20(array<String^, 2>^ Skakiera_Thinking_20)              
{     
	// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
	//if(huo_debug == true)
	//{
	//	Console::WriteLine("ComputerMove20 called");
	//	Console::ReadKey();
	//}
	//////////////////////////////////////////////////////////////////
	// SEE RESPECTIVE ComputerMove function for english comments
	//////////////////////////////////////////////////////////////////

	// Θέτουμε την τιμή της Mate σε false για να μην υπάρξει λανθασμένος συναγερμός για ματ.
	// Αν στη συνέχεια διαπιστωθεί ότι υπάρχει ματ (βλ. συνάρτηση CheckMove), τότε η τιμή της Mate θα γίνει true.

	Mate = false;

	// Δήλωση μεταβλητών που χρησιμοποιούνται στο βρόγχο "for"
	// (δεν μπορεί να χρησιμοποιηθούν οι μεταβλητές i και j διότι αυτές οι
	// μεταβλητές είναι καθολικές και δημιουργείται πρόβλημα κατά την
	// επιστροφή στην ComputerMove από την CheckMove

	int iii;
	int jjj;

	// Έλεγχος του αν ο υπολογιστής έχει σκεφτεί όσο του έχει βάλει ο χρήστης να σκέφτεται (το σήμα " > " μπήκε διότι το πρόγραμμα αυξάνει την τιμή της Move_Analyzed ΠΡΙΝ αναλύσει την κίνηση - βλ. μετά)

	if (Move_Analyzed > Thinking_Depth)
		Stop_Analyzing = true;


	if (Stop_Analyzing == false)
	{

	// Σκανάρισμα της σκακιέρας: Όταν εντοπίζεται κάποιο κομμάτι του υπολογιστή,
	// θα υπολογίζονται ΟΛΕΣ οι πιθανές κινήσεις του προς κάθε κατεύθυνση, ακόμα
	// και αυτές που δεν μπορεί να κάνει το κομμάτι. Στη συνέχεια, με τη βοήθεια
	// των συναρτήσεων ElegxosNomimotitas και ElegxosOrthotitas θα ελέγχεται το
	// αν η κίνηση είναι ορθή και νόμιμη. Αν είναι, η εν λόγω κίνηση θα γίνεται
	// προσωρινά στη σκακιέρα και θα καταγράφεται το σκορ της νέας θέσης που
	// προέκυψε

	// ΣΗΜΕΙΩΣΗ: Σε όλες τις στήλες και τις οριζόντιους προστίθεται η μονάδα (+1)
	// διότι πρέπει να μετατραπούν από το "σύστημα" μέτρησης "0-7" (που χρησιμο-
	// ποιείται στο παρακάτω "for inext" αλλά και στο συμβολισμό του πίνακα
	// Skakiera) στο σύστημα μέτρησης "1-8" το οποίο χρησιμοποιείται στις
	// μεταβλητές Starting/Finishing_Column/Rank σε όλο το υπόλοιπο πρόγραμμα.

	for (iii = 0; iii <= 7; iii++)
	{
		for (jjj = 0; jjj <= 7; jjj++)
		{

	if ( ((Who_Is_Analyzed->CompareTo("HY") == 0) && ( ( ((Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) || ( ((Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) ) ) || ( (Who_Is_Analyzed->CompareTo("Human") == 0) && ( ( ((Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White King") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Queen") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Rook") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Knight") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Bishop") == 0)  || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("White Pawn") == 0)) && (m_PlayerColor->CompareTo("White") == 0) ) || ( ((Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black King") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Queen") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Rook") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Knight") == 0) || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Bishop") == 0)  || (Skakiera_Thinking_20[(iii),(jjj)]->CompareTo("Black Pawn") == 0)) && (m_PlayerColor->CompareTo("Black") == 0) ) ) ))
	{


		for( int w=0; w<=7; w++)
		{
			for( int r=0; r<=7; r++)
			{
				MovingPiece = Skakiera_Thinking_20[(iii),(jjj)];
				m_StartingColumnNumber = iii+1;
				m_FinishingColumnNumber = w+1;
				m_StartingRank = jjj+1;
				m_FinishingRank = r+1;

				// Έλεγχος της κίνησης
				CheckMove(Skakiera_Thinking_20);
				// UNCOMMENT TO SHOW INNER THINKING MECHANISM!
				//if(huo_debug == true)
				//{
				//	Console::WriteLine("RETURNED TO ComputerMove20");
				//	Console::ReadKey();
				//}
			}
		}

	}


		}
	}


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ΚΑΤΑΓΡΑΦΗ ΤΟΥ ΑΝ ΥΠΑΡΧΕΙ ΜΑΤ.
	// Ο ΕΛΕΓΧΟΣ γίνεται αναλύοντας το κατά πόσο υπάρχει ή όχι κάποια ορθή και νόμιμη κίνηση η οποία αν
	// γίνει δεν αφήνει το βασιλιά υπό την απειλή σαχ, στη συνάρτηση CheckMove.
	// Προσοχή θέλει το γεγονός ότι η ΚΑΤΑΓΡΑΦΗ γίνεται μόνο κατά τον έλεγχο της πρώτης μισής κίνησης που
	// σκέφτεται ο υπολογιστής (ήτοι για Move_Analyzed == 0) διότι αν ο υπολογιστής σκεφτεί και μία κίνηση
	// ακόμα, θα θεωρήσει νόμιμο να διώξει το βασιλιά του από το σαχ και άρα δεν θα καταλάβει ότι υπάρχει
	// ματ. Η Move_Analyzed == 0 διασφαλίζει ότι αν βρεθεί ότι δεν υπάρχει καμία ΠΡΩΤΗ κίνηση στη σκακιέρα
	// η οποία να μπορεί να βγάλει το βασιλιά από το σαχ, τότε έχουμε ματ.
	// Η ύπαρξη και της προϋπόθεσης να έχει διαπιστωθεί πως ένας βασιλιάς είναι υπό την απειλή σαχ,
	// διασφαλίζει το πρόγραμμα από λάθος συναγερμούς ματ.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((Move_Analyzed == 0) && ((WhiteKingCheck == true)||(BlackKingCheck == true)))
	{
	
		// Αν ο υπολογιστής δεν κατόρθωσε να βρει καμία νόμιμη κίνηση να κάνει εξαιτίας του ότι είναι ματ

		if (Best_Move_Found == false)
		{
			Mate = true;

			if (m_PlayerColor->CompareTo("White") == 0)
				Console::WriteLine("Black is in mate!");
			else if (m_PlayerColor->CompareTo("Black") == 0)
				Console::WriteLine("White is in mate!");
		}

	}

	Move_Analyzed = Move_Analyzed - 2;
	Who_Is_Analyzed = "HY";

	// DEBUGGING CODE
	// Use only for solving application problems!
	//this->sw_hy_thought->WriteLine("--------------- MOVE ANALYZED REDUCED BY 2! ----------------");

	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			// Προσοχή: Εδώ χρησιμοποιείται η Skakiera_Thinking και όχι η Skakiera_Thinking_20!
			Skakiera_Thinking[i,j] = Skakiera_Move_0[i,j];
		}
	}

}


};


int main(array<System::String ^> ^args)
{
    // TODO: Please replace the sample code below with your own.

	HuoChess_main^ huo = gcnew HuoChess_main();
	huo->Game();

    return 0;
}



