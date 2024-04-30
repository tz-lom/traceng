#include <chrono>
#include <iostream>

constexpr auto A = 100000;
constexpr auto B = 100000;
constexpr auto X = 10;

void b(int);



void a(int x)
{
	if(x>X) return;
	for(volatile int j=0; j<A; ++j)
	{
		(void)j;
	}
	b(x+1);
}

void b(int x)
{
	if(x>X) return;
	for(volatile int j=0; j<B; ++j)
	{
		(void)j;
	}
	a(x+1);
}


int main()
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	a(0);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
}
