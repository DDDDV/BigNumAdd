#include <iostream>
#include <vector>
#include <cassert>
/**
 * 大数自增 1
 * 给定一个 n 位数， 打印从 1 到 n 位数之间的所有数字。
 * @return
 */
void addOne(std::vector<int> &everyBit, int n){
    //检查是否有进位, 有进位向前传递
    if(everyBit[0] == 9){
        for(int i = 1; i < n; i++){
            everyBit[0] = 0;
            if(everyBit[i] == 9){
                everyBit[i] = 0;
            }else{
                everyBit[i] += 1;
                break;
            }
        }
    }else{
        everyBit[0] += 1;
    }
}
void printOne(const std::vector<int> &everyBit){
    int size = everyBit.size();
    int maxPosition = size - 1;
    while(everyBit[maxPosition] == 0){
        maxPosition--;
    }
    for(int i = maxPosition; i >= 0; i--){
        std::cout << everyBit[i];
    }
    std::cout << std::endl;
}

void process(int n){
    std::vector<int> everyBit(10, 0);
    int i = 0;
    while(true){
        addOne(everyBit, n);
        printOne(everyBit);
    }
}

int main() {
    int n;
    std::cin >> n;
    assert(n >= 0);
    process(n);
    return 0;
}
