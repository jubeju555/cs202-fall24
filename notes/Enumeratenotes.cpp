// enumerate notes
#include <iostream>
#include <vector>

using namespace std;

void enumerate (vector <int> v, int pos){

    if (pos == 8){
        vector<bool> duplicate;
        duplicate.resize(10);

        if(duplicate[v[i]] == true)
        cout << "queen on the smae row!!" << endl;
        else{
            duplicate[v[i]] = true;
        }

        cout << v[i] << " ";
        cout << endl;
    }else {
        for(int i = 0; i < 8; i++){
                v[pos] = i;
       enumerate  

        }
    }
}

int main (){
vector <int> v
int pos = 0;

nums.resize(10);

enumerate (nums, pos);


}