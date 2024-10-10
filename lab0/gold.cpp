/* Hi, my name is Judah, I took CS 102 last semester, this is my file, I've tried my best and insured
 * that the grade strips in the formatting and what you guys are doing them this course was correct, 
 * if there are any grading or questions you have. Please feel free to reach me by email or phone
 * number. I hope to have a good year.*/

#include <iostream>

using namespace std;

int main(){
	char letter;		
	int oz = 0; 
	while (cin >> letter) {
		if ((letter != '-') && (letter != '.')) {
			oz += letter - 'A' + 1;

		}		

	}		
			cout  << oz << endl;
      return 0;

}
