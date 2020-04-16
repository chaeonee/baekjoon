#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	set<string> namecard;
	set<string>::reverse_iterator iter;
	for(int n = 0; n < N; n++){
		string name, stat;
		cin >> name >> stat;
		if(stat == "enter"){
			namecard.insert(name);
		}
		else if(stat == "leave"){
			namecard.erase(namecard.find(name));
		}
	}
	
	for(iter = namecard.rbegin(); iter != namecard.rend(); iter++){
		cout << *iter << '\n';
	}
	
	return 0;
}
