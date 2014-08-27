#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <utility>
#include <string>

using namespace std;

int i,j, cases, num_steps; 
string start,end, temp1, temp2;
int main(void) {
	
	scanf(" %d ", &cases);

	for (i = 0; i < cases ; i++) {
		map<string, string> steps;
		map<string, int> places;
		
		scanf( "%d ", &num_steps);
		for(j = 0; j < num_steps-1; j++) {
			cin >> temp1;
			cin >> temp2;
			steps[temp1] = temp2;
			
			if (places.find(temp1) == places.end())
				places[temp1] = 1;
			else
				places[temp1]++;
			
			if (places.find(temp2) == places.end())
				places[temp2] = 1;
			else
				places[temp2]++;
		}

		for (map<string, string>::iterator iter=steps.begin(); iter!=steps.end(); iter++) {
			if(places[iter->first] == 1) start = iter->first;
			if(places[iter->second] == 1) end = iter->second;
		}
		while(steps[start] != end) {
		 	cout << start << endl;
			start = steps[start];
		}
	}
}	
