#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void printVector(std::vector<T> v){							// simple output template function
	for(auto i:v){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template <typename ElementType, typename LessThanFunctor>
void insertion_sort(std::vector<ElementType> &v, LessThanFunctor less_than){
	int test = 0;
	for(int k = 1; k < v.size(); ++k){
		ElementType current = v[k];
		int j = k;
		while(j > 0){
			if(less_than(current, v[j - 1])){							// using the code to sort provided, not much explanation needed
				v[j] = v[j - 1];
			}else{
				break;
			}
			--j;
		}
		v[j] = current;
	}
}
template <typename T>
double std_sort_time(std::vector<T> v){
	std::random_shuffle(v.begin(), v.end());
	auto start = std::chrono::high_resolution_clock::now();
	insertion_sort(v, [](auto i, auto j){return i < j;});
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = stop - start;
	return diff.count();
}

int main(){
	std::vector<int> test1(19000);
	std::vector<int> test2(test1.size());
	std::vector<int> test3(test1.size());
	std::uniform_int_distribution<int> uniform_dist(1, test1.size());
	int j = test1.size();
	for(auto i = 0; i < test1.size(); ++i){
		test1[i] = i;
		test2[i] = j;
		test3[i] = i;
		--j;
	}
	std::random_shuffle(test3.begin(), test3.end());
	std::cout << "This vector was sorted the right way and took: " << std_sort_time(test1) << " seconds" << std::endl;
	std::cout << "This vector was sorted the wrong way and took: " << std_sort_time(test2) << " seconds" << std::endl;
	std::cout << "This vector was sorted randomly and took: " << std_sort_time(test3) << " seconds";
}