#include <cstdio>
#include <string>
#include <cmath>

class LuckySum{
	private:
		long long answer;
	public:
		long long construct(std::string note);
		bool test_all_combinations(std::string remaining, std::string previous);
		bool is_lucky_sum(long long num);
		bool is_lucky_num(long long num);
};


int main(){
	std::string s = "???????";//very slow after more than 7 question marks
	LuckySum l;
	long long la = l.construct(s);
	printf("%lld\n", la);
} 


long long LuckySum::construct(std::string note){
	answer = -1;
	bool b = test_all_combinations(note, "");
	return answer;
}

bool LuckySum::test_all_combinations(std::string remaining, std::string previous){
	printf("%s: %s\n", previous.c_str(), remaining.c_str());
	std::size_t found = remaining.find('?');
	if(found != std::string::npos){
		int i = previous == "" ? 1 : 0;
		while(i <= 8){
			char c = '0' + i;
			std::string a = remaining.substr(found + 1, remaining.length() - found);
			std::string b = previous + remaining.substr(0, found);
			b += c;
			bool found_number = test_all_combinations(a, b);
			if(found_number)
				return found_number;
			//only test 0,1,4,8 -->there seems to be a pattern
			if(i == 0)
				i = 1;
			else if(i == 1)
				i = 4;
			else if(i == 4)
				i = 8;
			else
				break;
		}
		return false;
	}else{
		long long i;
		std::string concat = previous + remaining;
		sscanf(concat.c_str(), "%lld", &i);
		bool result = is_lucky_sum(i);
		if(result)
			answer = i;
		return result;
	}
}
bool LuckySum::is_lucky_sum(long long num){
 	if(num < 8)
		return false;
	long long first_num = 4;
	while(first_num <= num/2){
		if(is_lucky_num(first_num)){
			long long second_num = num - first_num;
			if(is_lucky_num(second_num))
				return true;
		}
		++first_num;
	}
	return false;
}
bool LuckySum::is_lucky_num(long long num){
	if(num < 4)
		return false;
	while(num != 0){
		int digit = num%10;
		if(digit != 4 && digit != 7)
			return false;
		num /= 10;//integer division-check next decimal digit
	}
	return true;
}
