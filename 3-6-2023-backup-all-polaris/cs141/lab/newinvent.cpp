#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Record {
  string name;
  double cost;
  int markup;
  int count[3];
};

const string places[3] = {"counter", "shelf", "warehouse"};

bool read_file(vector <Record> &v);
void placement (vector <Record> &v);

int main()
{
  vector <Record> invent;
  char choice;

  if (read_file(invent) == false) {
    return 1;
  }
  cout << "You have " << invent.size() << endl;
  while (true)
    {
      cout << "(P)lacement e(X)it: ";
      cin >> choice;
      switch(choice) {
      case 'P':
      case 'p':
	placement(invent);
	break;
      case 'X':
      case 'x':
	return(0);
	break;
      default:
	cout << choice << " is not a chice\n";
      }
    }

  return 0;
}

void placement (vector <Record> &v)
{
  int which = -1;
  string input;

  cout << "Which? ";
  cin >> input;
  for (int i = 0; i < 3; i++) {
    if (input.substr(0,3) == places[i].substr(0,3)) which = i;
  }
  if (which == -1) {
    cout << "No match\n";
    return;
  }

  cout.setf(ios::left);
  cout.unsetf (ios::right);
  cout.width(30);
  cout << "Item";
  cout.setf(ios::right);
  cout.width(6);
  cout << places[which] << "\n";

  int j;
  for (j = 0; j < v.size(); j++) {
  cout.setf(ios::left);
  cout.unsetf (ios::right);
  cout.width(30);
  cout << v[j].name;
  cout.setf(ios::right);
  cout.width(6);
  cout << v[j].count[which] << endl;
  }
}

bool read_file(vector <Record> &v)
{
  Record r;
  ifstream infile;

  infile.open("inventory.txt");
  if (infile.fail()) {
    cout << "can't open file\n";
    return (false);
  }
  while (true) {
    getline (infile, r.name);
    cout << "Read " << r.name << endl;
    if (r.name == "END") {
      infile.close();
      return true;
    }
    else {
      infile >> r.cost >> r.markup;
      for (int i = 0; i < 3; i++) infile >> r.count[i];
      infile.get();

      v.push_back(r);
    }
  }
  return true;
}


