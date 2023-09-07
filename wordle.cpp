#include<bits/stdc++.h>

using namespace std;
void
delay (unsigned int mseconds)
{

  clock_t goal = mseconds + clock ();
  while (goal > clock ());
}

string
wordDatabase ()
{
  string words[101] = {
    "apple", "baker", "camel", "dwarf", "eagle", "fudge", "ghost", "honey",
      "inbox", "jumbo",
    "kiosk", "lemon", "mango", "noble", "oasis", "panda", "queen", "rumba",
      "salsa", "tango",
    "umbra", "vixen", "waltz", "xenon", "yacht", "zebra", "abide", "bento",
      "cabin", "daisy",
    "early", "fairy", "gaffe", "havoc", "ideal", "jolly", "karma", "laser",
      "mirth", "nymph",
    "ozone", "pilot", "quack", "raven", "scoop", "table", "umbra", "vocal",
      "witty", "xerox",
    "youth", "zebra", "abode", "beach", "cable", "darts", "eager", "fable",
      "gazer", "haste",
    "ideal", "jaded", "kneel", "latch", "merry", "nymph", "oasis", "panel",
      "quail", "risky",
    "saint", "table", "ultra", "vivid", "whale", "xenon", "yacht", "zebra",
      "abuse", "beast",
    "candy", "dance", "eager", "fancy", "giant", "happy", "icing", "joker",
      "knees", "latch",
    "magic", "noble", "ocean", "panel", "quack", "raise", "saint", "table",
      "ultra", "vocal"
  };
  srand (static_cast < unsigned int >(std::time (nullptr)));
  int randomIndex = std::rand () % 100;
  string word = words[randomIndex];
  return word;

}

void game_in_progress ();
void
rules ()
{
  cout << "Welcome to Wordle this is a word guessing game" << endl;
  cout << "You have to guess the five letter word in five tries " << endl;
  cout << "There are certain indicators that will help you deduce the word:- "
    << endl;
  cout <<
    "1. If the guessed letter is present in the word and at correct location then the index below is G. "
    << endl;
  cout <<
    "2. If the guessed letter is present in the word but not at correct location then the index below it is Y. "
    << endl;
  cout <<
    "3. If the guessed letter of the word is not present in the word then the index below it is B. "
    << endl;
  cout << "NOTE:-  Enter the letters in lowercase." << endl;
}

void
playgame ()
{
  cout << "To play the game press 1.\n";
  cout << "To know the rules press 2." << endl;
  delay (300);




  int x;
  cin >> x;
  switch (x)
    {
    case 1:
      cout << "Choosing the Word\n" << endl;
      game_in_progress ();

      break;
    case 2:
      cout << "Rules of the Wordle game:-" << endl;
      rules ();
      playgame ();
      break;

    default:
      cout << "\nERROR CMD NOT FOUND! TRY AGAIN" << endl;
      playgame ();
      break;


    }
}

string
fun (string guessed, string comp_generated)
{
  unordered_map < char, int >mp;
  string ans = "";
  // stored the index of every character of computer generated string.
  for (int i = 0; i < comp_generated.length (); i++)
    mp[comp_generated[i]] = i;
  for (int i = 0; i < comp_generated.length (); i++)
    {
      // if the character guessed is not present in the string of computer.
      if (mp.find (guessed[i]) == mp.end ())
	{
	  ans += 'B';
	}
      // if the character you guessed is on the correct index.
      else if (mp[guessed[i]] == i)
	ans += 'G';
      else
	ans += 'Y';
    }
  return ans;
}

void
game_in_progress ()
{
  //cout<<wordDatabase()<<"\n";

  string word = wordDatabase ();
  int t = 5, c = 0;

  while (t--)
    {
      cout << "Enter the word\n";
      string user_inpt;
      cin >> user_inpt;
      if (user_inpt.length () != 5)
	{
	  cout << "The given word is invalid! TRY AGAIN" << endl;
	  t++;
	}
      else
	{
	  cout << fun (user_inpt, word) << endl;
	  if (user_inpt == word)
	    {
	      cout << "!!!!!!  7 crore :D  !!!!!" << endl;
	      c++;
	      break;

	    }
	}
    }

  if (c == 0)
    cout << "Beta Tumse na hopayega :(" << endl;
  cout << "The Given Word was " << word;
}


int
main ()
{
  cout << "o       o  o-o  o--o  o-o   o    o--o\n";
  delay (100);
  cout << "|       | o   o |   | |  \\  |    |   \n";
  delay (100);
  cout << "o   o   o |   | O-Oo  |   O |    O-o \n";
  delay (100);
  cout << " \\ / \\ /  o   o |  \\  |  /  |    |   \n";
  delay (100);
  cout << "  o   o    o-o  o   o o-o   O---oo--o\n";
  delay (100);
  playgame ();

}
