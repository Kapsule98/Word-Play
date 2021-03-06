// trial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FGuessTheWord.h"
#include <iostream>
void PlayGame();
FGuessTheWord GameInstance;
int main()
{
	do { PlayGame(); }
	while (GameInstance.AskToPlayAgain());
	
	return 0;
}

void PlayGame()
{
	GameInstance.Reset();
	GameInstance.PrintIntro();
	while((!GameInstance.GetIsGameWon())&&((GameInstance.GetCurrentTry() <= GameInstance.GetMaxTries())))
	{
		GameInstance.InputPlayerGuess();
	}
	GameInstance.SummariseGame();
}
