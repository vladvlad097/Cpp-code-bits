
#include <iostream>
#include <map>
#include<vector>
#include<set>
#include<iterator>

using namespace std;
int main()
{
	
	map< string, map< string, vector<int> > > student;

	student["Michael"]["Biology"].push_back(5);
	student["Michael"]["Biology"].push_back(8);
	student["Michael"]["History"].push_back(10);
	student["Michael"]["Math"].push_back(7);
	student["Michael"]["Chemistry"].push_back(10);


	student["Marcelo"]["Biology"].push_back(10);
	student["Marcelo"]["Biology"].push_back(9);
	student["Marcelo"]["History"].push_back(10);
	student["Marcelo"]["Math"].push_back(9);
	student["Marcelo"]["Chemistry"].push_back(10);

	student["Rudolf"]["Biology"].push_back(5);
	student["Rudolf"]["Biology"].push_back(6);
	student["Rudolf"]["History"].push_back(1);
	student["Rudolf"]["Math"].push_back(9);
	student["Rudolf"]["Science"].push_back(10);

	map< string, map< string, vector<int> > >::iterator it01;
	map< string, vector<int> >::iterator it02;
	vector<int>::iterator it03;


	for (it01 = student.begin(); it01 != student.end(); it01++)
	{
		cout << it01->first <<":"<< endl;

		for (it02 = it01->second.begin(); it02 != it01->second.end(); it02++)
		{
			cout << it02->first << ": ";

			for (it03 = it02->second.begin(); it03 != it02->second.end(); it03++)
			{
				cout << *it03 <<" ";
			}
			cout << endl;
		}
		cout << endl;
	}


}


