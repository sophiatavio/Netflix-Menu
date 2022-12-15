#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void print_menu(){
  cout << "\n**********************************" << endl;
  cout << " Welcome to Netflix Shows Trivia!" << endl;
  cout << "**********************************" << endl;
  cout << "************ 1. Title   **********" << endl;
  cout << "************ 2. Year    **********" << endl;
  cout << "************ 3. Rating  **********" << endl;
  cout << "************ 4. Quit    **********" << endl;
  cout << "**********************************\n" << endl;
  cout << "Please enter you choice: ";
}

void initialize_data(vector<string>& title_list, vector<int>& year_list, vector<float>& rating_list){
  
  ifstream fin;
  string temp_s;
  int temp_i;
  float temp_f;
  
  fin.open("shows.txt");
  if(fin.is_open()){
    while(!fin.eof()){
      fin >> temp_s;
      title_list.push_back(temp_s);
      fin >> temp_i;
      year_list.push_back(temp_i);
      fin >> temp_f;
      rating_list.push_back(temp_f);
    }
    fin.close();
    cout << "\nInitialized " << title_list.size() << " shows..." << endl;
  } else {
    cout << "Error: File not found!" << endl;
  }
}

void print_title(vector<string> title_list){
  cout << "\nTitles of some of the best Netflix shows:\n" << endl;
  for(int i = 0; i < title_list.size(); i++){
    cout << "\t*" << title_list[i] << endl;
  }
  }

void print_year(vector<string> title_list, vector<int> year_list){
  cout << "\nYear that each show was produced:\n" << endl;
  for(int i = 0; i < title_list.size(); i++){
    cout << "\t*" << title_list[i];
    cout << " --- " << year_list[i] << "\n" << endl;
  }
  }

void print_rating(vector<string> title_list, vector<float> rating_list){
  cout << "\nRating of each show:\n" << endl;
  for(int i = 0; i < title_list.size(); i++){
    cout << "\t*" << title_list[i];
    cout << " --- " << rating_list[i] << "/10\n" << endl;
  }
  }

void save_data(vector<string> title_list, vector<int> year_list, vector<float> rating_list){
  ofstream fout;
  fout.open("saved_data.txt");
  if(fout.is_open()){
    for(int i = 0; i < title_list.size(); i++){
      fout << title_list[i] << " , " << year_list[i] << " , " << rating_list[i] << endl;
    }
    fout.close();
  } else {
    cout << "Error: File not found!" << endl;
    }
  }

int main() {
  int userChoice;
  
  vector<string> title_list;
  vector<int> year_list;
  vector<float> rating_list;

  cout << "\nHi! This project was made by Sophia Tavio Perez. I hope you enjoy it!\n" << endl;
  
  initialize_data(title_list, year_list, rating_list);
  
  do {
    print_menu();
    cin >> userChoice;
    switch(userChoice){
      case 1: 
        print_title(title_list);
        break;
      case 2:
        print_year(title_list, year_list);
        break;
      case 3:
        print_rating(title_list, rating_list);
        break;
      case 4:
        cout << "\nThanks for using Netflix Shows Trivia!\n" << endl;
        save_data(title_list, year_list, rating_list);
        break;
      default:
        cout << "\nInvalid choice, please try again!\n";
    }
  } while(userChoice != 4);

  return 0;
}