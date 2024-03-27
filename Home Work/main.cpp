//
//  main.cpp
//  Home Work
//
//  Created by Дмитрий Сергеевич on 27.03.2024.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include <algorithm>
#include <random>


int main(int argc, const char * argv[]) {
    std::fstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    
    std::string line;
    std::queue<std::string> namesQueue;
    
    //!Счтитываем имена из файла и сохраняем их в очередь
    while(std::getline(inputFile, line)) {
        namesQueue.push(line);
    }
    //!Перемешиваем имена в очередь
    std::vector<std::string> shuffledNames;
    while (!namesQueue.empty()) {
        shuffledNames.push_back(namesQueue.front());
        namesQueue.pop();
    }
    std::shuffle(shuffledNames.begin(),shuffledNames.end(),std::mt19937(std::random_device()()));
    
    //!Выводим перемешанные имена на экран и записываем в файл
    for(const std::string& name : shuffledNames){
        std::cout << name << std::endl;
        outputFile << name << std::endl;
    }
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}

