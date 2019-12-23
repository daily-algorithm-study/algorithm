#include <string>
#include <vector>
#include <string.h>

using namespace std;

int number[10];
bool prime[10000000];

bool can_make(int x)
{
    int num[10] = {0};
    int temp;
    
    while(x)
    {
        temp = x % 10;
        num[temp]++;
        
        if(num[temp] > number[temp]) return false;
        x /= 10;
    }
    
    return true;
}

int solution(string numbers) {
    int i, j;
    int answer = 0;
    
    for(i=0;i<numbers.size();i++)
    {
        number[numbers[i] - '0']++;
    }
    
    memset(prime,true,sizeof(prime));
    
    prime[0] = prime[1] = false;
    for(i=2;i*i<10000000;i++)
    {
        for(j = i*i; j < 10000000; j+= i)
        {
            prime[j] = false;
        }
    }
    
    for(i=2;i<=10000000;i++)
    {
        if(prime[i] && can_make(i)) answer++;
    }
    
    return answer;
}
