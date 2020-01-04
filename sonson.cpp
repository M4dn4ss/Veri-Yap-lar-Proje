#include "windows.h"

#include "string"
#include <stdlib.h>
#include "fstream"
#include <iostream>
#include <vector>
#include <map>

#include <ctime>
#include <chrono>
#include <time.h>




#include <cctype>
using namespace std;


clock_t timer;
double duration;

int secim2;

class SpellCheck {
public:
	SpellCheck(string filename) {
		ifstream in(filename.c_str());
		string temp;
		while (in) {
			getline(in, temp);
			string word;
			while (temp.length() > 0) {
				if (nextWord(temp, word)) {
					map<string, int>::iterator itr = nWords.find(word);
					if (itr == nWords.end()) {
						nWords.insert(pair<string, int>(word, 1));
					}
					else {
						(*itr).second++;
					}
				}
			}
		}
		in.close();
	}

	string correct(string word) {
		if (nWords.find(word) != nWords.end()) return word;
		vector<string> edit1 = edits(word);
		map<int, string> candidates;
		for (int i = 0; i < edit1.size(); i++) {
			map<string, int>::iterator itr = nWords.find(edit1[i]);
			if (itr != nWords.end()) {
				pair<string, int> myPair = *itr;
				candidates.insert(pair<int, string>(myPair.second, myPair.first));
			}
		}
		if (candidates.size() > 0) {
			map<int, string>::iterator itr = candidates.begin();
			pair<int, string> max = *itr;
			itr++;
			while (itr != candidates.end())
				if ((*itr).first > max.first) max = *itr;
			return max.second;
		}
		candidates.clear();
		for (int i = 0; i < edit1.size(); i++) {
			vector<string> edit2 = edits(edit1[i]);
			for (int i = 0; i < edit2.size(); i++) {
				map<string, int>::iterator itr = nWords.find(edit2[i]);
				if (itr != nWords.end()) {
					pair<string, int> myPair = *itr;
					candidates.insert(pair<int, string>(myPair.second, myPair.first));
				}
			}
		}
		if (candidates.size() > 0) {
			map<int, string>::iterator itr = candidates.begin();
			pair<int, string> max = *itr;
			itr++;
			while (itr != candidates.end())
				if ((*itr).first > max.first) max = *itr;
			return max.second;
		}
		return word;
	}

private:
	vector<string> edits(string word) {
		vector<string> result;
		string temp;
		for (int i = 0; i < word.length(); i++) {
			temp = word.substr(0, i) + word.substr(i + 1);
			result.push_back(temp);
		}
		for (int i = 0; i < word.length() - 1; i++) {
			temp = word.substr(0, i) + word[i + 1] + word[i] + word.substr(i + 2);
			result.push_back(temp);
		}
		for (int i = 0; i < word.length(); i++) {
			for (char c = 'a'; c <= 'z'; c++) {
				temp = word.substr(0, i) + c + word.substr(i + 1);
				result.push_back(temp);
			}
		}
		for (int i = 0; i < word.length() + 1; i++) {
			for (char c = 'a'; c <= 'z'; c++) {
				temp = word.substr(0, i) + c + word.substr(i);
				result.push_back(temp);
			}
		}
		return result;
	}

	bool nextWord(string& sentence, string& word) {
		while (true) {
			int pos = sentence.find(" ");

			if (pos != string::npos) {
				word = sentence.substr(0, pos);

				sentence = sentence.substr(pos);
				while (sentence.length() > 0 && !isalpha(sentence[0])) {
					sentence = sentence.substr(1);
				}
				bool isWord = true;
				for (int i = 0; i < word.length(); i++) {
					if (isalpha(word[i])) {
						word[i] = tolower(word[i]);
					}
					else if (ispunct(word[i])) {
						word = word.substr(0, i) + word.substr(i + 1);
					}
					else isWord = false;
				}
				if (!isWord) {
					continue;
				}
				return true;
			}
			else {
				word = sentence;
				sentence = "";
				bool isWord = true;
				for (int i = 0; i < word.length(); i++) {
					if (isalpha(word[i])) word[i] = tolower(word[i]);
					else isWord = false;
				}
				if (!isWord) {
					return false;
				}
				return true;
			}
		}
	}

	map<string, int> nWords;
}; //spellcheck sonu, oneri


void readFiletxt()
{
	ifstream file1;
	file1.open("TXTset.txt");
	string word;
	char x;
	word.clear();

	while (!file1.eof())
	{
		std::ifstream::int_type x = file1.get();

		while (x != ' ' && x != std::ifstream::traits_type::eof())
		{
			word += static_cast<char>(x);
			x = file1.get();
		}
		//std::cout << word << '\n';
		word.clear();

	}

}

void readFileHtml()
{
	ifstream file1;
	file1.open("HTMLset.html");
	string word;
	char x;
	word.clear();

	while (!file1.eof())
	{
		std::ifstream::int_type x = file1.get();

		while (x != ' ' && x != std::ifstream::traits_type::eof())
		{
			word += static_cast<char>(x);
			x = file1.get();
		}
		//std::cout << word << '\n';
		word.clear();

	}
}

void readFileRTF()
{
	ifstream file1;
	file1.open("RTFset.rtf");
	string word;
	char x;
	word.clear();

	while (!file1.eof())
	{
		std::ifstream::int_type x = file1.get();

		while (x != ' ' && x != std::ifstream::traits_type::eof())
		{
			word += static_cast<char>(x);
			x = file1.get();
		}
		//std::cout << word << '\n';
		word.clear();

	}

}

void readFileDAT()
{
	ifstream file1;
	file1.open("DATset.dat");
	string word;
	char x;
	word.clear();

	while (!file1.eof())
	{
		std::ifstream::int_type x = file1.get();

		while (x != ' ' && x != std::ifstream::traits_type::eof())
		{
			word += static_cast<char>(x);
			x = file1.get();
		}
		//std::cout << word << '\n';
		word.clear();

	}

}



void satirsatirokumatxt(string x)
{
	int sayac1 = 0;
	ifstream input;
	size_t pos;
	string line;


	input.open("TXTset.txt");
	if (input.is_open())
	{
		while (getline(input, line))
		{
			pos = line.find(x);

			sayac1++;
			if (pos != string::npos) // string::npos is returned if string is not found
			{

				cout << "TXT dosyasinda" << " " << sayac1 << ". satirda aradiginiz kelime bulundu\n";
				ofstream myfile; // MY File adında yazdırma verisi oluşturduk
				myfile.open("sonuc.txt",fstream::app); // yazdir.txt adında bir metin belgesi olduğunu söylüyoruz ve bunu acmasını istiyoruz. (txt dosyası yok ise kendisi oluşturuyor.)
				myfile << "TXT dosyasında" " " << x << " " << "kelimesi bulunmaktadir"<<" "; // bu metnimizi txt yapıştırıyoruz , farklı uzantılarda bunu yapamaya biliriz.
				myfile.close();
				system("start C:\\Users\\ACER\\Documents\\Ornekler\\sonson\\sonson\\TXTset.txt");// Acılıp yazma işlemi yapılan txt dosyası burda close komutu ile kapatılıyor.


				//cout << "Dosyanin bulundugu klasoru acmak icin 2'ye basin." << endl;
				//cout << "Yeni bir aramak icin 1'e basin" << endl;

				/*if (secim2 == 2)
				{
					system("explorer C:\\Users\\ACER\\Pictures\\Camera Roll\\Proje\\Proje\\Proje\\TXTset.txt");
				}
				*/
				break;

			}

		}

		if (pos == string::npos)
		{
			cout << endl;
			cout << "TXT dosyasinda aradiginiz kelime bulunamadi." << endl;
			//cout << "Benzerlerini aramaya basliyorum.." << endl;
			cout << endl;


			/*string filename = "TXTset.txt";
			SpellCheck checker(filename);

			char choice = 'y';



			cout << "Bunu mu demek istediniz ? " << checker.correct(x) << "?" << endl;
			cout << endl;*/
		}



		//



	}

}

void satirsatirokumahtml(string x)
{
	timer = clock();


	int sayac1 = 0;
	ifstream input;
	size_t pos;
	string line;



	input.open("HTMLset.html");
	if (input.is_open())
	{
		while (getline(input, line))
		{
			pos = line.find(x);

			sayac1++;
			if (pos != string::npos) // string::npos is returned if string is not found
			{



				cout << "HTML dosyasinda" << " " << sayac1 << ". satirda aradiginiz kelime bulundu\n";
				ofstream myfile; // MY File adında yazdırma verisi oluşturduk
				myfile.open("sonuc.txt", fstream::app); // yazdir.txt adında bir metin belgesi olduğunu söylüyoruz ve bunu acmasını istiyoruz. (txt dosyası yok ise kendisi oluşturuyor.)
				myfile << "HTML dosyasında" " " << x << " " << "kelimesi bulunmaktadir"<<" "; // bu metnimizi txt yapıştırıyoruz , farklı uzantılarda bunu yapamaya biliriz.
				myfile.close();
				system("start C:\\Users\\ACER\\Documents\\Ornekler\\sonson\\sonson\\HTMLset.html");// Acılıp yazma işlemi yapılan txt dosyası burda close komutu ile kapatılıyor.
				/*cout << "Dosyanin bulundugu klasoru acmak icin 2'ye basin." << endl;
				cout << "Yeni bir aramak icin 1'e basin" << endl;
				cin >> secim2;
				if (secim2 == 2)
				{
				
				}
				*/

				break;

			}

		}

		if (pos == string::npos)
		{
			cout << endl;
			cout << "HTML dosyasinda aradiginiz kelime bulunamadi." << endl;
			//cout << "Benzerlerini aramaya basliyorum.." << endl;
			cout << endl;


			/*string filename = "HTMLset.html";
			SpellCheck checker(filename);

			char choice = 'y';



			cout << "Bunu mu demek istediniz ? " << checker.correct(x) << "?" << endl;
			cout << endl;*/
		}


	}
	/*duration = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
	cout << "sure : " << duration << endl;*/
}


void satirsatirokumaRTF(string x)
{
	int sayac1 = 0;
	ifstream input;
	size_t pos;
	string line;



	input.open("RTFset.rtf");
	if (input.is_open())
	{
		while (getline(input, line))
		{
			pos = line.find(x);

			sayac1++;
			if (pos != string::npos) // string::npos is returned if string is not found
			{




				cout << "RTF dosyasinda" << " " << sayac1 << ". satirda aradiginiz kelime bulundu\n";
				ofstream myfile; // MY File adında yazdırma verisi oluşturduk
				myfile.open("sonuc.txt", fstream::app); // yazdir.txt adında bir metin belgesi olduğunu söylüyoruz ve bunu acmasını istiyoruz. (txt dosyası yok ise kendisi oluşturuyor.)
				myfile << "RTF dosyasında" " " << x << " " << "kelimesi bulunmaktadir"<<" "; // bu metnimizi txt yapıştırıyoruz , farklı uzantılarda bunu yapamaya biliriz.
				myfile.close(); 
				system("start C:\\Users\\ACER\\Documents\\Ornekler\\sonson\\sonson\\RTFset.rtf");// Acılıp yazma işlemi yapılan txt dosyası burda close komutu ile kapatılıyor.
				/*cout << "Dosyanin bulundugu klasoru acmak icin 2'ye basin." << endl;
				cout << "Yeni bir aramak icin 1'e basin" << endl;
				cin >> secim2;
				if (secim2 == 2)
				{
					system("explorer C:\\Users\\ACER\\Pictures\\Camera Roll\\Proje\\Proje\\Proje\\RTFset.rtf");
				}
				*/

				break;

			}

		}

		if (pos == string::npos)
		{
			cout << endl;
			cout << "RTF dosyasinda aradiginiz kelime bulunamadi." << endl;
			//cout << "Benzerlerini aramaya basliyorum.." << endl;
			cout << endl;


			/*string filename = "RTFset.rtf";
			SpellCheck checker(filename);

			char choice = 'y';



			cout << "Bunu mu demek istediniz ? " << checker.correct(x) << "?" << endl;
			cout << endl;*/
		}


	}

}


void satirsatirokumaDAT(string x)
{
	int sayac1 = 0;
	ifstream input;
	size_t pos;
	string line;



	input.open("DATset.dat");
	if (input.is_open())
	{
		while (getline(input, line))
		{
			pos = line.find(x);

			sayac1++;
			if (pos != string::npos) // string::npos is returned if string is not found
			{




				cout << "DAT dosyasinda" << " " << sayac1 << ". satirda aradiginiz kelime bulundu\n";
				ofstream myfile; // MY File adında yazdırma verisi oluşturduk
				myfile.open("sonuc.txt", fstream::app); // yazdir.txt adında bir metin belgesi olduğunu söylüyoruz ve bunu acmasını istiyoruz. (txt dosyası yok ise kendisi oluşturuyor.)
				myfile << "DAT dosyasında" " " << x << " " << "kelimesi bulunmaktadir"<<" "; // bu metnimizi txt yapıştırıyoruz , farklı uzantılarda bunu yapamaya biliriz.
				myfile.close();
				system("start C:\\Users\\ACER\\Documents\\Ornekler\\sonson\\sonson\\DATSET.dat");// Acılıp yazma işlemi yapılan txt dosyası burda close komutu ile kapatılıyor.
				/*cout << "Dosyanin bulundugu klasoru acmak icin 2'ye basin." << endl;
				cout << "Yeni bir aramak icin 1'e basin" << endl;
				cin >> secim2;
				if (secim2 == 2)
				{
					system("explorer C:\\Users\\ACER\\Pictures\\Camera Roll\\Proje\\Proje\\Proje\\DATset.dat");
				}*/


				break;

			}

		}

		if (pos == string::npos)
		{
			cout << endl;
			cout << "DAT dosyasinda aradiginiz kelime bulunamadi." << endl;
			//cout << "Benzerlerini aramaya basliyorum.." << endl;
			cout << endl;


			/*string filename = "DATset.dat";
			SpellCheck checker(filename);

			char choice = 'y';



			cout << "Bunu mu demek istediniz ? " << checker.correct(x) << "?" << endl;
			cout << endl;*/
		}


	}

}





bool openIO(std::fstream& file, const char* filename) {
	file.open(filename); // Try to open for I/O
	if (!file) {
		file.clear();
		file.open(filename, std::ios::out); // Create using out
		if (!file)  return false;
		file.close();
		file.open(filename); // Open for I/O
		if (!file)  return false;
	}
	return true;
}



int main() {
burdan:
	for (;;) {

		system("cls");

		int secim;
		int secim1;
		char devam;
		string a;
		int secim3;

		cout << "--- DIZIN ICINDE KELIME ARAMA PROGRAMI ---" << endl << endl;
		cout << "Aramak istediginiz kelimeyi giriniz" << endl;

		cin >> a;

		timer = clock(); /* Zamanlayici*/

		//arama isleminin ne kadar surede oldugu hesaplaniyor.


		satirsatirokumatxt(a);
		readFiletxt();
		satirsatirokumahtml(a);
		readFileHtml();
		satirsatirokumaRTF(a);
		readFileRTF();
		satirsatirokumaDAT(a);
		readFileDAT();

		duration = (std::clock() - timer) / (double)CLOCKS_PER_SEC;

		ofstream myfile; // MY File adında yazdırma verisi oluşturduk
		myfile.open("sonuc.txt",fstream::app); // yazdir.txt adında bir metin belgesi olduğunu söylüyoruz ve bunu acmasını istiyoruz. (txt dosyası yok ise kendisi oluşturuyor.)
		myfile << "Arama islemi" << " " << duration << " " << "saniye surmustur.\n"; // bu metnimizi txt yapıştırıyoruz , farklı uzantılarda bunu yapamaya biliriz.
		myfile.close(); // Acılıp yazma işlemi yapılan txt dosyası burda close komutu ile kapatılıyor.

		cout << "Onerilen kelimeyi gormek icin 3'e basiniz." << endl;
		cin >> secim3;

		
		if(secim3==3)
		{
			cout << "Ariyorum.." << endl;
			string filename = "kral.txt";
			  SpellCheck checker(filename);

			  char choice = 'y';



			  cout << "Bunu mu demek istediniz ? " << checker.correct(a) << " " << endl;
			  cout << endl;
		}



		cout << "Yeni bir arama yapmak icin 1'e basiniz" << endl;
		cout << "Arama sonuclarinin bulundugu dosyayi acmak icin herhangi bir tusa basiniz." << endl;
		cin >> secim1;
		if (secim1 == 1)
		{
			goto burdan;
		}
		else

			system("start C:\\Users\\ACER\\Documents\\Ornekler\\sonson\\sonson\\sonuc.txt");
		break;

	}
}

//burdan:
//	for (;;) {
//
//		system("cls");
//		cout << "Welcome String search progress " << endl;
//		cout << "1) TXT" << endl;
//		cout << "2) HTML" << endl;
//		cout << "3) RTF" << endl;
//		cout << "4) DAT" << endl;
//		cin >> secim;
//
//		switch (secim)
//		{
//		case 1:
//			cout << "string gir" << endl;
//			cin >> a;
//
//			satirsatirokumatxt(a);
//			readFiletxt();
//
//
//
//			break;
//		case 2:
//
//			cout << "string gir" << endl;
//			cin >> a;
//
//
//			satirsatirokumahtml(a);
//			readFileHtml();
//
//			break;
//
//		case 3:
//
//			cout << "string gir" << endl;
//			cin >> a;
//
//
//			satirsatirokumaRTF(a);
//			readFileRTF();
//
//			break;
//
//		case 4:
//
//			cout << "string gir" << endl;
//			cin >> a;
//
//
//			satirsatirokumaDAT(a);
//			readFileDAT();
//
//			break;
//
//		}
//
//		cin >> secim1;
//		if (secim1 == 1)
//		{
//			goto burdan;
//		}
//		else
//
//			system("explorer C:\\Users\\ACER\\Documents\\Ornekler\\Project\\ConsoleApplication1\\gile.txt");
//
//
//		cin >> devam;
//		if (devam == 'e' || devam == 'E')
//		{
//
//			continue;
//
//		}
//		else
//			break;
//	/
