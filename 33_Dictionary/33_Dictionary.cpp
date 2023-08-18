#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;
/* Collection:
	Key (first): string - Value (second): list<string>
	"Run" - "Bigty", "Stvoryvaty", ....
	"Day" - "Gaerha", "Stvoryvaty", ....
	"Good" - "Hae", "Feragaethr", ....
*/

class Dictionary
{
private:
	string name;
	map<string, list<string>> words;
public:
	Dictionary(string name) :name(name) {}
	void Print()
	{
		cout << "Dictionary : " << name << endl;
		for (auto pair : words)
		{
			cout << pair.first << " - ";
			for (string t : pair.second)
			{
				cout << t << " , ";
			}
			cout << endl;
		}
	}
	void AddWord(string word,initializer_list< string> translate)
	{
		words.insert(make_pair(word, list<string>(translate)));
	}
	bool IsExists(string word)
	{
		return words.find(word) != words.end();
	}
	void AddTranslation(string word, string translation)
	{
		if(IsExists(word))
			words[word].push_back(translation);
	}
};
int main()
{
	Dictionary d("English-Ukrainian");
	d.AddWord("run", { "bigtu", "zapochatkkyvatu", "pochatu","pospishatu"});
	d.AddWord("mind", { "dymka", "dusha", "svidomist", "sens" });
	d.AddWord("bad", { "luxo", "poganuy", "borg", "dificit" });
	d.Print();
	//add translaion from keyboard
	string input = "";
	cout << "Enter word to add translatins: "; getline(cin, input);

	if (!d.IsExists(input))
		cout << "Word not found!\n";
	else
	{
		string translate = "";
		do
		{
			cout << "Enter translate: ";
			getline(cin, translate);
			if(!translate.empty())
				d.AddTranslation(input, translate);

		} while (!translate.empty());
	}
	
	d.Print();

	/*
	setlocale(LC_CTYPE, "ukr");

	map<string, list<string>> dic;

	string word = "run";
	list<string> meanings = list<string>({ "bigtu", "zapochatkkyvatu", "pochatu" });

	dic.insert(make_pair(word, meanings));

	dic.insert(make_pair("mind", list<string>({ "dymka", "dusha", "svidomist", "sens" })));
	dic.insert(make_pair("bad", list<string>({ "luxo", "poganuy", "borg", "dificit" })));
	dic.insert(make_pair("test", list<string>({ "mean1", "mean2", "mean3" })));

	for (string s : dic["mind"])
	{
		cout << s << " ";
	}

	//////////////////// add translate
	
	string input = "";
	cout << "Enter word to add translatins: "; getline(cin, input);

	if (dic.find(input) == dic.end())
		cout << "Word not found!\n";
	else
	{
		string translate = "";
		do
		{
			cout << "Enter translate: ";
			getline(cin, translate);
			dic[input].push_back(translate);

		} while (!translate.empty());
	}
	for (string s : dic["test"])
	{
		cout << s << " ";
	}
	/*
	////////////////////// check translate
	cout << "Enter word to translate: "; getline(cin, input);

	if (dic.find(input) == dic.end())
		cout << "Translate not found!\n";
	else
	{
		cout << "\tMeans:\n";
		for (string elem : dic[input])
			cout << elem << " ";
	}
	*/
	
}

