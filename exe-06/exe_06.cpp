#include <thread>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

void minha_funcao(int arg)
{
    printf("Hello %d\n", arg);
}

int main()
{
    vector<thread> threads;
    for(int i = 0; i < 5; i++){
        threads.emplace_back(minha_funcao, i);
    }

    for(auto& thread : threads){
        thread.join();
    }

    return 0;
}