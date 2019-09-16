#include <iostream>
#include <ctime>
#include <thread>
#include <string>

using namespace std;

//This is all I can do sir :(
/* I'm trying my best to understand how threads work and how I can implement it 
to my code w/o using the rand() function 
but sadly and unfortunately this is all I can do and I know, as for now :((
Coding is not my forte and kinda dissapointed to myself :/ sorry po
*/

void Lottery_1(){
	time_t s;
	time (&s);
	srand(s);
	for (int iLotto = 1; iLotto < 7; ++iLotto){
		cout << rand()% 55+1 << " ";
	}
	cout <<"\n\n"<<endl;	
}

void Lottery_2(){
	time_t s;
	time (&s);
	srand(s);
	for (int iLotto = 1; iLotto < 7; ++iLotto){
		cout << (rand()% 55 + 1)+ 1<< " ";
	}
	cout <<"\n\n"<<endl;
}

void Lottery_3(){
	time_t s;
	time (&s);
	srand(s);
	for (int iLotto = 1; iLotto < 7; ++iLotto){
		cout << (rand()% 55 + 1) + 2<< " ";
	}
	cout <<"\n\n"<<endl;
}

int main()
{
	cout <<"Lottery numbers for today are as follows: \n\n";
	this_thread::sleep_for(chrono::seconds(1));
	std::thread t1(Lottery_1);
	this_thread::sleep_for(chrono::seconds(1));
	std::thread t2(Lottery_2);
	this_thread::sleep_for(chrono::seconds(1));
	std::thread t3(Lottery_3);
	this_thread::sleep_for(chrono::seconds(1));
	
	t1.join();
	t2.join();
	t3.join();
	
	cout <<"Congratulations";
	return(0);
}
