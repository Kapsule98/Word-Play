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
	TargetWord = Isograms[GenerateNumber()];
	CurrentTry = 1;
	TargetLength = TargetWord.length();
	MaxTries = 10;
}

int FGuessTheWord::GenerateNumber()
{
	srand(time(0));
	return (rand()%105);
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




