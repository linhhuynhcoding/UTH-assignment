// cuoiky_c1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Website.h";
#include "WebBrowser.h";
#include <iostream>

using namespace std;

int main()
{
	Website* w1 = new Website("google");
	Website* w2 = new Website("facebook");
	Website* w3 = new Website("instagram");

	WebBrowser* browser = new WebBrowser();

	browser->goTo(w1);
	browser->goTo(w2);
	browser->goTo(w3);

	browser->history();
	
	browser->back_();
	browser->back_();
	browser->back_();

	browser->forward_();

	browser->thongke();

	browser->clearHistory();
	browser->history();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
