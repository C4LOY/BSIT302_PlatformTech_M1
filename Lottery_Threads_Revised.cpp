#include <atomic>
#include <iostream>
#include <atomic>
#include <thread>

using namespace std;
std::atomic<bool> ready1 (false);
std::atomic<bool> ready2 (false);
std::atomic<bool> ready3 (false);
std::atomic<int> counter1 (0);
std::atomic<int> counter2 (0);
std::atomic<int> counter3 (0);

void Lottery_1(int id)
{
	while (!ready1){
		this_thread::yield();
	}
	for (volatile int i = 0; i <= 55; i++){
		++ counter1;
		if (counter1 <= 6)
		cout << id + 1<< " ";
	}
}

void Lottery_2(int id)
{
	while (!ready2){
		this_thread::yield();
	}
	for (volatile int i = 0; i <= 55; i++){
		++ counter2;
		if (counter2 <= 6)
		cout << id + 1 << " ";
	}
}

void Lottery_3(int id)
{
	while (!ready3){
		this_thread::yield();
	}
	for (volatile int i = 0; i <= 55; i++){
		++ counter3;
		if (counter3 <= 6)
		cout << id + 1 << " ";
	}
}


int main()
{
	std::cout << "Lucky Winners for Todays Lotto are: " << '\n' << endl ;
	this_thread::sleep_for(chrono::seconds(1));
	
	thread threads1[55];
	thread threads2[55];
	thread threads3[55];
	
	for (int i = 0; i < 55; ++i) threads1[i] = thread(Lottery_1, i);
	cout << "1st Prize Lottery: ";
	ready1 = true;
	this_thread::sleep_for(chrono::seconds(1));
	std::cout << '\n';
	
	for (int i = 0; i < 55; ++i) threads2[i] = thread(Lottery_2, i);
	cout << "2nd Prize Lottery: ";
	ready2 = true;
	this_thread::sleep_for(chrono::seconds(1));
	std::cout << '\n';
	
	for (int i = 0; i < 55; ++i) threads3[i] = thread(Lottery_3, i);
	cout << "3rd Prize Lottery: ";
	ready3 = true;
	this_thread::sleep_for(chrono::seconds(1));
	std::cout << '\n' << endl ;
	
	for (int i = 0; i < 55; ++i){
		threads1[i].join();
		threads2[i].join();
		threads3[i].join();
	}
	
	std::cout << "Congratulations!" << endl ;
	
	return 0;
}
