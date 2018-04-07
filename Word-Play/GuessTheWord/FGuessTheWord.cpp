#include "stdafx.h"
#include <ctime>
#include <iostream>
#include "FGuessTheWord.h"
BullCowCount BCCount;
int FGuessTheWord::GetMaxTries() const
{
	return MaxTries;
}

int FGuessTheWord::GetCurrentTry() const
{
	return CurrentTry;
}

int FGuessTheWord::GetTargetLength() const
{
	return TargetLength;
}

bool FGuessTheWord::GetIsGameWon() const
{
	return IsGameWon;
}

std::string FGuessTheWord::GetTargetWord() const
{
	return TargetWord;
}

void FGuessTheWord::PrintIntro()
{
	std::cout << " Welcome to the game \n can you guess the " << GetTargetLength() << " letter isogram \n";
}

void FGuessTheWord::Reset()
{	
	IsGameWon = false;
	CurrentTry = 1;
	switch (MainMenuChoice)
	{case 1:
		TargetWord = ThreeLetterIsograms[(GenerateNumber()%20)];
		MaxTries = 5;
		break;
	case 2:
		TargetWord = FourLetterIsograms[(GenerateNumber()%32)];
		MaxTries = 7;
		break;
	case 3:
		TargetWord = FiveLetterIsograms[(GenerateNumber()%10)];
		MaxTries = 10;
		break;
	case 4:
		TargetWord = SixLetterIsograms[(GenerateNumber()%25)];
		MaxTries = 12;
		break;
	case 5:
		TargetWord = SevenLetterIsograms[(GenerateNumber()%8)];
		MaxTries = 14;
		break;
	default:std::cout << "Invalid Choice\n";
		break;
	}
	TargetLength = TargetWord.length();
}

int FGuessTheWord::GenerateNumber()
{
	srand(time(0));
	return (rand());
}

bool FGuessTheWord::ValidateGuess(std::string Guess )
{
	if (!IsCorrectLength(Guess))
	{
		std::cout << " Your Guess is of incorrect length playa \n";
		return false;
	}
	if (!IsLowercase(Guess))
	{
		std::cout << " Your guess is not in lowercase letters\n ";
		return false;
	}
	if (!IsIsogram(Guess))
	{
		std::cout << " your guess is not an isogram \n";
		return false;
	}
	return true;
}

bool FGuessTheWord::IsLowercase(std::string Guess)
{
	for (int i = 0; i < (Guess.length()); i++)
	{
		if (isupper(Guess[i]))
		{
			return false;
		}
	}
	return true;
}

bool FGuessTheWord::IsIsogram(std::string Guess)
{	
	for (int i = 0; i < (Guess.length()-1); i++)
	{
		for (int j = i + 1; j < (Guess.length()); j++)
		{
			if (Guess[i] == Guess[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool FGuessTheWord::IsCorrectLength(std::string guess)
{
	if (guess.length() == TargetLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

BullCowCount FGuessTheWord::GetBullCowCount(std::string Guess)
{
	BCCount.Bulls = 0;
	BCCount.Cows = 0;
	for (int GuessIterator = 0; GuessIterator < TargetLength; GuessIterator++)
	{
		for (int TargetIterator = 0; TargetIterator < TargetLength; TargetIterator++)
		{
			if (Guess[GuessIterator] == TargetWord[TargetIterator])
			{
				if (GuessIterator == TargetIterator)
				{
					BCCount.Bulls++;
				}
				else
				{
					BCCount.Cows++;
				}
			}
		}
	}

	if (PlayerGuess == TargetWord)
	{
		IsGameWon = true;
	}
	else
	{
		IsGameWon = false;
	}
	return BCCount;
}

void FGuessTheWord::InputPlayerGuess()
{
	std::cout << " Try " << GetCurrentTry() << " of " << GetMaxTries() << std::endl;
	std::cin >> PlayerGuess;
	//ValidateGuess(PlayerGuess);
	if (ValidateGuess(PlayerGuess))
	{
		CurrentTry++;
		GetBullCowCount(PlayerGuess);
		std::cout << " Bulls = " << BCCount.Bulls << "\n" << " Cows = " << BCCount.Cows << "\n";
	}
	else
	{
		std::cout << " Invalid Guess ! \n";
	}
}

void FGuessTheWord::SummariseGame() const
{
	if (IsGameWon)
	{
		std::cout << " Congratulations You Won!! \n";
	}
	else
	{
		std::cout << " The word was "<<GetTargetWord() <<" Better Luck Next Time \n";
	}
}

bool FGuessTheWord::AskToPlayAgain()
{
	std::string Input;
	std::cout << " Do you want to play again (Y/N) \n";
	std::cin >> Input;
	if ((Input[0] == 'Y') || (Input[0] == 'y'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void FGuessTheWord::MainMenu()
{
	system("cls");
	std::cout << "--------Welcome to Word-Play-------\n ";
	std::cout << " Choose one from the following\n";
	std::cout << " 1. THREE Letters\n";
	std::cout << " 2. FOUR Letters\n";
	std::cout << " 3. FIVE Letters\n";
	std::cout << " 4. SIX Letters\n";
	std::cout << " 5. SEVEN Letters\n";
	std::cin >> MainMenuChoice;
}




