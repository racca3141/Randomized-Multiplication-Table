// Randomize a 12 x 12 multiplication table.
// 
#include <iostream>
#include <string>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
//#include <sstream> // needed to convert string to int?

using namespace std;

string ms[144];
string mtemp; // holds temporary value
int x;
int rx;

// int rs; //random size

string xs, ys, ps; //product
int posx; //position of x
int pose; //position of =

int score;

int main()
{
    
    int pos = 0;
    for (int i = 1; i < 13; i++){
        for (int j = 1; j < 13; j++){
            ms[pos] = to_string(i) + "*" + to_string(j) + "=" + to_string(i * j);
            pos++;
        }
    }
    
    for (int c = 0; c < 144; c++){
       cout << "ms[" << c << "] = " << ms[c] << endl;
    }
    
    
    // initialize random seed: //
    srand (time(NULL));
    
    //random swap from the top
    for (int i = 143; i > 0; i = i - 1) { //i goes through all 144 elements starting from the top.
        rx = rand() % i; //initial is 0 to 142 for a total of 143 elements to be randomized.
        mtemp = ms[i];
        ms[i] = ms[rx];
        ms[rx] = mtemp;
    }
    
    //display final result
    cout << endl << endl;
    for (int c = 0; c < 144; c++){
       cout << "ms[" << c << "] = " << ms[c] << endl;
    }
    
    cout << endl << endl;
    
    // extract strings and convert them to integers.
    
    // Find position of '*' using find() for the first element
    for (int c = 0; c < 144; c++){
        int posx = ms[c].find("*");
        int pose = ms[c].find("=");
        // Copy substring after pos
        xs = ms[c].substr(0, posx);
        ys = ms[c].substr(posx + 1, pose - posx - 1);
        ps = ms[c].substr(pose + 1);
    
        //cout << endl;
        cout << xs << " x " << ys << " = " << stoi(xs) * stoi(ys) << endl; //verifies that conversion worked.
    }
    
    cout << endl << endl;
    
    // Test them.
    score = 0;
    for (int c = 0; c < 144; c++){
        int posx = ms[c].find("*");
        int pose = ms[c].find("=");
        // Copy substring after pos
        xs = ms[c].substr(0, posx);
        ys = ms[c].substr(posx + 1, pose - posx - 1);
        ps = ms[c].substr(pose + 1);
    
        //cout << endl;
        cout << xs << " x " << ys << " = " ;
        cin >> x;
        //cout << endl;
        if(x == stoi(xs) * stoi(ys)){
            score++;
            cout << "Correct! Your score is " << score << "/144 or " << score / 144.0 * 100 << " % of " << c + 1 << " questions." << endl << endl;
        }
        else{
            cout << "Wrong. " << xs << " x " << ys << " = " << stoi(xs) * stoi(ys) << endl << endl;
        
        }
    }
}
