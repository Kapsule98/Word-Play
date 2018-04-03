#pragma once
#include <string>

struct BullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};

class FGuessTheWord
{
public:
	int GetMaxTries() const;
	int GetCurrentTry() const;
	int GetTargetLength() const;
	bool GetIsGameWon() const;
	std::string GetTargetWord() const;
	void Reset();
	int GenerateNumber();
	bool ValidateGuess(std::string);
	void PrintIntro();
	bool IsLowercase(std::string);
	bool IsIsogram(std::string);
	bool IsCorrectLength(std::string);
	BullCowCount GetBullCowCount(std::string);
	void InputPlayerGuess();
	void SummariseGame() const;
	bool AskToPlayAgain();



private:
	int MaxTries;
	int CurrentTry;
	bool IsGameWon;
	std::string Isograms[105] = {"age","aim","air","bad","bit","bug","bus","cab","cup","dab","dam","gem","pea","lip","mud","nip","pun","pub","why",
								"zip","acid","amen","anti","axel","bags","bang","bank","cake","bean","dice","name","nail","neck","nest","numb","mail","make",
		"main","mate","mind","sack","salt","sand","scam","vane","vile","visa","yawn","your","zeal","zone","zero","dairy","delay","empty","magic","damsel",
	"entry","image","irony","quake","quirk","waiter","wanted","warden","warmup","yachts","zodiac","uphold","urgent","sacked","saying","savior","seldom","sermon"
	,"native","nimble","magpie","magot","mantle","marble","mosque","matrix","mosaic","motive","yourself","teaching","temporal","terminal","racquet","rainbow"
	,"peculiar","napthol","neutral","neural","network","labour","javelin","jeopardy","hacker","handsome","failure","zealous","obscure","octave"};
	std::string TargetWord ;
	int TargetLength;
	std::string PlayerGuess;

};